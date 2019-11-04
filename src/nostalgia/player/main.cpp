/*
 * Copyright 2016 - 2019 gtalent2@gmail.com
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <ox/fs/fs.hpp>
#include <ox/std/units.hpp>
#include <nostalgia/world/world.hpp>

using namespace nostalgia::common;
using namespace nostalgia::core;
using namespace nostalgia::world;

ox::Error run(ox::FileSystem *fs) {
	Context ctx;
	ctx.rom = fs;
	oxReturnError(init(&ctx));
	//Zone zone;
	//oxReturnError(zone.init(&ctx, Bounds{0, 0, 40, 40}, "/TileSheets/Charset.ng", "/Palettes/Charset.npal"));
	//zone.draw(&ctx);
	oxReturnError(initConsole(&ctx));
	puts(&ctx, 9 * 32 + 10, "DOPENESS!!!");
	oxReturnError(run());
	oxReturnError(shutdownGfx());
	return OxError(0);
}

#ifndef OX_USE_STDLIB

int main() {
	auto rom = loadRom();
	if (!rom) {
		return 1;
	}
	ox::FileSystem32 fs(ox::FileStore32(rom, 32 * ox::units::MB));
	run(&fs);
	return 0;
}

#else

int main(int argc, const char **argv) {
	if (argc > 1) {
		ox::PassThroughFS fs(argv[1]);
		auto err = run(&fs);
		oxAssert(err, "Something went wrong...");
		return err;
	}
	return 2;
}

#endif
