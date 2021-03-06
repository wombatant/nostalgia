/*
 * Copyright 2016 - 2021 gary@drinkingtea.net
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <nostalgia/core/core.hpp>

#include "app.hpp"

static ox::Error run(int argc, const char **argv) noexcept {
	ox::trace::init();
	if (argc < 2) {
		oxErr("Please provide path to project directory or OxFS file.");
		return OxError(1);
	}
	const auto path = argv[1];
	oxRequire(fs, nostalgia::core::loadRomFs(path));
	return run(fs.get());
}

int main(int argc, const char **argv) {
	const auto err = run(argc, argv);
	oxAssert(err, "Something went wrong...");
	return static_cast<int>(err);
}
