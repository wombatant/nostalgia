/*
 * Copyright 2015 - 2018 gtalent2@gmail.com
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once

#include "types.hpp"

#ifdef DEBUG
#define OxError(x) ox::_error(__FILE__, __LINE__, x)
#else
#define OxError(x) x
#endif

#define oxReturnError(x) if (const auto err = x) return err

namespace ox {

using Error = uint64_t;

constexpr Error errCode(Error err) {
	return (err >> 58) & onMask<Error>(5);
}

struct ErrorInfo {
	const char *file = nullptr;
	int line = -1;
	Error errCode = 0;

	ErrorInfo() = default;

	ErrorInfo(Error err) {
		this->file = reinterpret_cast<const char*>(err & onMask<Error>(48));
		this->line = static_cast<int>((err >> 48) & onMask<Error>(11));
		this->errCode = ox::errCode(err);
	}
};

static constexpr Error _errorTags(Error line, Error errCode) {
	line &= onMask<Error>(11);
	line <<= 48;
	errCode &= onMask<Error>(5);
	errCode <<= 59;
	return errCode | line;
}

static constexpr Error _error(const char *file, int line, Error errCode) {
	return errCode ? reinterpret_cast<uint64_t>(file) | _errorTags(line, errCode) : 0;
}

template<typename T>
struct ValErr {
	T value;
	Error error;

	inline constexpr ValErr() = default;

	inline constexpr ValErr(T value, Error error = 0): value(value), error(error) {
	}

	inline constexpr operator const T&() const {
		return value;
	}

	inline constexpr operator T&() {
		return value;
	}

	inline constexpr bool ok() const {
		return error == 0;
	}

};

}

