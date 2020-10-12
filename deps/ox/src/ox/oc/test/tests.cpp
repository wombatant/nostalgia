/*
 * Copyright 2015 - 2020 gtalent2@gmail.com
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#undef NDEBUG

#include <iostream>
#include <map>
#include <string>

#include <ox/model/model.hpp>
#include <ox/oc/oc.hpp>
#include <ox/std/std.hpp>

union TestUnion {
	static constexpr auto TypeName = "TestUnion";
	static constexpr auto Fields = 3;
	bool Bool;
	uint32_t Int = 5;
	char String[32];
};

struct TestStructNest {
	bool Bool = false;
	uint32_t Int = 0;
	ox::BString<32> String = "";
};

struct TestStruct {
	bool Bool = false;
	int32_t Int = 0;
	int32_t Int1 = 0;
	int32_t Int2 = 0;
	int32_t Int3 = 0;
	int32_t Int4 = 0;
	int32_t Int5 = 0;
	int32_t Int6 = 0;
	int32_t Int7 = 0;
	int32_t Int8 = 0;
	TestUnion Union;
	char *CString = nullptr;
	ox::BString<32> String = "";
	uint32_t List[4] = {0, 0, 0, 0};
	ox::HashMap<ox::String, int> Map;
	TestStructNest EmptyStruct;
	TestStructNest Struct;

	~TestStruct() {
		delete[] CString;
	}

};

template<typename T>
ox::Error model(T *io, TestUnion *obj) {
	io->template setTypeInfo<TestUnion>();
	oxReturnError(io->field("Bool", &obj->Bool));
	oxReturnError(io->field("Int", &obj->Int));
	oxReturnError(io->field("String", ox::SerStr(obj->String)));
	return OxError(0);
}

template<typename T>
ox::Error model(T *io, TestStructNest *obj) {
	io->setTypeInfo("TestStructNest", 3);
	oxReturnError(io->field("Bool", &obj->Bool));
	oxReturnError(io->field("Int", &obj->Int));
	oxReturnError(io->field("String", &obj->String));
	return OxError(0);
}

template<typename T>
ox::Error model(T *io, TestStruct *obj) {
	io->setTypeInfo("TestStruct", 17);
	oxReturnError(io->field("Bool", &obj->Bool));
	oxReturnError(io->field("Int", &obj->Int));
	oxReturnError(io->field("Int1", &obj->Int1));
	oxReturnError(io->field("Int2", &obj->Int2));
	oxReturnError(io->field("Int3", &obj->Int3));
	oxReturnError(io->field("Int4", &obj->Int4));
	oxReturnError(io->field("Int5", &obj->Int5));
	oxReturnError(io->field("Int6", &obj->Int6));
	oxReturnError(io->field("Int7", &obj->Int7));
	oxReturnError(io->field("Int8", &obj->Int8));
	oxReturnError(io->field("Union", ox::UnionView{&obj->Union, 1}));
	oxReturnError(io->field("CString", ox::SerStr(&obj->CString)));
	oxReturnError(io->field("String", &obj->String));
	oxReturnError(io->field("List", obj->List, 4));
	oxReturnError(io->field("Map", &obj->Map));
	oxReturnError(io->field("EmptyStruct", &obj->EmptyStruct));
	oxReturnError(io->field("Struct", &obj->Struct));
	return OxError(0);
}

std::map<std::string, ox::Error(*)()> tests = {
	{
		{
			"OrganicClawWriter",
			[] {
				// This test doesn't confirm much, but it does show that the writer
				// doesn't segfault
				TestStruct ts;
				return ox::writeOC(&ts).error;
			}
		},
		{
			"OrganicClawReader",
			[] {
				TestStruct testIn;
				testIn.Bool = true;
				testIn.Int = 42;
				testIn.Union.Int = 52;
				testIn.String = "Test String 1";
				testIn.CString = new char[ox_strlen("c-string") + 1];
				ox_strcpy(testIn.CString, "c-string");
				testIn.List[0] = 1;
				testIn.List[1] = 2;
				testIn.List[2] = 3;
				testIn.List[3] = 4;
				testIn.Map["asdf"] = 93;
				testIn.Map["aoeu"] = 94;
				testIn.Struct.Bool = false;
				testIn.Struct.Int = 300;
				testIn.Struct.String = "Test String 2";

				auto [oc, writeErr] = ox::writeOC(&testIn);
				oxAssert(writeErr, "writeOC failed");
				std::cout << oc.data() << '\n';
				auto [testOut, readErr] = ox::readOC<TestStruct>(oc.data());
				oxAssert(readErr, "readOC failed");

				oxAssert(testIn.Bool               == testOut->Bool, "Bool value mismatch");
				oxAssert(testIn.Int                == testOut->Int, "Int value mismatch");
				oxAssert(testIn.Int1               == testOut->Int1, "Int1 value mismatch");
				oxAssert(testIn.Int2               == testOut->Int2, "Int2 value mismatch");
				oxAssert(testIn.Int3               == testOut->Int3, "Int3 value mismatch");
				oxAssert(testIn.Int4               == testOut->Int4, "Int4 value mismatch");
				oxAssert(testIn.Int5               == testOut->Int5, "Int5 value mismatch");
				oxAssert(testIn.Int6               == testOut->Int6, "Int6 value mismatch");
				oxAssert(testIn.Int7               == testOut->Int7, "Int7 value mismatch");
				oxAssert(testIn.Int8               == testOut->Int8, "Int8 value mismatch");
				oxAssert(ox_strcmp(testIn.CString, testOut->CString) == 0, "CString value mismatch");
				oxAssert(testIn.Union.Int          == testOut->Union.Int, "Union.Int value mismatch");
				oxAssert(testIn.String             == testOut->String, "String value mismatch");
				oxAssert(testIn.List[0]            == testOut->List[0], "List[0] value mismatch");
				oxAssert(testIn.List[1]            == testOut->List[1], "List[1] value mismatch");
				oxAssert(testIn.List[2]            == testOut->List[2], "List[2] value mismatch");
				oxAssert(testIn.List[3]            == testOut->List[3], "List[3] value mismatch");
				oxAssert(testIn.Map["asdf"]        == testOut->Map["asdf"], "Map[\"asdf\"] value mismatch");
				oxAssert(testIn.Map["aoeu"]        == testOut->Map["aoeu"], "Map[\"aoeu\"] value mismatch");
				oxAssert(testIn.EmptyStruct.Bool   == testOut->EmptyStruct.Bool, "EmptyStruct.Bool value mismatch");
				oxAssert(testIn.EmptyStruct.Int    == testOut->EmptyStruct.Int, "EmptyStruct.Int value mismatch");
				oxAssert(testIn.EmptyStruct.String == testOut->EmptyStruct.String, "EmptyStruct.String value mismatch");
				oxAssert(testIn.Struct.Int         == testOut->Struct.Int, "Struct.Int value mismatch");
				oxAssert(testIn.Struct.String      == testOut->Struct.String, "Struct.String value mismatch");
				oxAssert(testIn.Struct.Bool        == testOut->Struct.Bool, "Struct.Bool value mismatch");

				return OxError(0);
			}
		},
		{
			"OrganicClawDef",
			[] {
				TestStruct testIn, testOut;

				testIn.Bool = true;
				testIn.Int = 42;
				testIn.String = "Test String 1";
				testIn.List[0] = 1;
				testIn.List[1] = 2;
				testIn.List[2] = 3;
				testIn.List[3] = 4;
				testIn.Struct.Bool = false;
				testIn.Struct.Int = 300;
				testIn.Struct.String = "Test String 2";

				auto [oc, ocErr] = ox::writeOC(&testIn);
				oxAssert(ocErr, "Data generation failed");
				auto type = ox::buildTypeDef(&testIn);
				oxAssert(type.error, "Descriptor write failed");
				oxReturnError(ox::walkModel<ox::OrganicClawReader>(type.value, ox::bit_cast<uint8_t*>(oc.data()), oc.size(),
					[](const ox::Vector<ox::FieldName>&, const ox::Vector<ox::TypeName>&, const ox::DescriptorField &f, ox::OrganicClawReader *rdr) -> ox::Error {
						//std::cout << f.fieldName.c_str() << '\n';
						auto fieldName = f.fieldName.c_str();
						switch (f.type->primitiveType) {
							case ox::PrimitiveType::UnsignedInteger:
								std::cout << fieldName << ":\tuint" << f.type->length * 8 << "_t:\t";
								switch (f.type->length) {
									case 1: {
										uint8_t i = {};
										oxAssert(rdr->field(fieldName, &i), "Walking model failed.");
										std::cout << i;
										break;
									}
									case 2: {
										uint16_t i = {};
										oxAssert(rdr->field(fieldName, &i), "Walking model failed.");
										std::cout << i;
										break;
									}
									case 4: {
										uint32_t i = {};
										oxAssert(rdr->field(fieldName, &i), "Walking model failed.");
										std::cout << i;
										break;
									}
									case 8: {
										uint64_t i = {};
										oxAssert(rdr->field(fieldName, &i), "Walking model failed.");
										std::cout << i;
										break;
									}
								}
								std::cout << '\n';
								break;
							case ox::PrimitiveType::SignedInteger:
								std::cout << fieldName << ":\tint" << f.type->length * 8 << "_t:\t";
								switch (f.type->length) {
									case 1: {
										int8_t i = {};
										oxAssert(rdr->field(fieldName, &i), "Walking model failed.");
										std::cout << i;
										break;
									}
									case 2: {
										int16_t i = {};
										oxAssert(rdr->field(fieldName, &i), "Walking model failed.");
										std::cout << i;
										break;
									}
									case 4: {
										int32_t i = {};
										oxAssert(rdr->field(fieldName, &i), "Walking model failed.");
										std::cout << i;
										break;
									}
									case 8: {
										int64_t i = {};
										oxAssert(rdr->field(fieldName, &i), "Walking model failed.");
										std::cout << i;
										break;
									}
								}
								std::cout << '\n';
								break;
							case ox::PrimitiveType::Bool: {
								bool i = {};
								oxAssert(rdr->field(fieldName, &i), "Walking model failed.");
								std::cout << fieldName << ":\t" << "bool:\t" << (i ? "true" : "false") << '\n';
								break;
							}
							case ox::PrimitiveType::String: {
								ox::Vector<char> v(rdr->stringLength(fieldName) + 1);
								//std::cout << rdr->stringLength() << '\n';
								oxAssert(rdr->field(fieldName, ox::SerStr(v.data(), v.size())), "Walking model failed.");
								std::cout << fieldName << ":\t" << "string: " << v.data() << '\n';
								break;
							}
							case ox::PrimitiveType::Struct:
								break;
							case ox::PrimitiveType::Union:
								break;
						}
						return OxError(0);
					}
				));
				delete type.value;

				return OxError(0);
			}
		},
	}
};

int main(int argc, const char **args) {
	int retval = -1;
	if (argc > 0) {
		auto testName = args[1];
		if (tests.find(testName) != tests.end()) {
			retval = tests[testName]();
		}
	}
	return retval;
}
