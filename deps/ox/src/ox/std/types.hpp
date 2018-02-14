/*
 * Copyright 2015 - 2018 gtalent2@gmail.com
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once

typedef signed char        int8_t;
typedef unsigned char      uint8_t;
typedef short              int16_t;
typedef unsigned short     uint16_t;
typedef int                int32_t;
typedef unsigned int       uint32_t;
typedef unsigned           uint_t;
#if defined(_WIN32) || defined(__APPLE__) || defined(__arm__) || defined(__ppc__)
typedef long long          int64_t;
typedef unsigned long long uint64_t;
typedef __INTMAX_TYPE__    intmax_t;
typedef __UINTMAX_TYPE__   uintmax_t;
#else
typedef long               int64_t;
typedef unsigned long      uint64_t;
typedef int64_t            intmax_t;
typedef uint64_t           uintmax_t;
#endif

static_assert(sizeof(int8_t)  == 1, "int8_t is wrong size");
static_assert(sizeof(int16_t) == 2, "int16_t is wrong size");
static_assert(sizeof(int32_t) == 4, "int32_t is wrong size");
static_assert(sizeof(int64_t) == 8, "int64_t is wrong size");

static_assert(sizeof(uint8_t)  == 1, "uint8_t is wrong size");
static_assert(sizeof(uint16_t) == 2, "uint16_t is wrong size");
static_assert(sizeof(uint32_t) == 4, "uint32_t is wrong size");
static_assert(sizeof(uint64_t) == 8, "uint64_t is wrong size");

namespace ox {

typedef uint32_t Error;

}

#if defined(_LP64) || defined(__ppc64__) || defined(__aarch64__)
typedef unsigned long size_t;
#elif defined(_WIN64)
typedef uint64_t size_t;
#elif defined(_LP32) || defined(__ppc__) || defined(_WIN32) || defined(__arm__)
typedef uint32_t size_t;
#else
#error size_t undefined
#endif
