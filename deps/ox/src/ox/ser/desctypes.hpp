/*
 * Copyright 2015 - 2018 gtalent2@gmail.com
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <ox/std/error.hpp>
#include <ox/std/hashmap.hpp>
#include <ox/std/string.hpp>
#include <ox/std/vector.hpp>

namespace ox {

using String = BString<100>;
using FieldName = String;
using TypeName = String;

enum class PrimitiveType: uint8_t {
	UnsignedInteger = 0,
	SignedInteger = 1,
	Bool = 2,
	// Float = 3, reserved, but not implemented
	String = 4,
	Struct = 5,
};

struct DescriptorField {
	// order of fields matters

	// only serialize type name if type has already been serialized
	const struct DescriptorType *type = nullptr;
	FieldName fieldName;
	int subscriptLevels = 0;

	// do not serialize the following
	TypeName typeName; // gives reference to type for lookup if type is null
	bool ownsType = false;

	constexpr DescriptorField() noexcept = default;

	/**
	 * Allow for explicit copying.
	 */
	constexpr explicit DescriptorField(const DescriptorField &other) noexcept {
		type = other.type;
		fieldName = other.fieldName;
		subscriptLevels = other.subscriptLevels;
		typeName = other.typeName;
		ownsType = false; // is copy, only owns type if move
	}

	constexpr DescriptorField(const DescriptorType *type, const FieldName &fieldName, int subscriptLevels, const TypeName &typeName, bool ownsType) noexcept {
		this->type = type;
		this->fieldName = fieldName;
		this->subscriptLevels = subscriptLevels;
		this->typeName = typeName;
		this->ownsType = ownsType;
	}

	constexpr DescriptorField(DescriptorField &&other) noexcept {
		type = other.type;
		fieldName = other.fieldName;
		subscriptLevels = other.subscriptLevels;
		typeName = other.typeName;
		ownsType = other.ownsType;

		other.type = {};
		other.fieldName = "";
		other.subscriptLevels = {};
		other.typeName = "";
		other.ownsType = {};
	}

	~DescriptorField();

	constexpr const DescriptorField &operator=(DescriptorField &&other) noexcept {
		type = other.type;
		fieldName = other.fieldName;
		subscriptLevels = other.subscriptLevels;
		typeName = other.typeName;
		ownsType = other.ownsType;

		other.type = {};
		other.fieldName = "";
		other.subscriptLevels = {};
		other.typeName = "";
		other.ownsType = {};

		return *this;
	}

};

using FieldList = Vector<DescriptorField>;

struct DescriptorType {
	TypeName typeName;
	PrimitiveType primitiveType;
	// fieldList only applies to structs
	FieldList fieldList;
	// - number of bytes for integer and float types
	// - number of fields for structs and lists
	int64_t length = 0;

	DescriptorType() = default;

	DescriptorType(TypeName tn, PrimitiveType t, int b): typeName(tn), primitiveType(t), length(b) {
	}

	DescriptorType(TypeName tn, PrimitiveType t, FieldList fl): typeName(tn), primitiveType(t), fieldList(fl) {
	}
};


template<typename T>
Error ioOp(T *io, DescriptorType *type) {
	Error err = 0;
	io->setTypeInfo("ox::DescriptorType", 4);
	err |= io->op("typeName", &type->typeName);
	err |= io->op("primitiveType", &type->primitiveType);
	err |= io->op("fieldList", &type->fieldList);
	err |= io->op("length", &type->length);
	return err;
}

template<typename T>
Error ioOpWrite(T *io, DescriptorField *field) {
	Error err = 0;
	io->setTypeInfo("ox::DescriptorField", 4);
	if (field->ownsType) {
		err |= io->op("typeName", "");
		err |= io->op("type", field->type);
	} else {
		err |= io->op("typeName", &field->type->typeName);
		err |= io->op("type", static_cast<decltype(field->type)>(nullptr));
	}
	err |= io->op("fieldName", &field->fieldName);
	// defaultValue is unused now, but leave placeholder for backwards compatibility
	const int DefaultValue = 0;
	err |= io->op("defaultValue", &DefaultValue);
	return err;
}

template<typename T>
Error ioOpRead(T *io, DescriptorField *field) {
	Error err = 0;
	auto &typeStore = io->typeStore();
	io->setTypeInfo("ox::DescriptorField", 4);
	err |= io->op("typeName", &field->typeName);
	if (field->typeName == "") {
		field->ownsType = true;
		if (field->type == nullptr) {
			field->type = new DescriptorType;
		}
		err |= io->op("type", field->type);
		typeStore[field->type->typeName] = field->type;
	} else {
		// should be empty, so discard
		DescriptorType t;
		err |= io->op("type", &t);
		field->type = typeStore[field->typeName];
	}
	err |= io->op("fieldName", &field->fieldName);
	// defaultValue is unused now, but placeholder for backwards compatibility
	err |= io->op("defaultValue", nullptr);
	return err;
}

using TypeStore = ox::HashMap<String, DescriptorType*>;

}
