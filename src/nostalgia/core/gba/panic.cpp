/*
 * Copyright 2016 - 2021 gary@drinkingtea.net
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <ox/std/memops.hpp>

#include <nostalgia/core/core.hpp>
#include <nostalgia/core/gfx.hpp>

#include "addresses.hpp"
#include "bios.hpp"
#include "gfx.hpp"

namespace ox {

using namespace nostalgia::core;

void panic(const char*, int, const char *msg, const ox::Error &err) noexcept {
	oxIgnoreError(initGfx(nullptr));
	oxIgnoreError(initConsole(nullptr));
	// enable only BG 0
	REG_DISPCTL = DispCtl_Bg0;
	clearTileLayer(nullptr, 0);
	ox::BString<23> serr = "Error code: ";
	serr += static_cast<int64_t>(err);
	puts(nullptr, 32 + 1,  1, "SADNESS...");
	puts(nullptr, 32 + 1,  4, "UNEXPECTED STATE:");
	puts(nullptr, 32 + 2,  6, msg);
	if (err) {
		puts(nullptr, 32 + 2,  8, serr.c_str());
	}
	puts(nullptr, 32 + 1, 15, "PLEASE RESTART THE SYSTEM");
	// disable all interrupt handling and IntrWait on no interrupts
	REG_IE = 0;
	nostalgia_core_intrwait(0, 0);
}

}
