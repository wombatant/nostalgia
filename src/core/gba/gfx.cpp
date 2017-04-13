/*
 * Copyright 2016-2017 gtalent2@gmail.com
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <ox/fs/filesystem.hpp>
#include <ox/std/std.hpp>
#include "addresses.hpp"
#include "media.hpp"
#include "gba.hpp"
#include "dirt.h"

namespace nostalgia {
namespace core {

using namespace ox::fs;

#define TILE_ADDR  ((CharBlock*) 0x06000000)
#define TILE8_ADDR ((CharBlock8*) 0x06000000)

ox::Error initGfx() {
	/* Sprite Mode ----\ */
	/*             ---\| */
	/* Background 0 -\|| */
	/* Objects -----\||| */
	/*              |||| */
	REG_DISPCNT = 0x1100;

	TILE_ADDR[0][1] = *(Tile*) dirtTiles;

	for (auto i = 0; i < (dirtPalLen / 2); i++) {
		(&MEM_PALLETE_BG)[i] = dirtPal[i];
	}

	auto fs = (FileStore32*) findMedia();
	REG_BG0CNT = (28 << 8) | 1;
	MEM_BG_MAP[28][106] = 1;
	MEM_BG_MAP[28][107] = 1;
	if (fs) {
		char out[6];
		FileStore32::FsSize_t outSize = 0;
		fs->read(3, out, &outSize);
		if (outSize == 5) {
			MEM_BG_MAP[28][138] = 1;
			MEM_BG_MAP[28][139] = 1;
		}
	}

	return 0;
}

}
}
