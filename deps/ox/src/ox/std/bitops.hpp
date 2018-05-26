/*
 * Copyright 2015 - 2018 gtalent2@gmail.com
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once

namespace ox {

template<typename T>
inline constexpr T rotateLeft(T i, int shift) {
	constexpr auto bits = sizeof(i) * 8;
	return (i << shift) | (i >> (bits - shift));
}

template<typename T>
constexpr T onMask(int bits) {
	T out = 0;
	for (auto i = 0; i < bits; i++) {
		out |= 1 << i;
	}
	return out;
}

}
