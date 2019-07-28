/*
 * Copyright 2016 - 2018 gtalent2@gmail.com
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "../gfx.hpp"

namespace nostalgia::core {

ox::Error initGfx(Context*) {
	return OxError(1);
}

ox::Error initConsole(Context*) {
	return OxError(1);
}

ox::Error loadTileSheet(Context*, InodeId_t) {
	return OxError(1);
}

void puts(Context*, int, const char*) {
}

void setTile(Context*, int, int, int, uint8_t) {
}

}
