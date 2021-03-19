/*
 * Copyright 2016 - 2021 gary@drinkingtea.net
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <ox/claw/claw.hpp>
#include <nostalgia/core/gfx.hpp>
#include <nostalgia/core/gfx.hpp>

#include "gfx.hpp"

namespace nostalgia::core {

static ox::Result<ox::Vector<char>> readFile(Context *ctx, const ox::FileAddress &file) {
	oxRequire(stat, ctx->rom->stat(file));
	ox::Vector<char> buff(stat.size);
	oxReturnError(ctx->rom->read(file, buff.data(), buff.size()));
	return buff;
}

template<typename T>
ox::Result<T> readObj(Context *ctx, const ox::FileAddress &file) {
	oxRequire(buff, readFile(ctx, file));
	T t;
	oxReturnError(ox::readClaw(buff.data(), buff.size(), &t));
	return t;
}

ox::Error initConsole(Context *ctx) {
	constexpr auto TilesheetAddr = "/TileSheets/Charset.ng";
	setBgStatus(ctx, 0b0001);
	return loadBgTileSheet(ctx, 0, TilesheetAddr);
}

ox::Error loadSpriteTileSheet(Context*,
                              int,
                              ox::FileAddress,
                              ox::FileAddress) {
	return OxError(0);
}

ox::Error loadBgTileSheet(Context *ctx,
                          int section,
                          ox::FileAddress tilesheetPath,
                          ox::FileAddress palettePath) {
	oxRequire(tilesheet, readObj<NostalgiaGraphic>(ctx, tilesheetPath));
	if (!palettePath) {
		palettePath = tilesheet.defaultPalette;
	}
	oxRequire(palette, readObj<NostalgiaPalette>(ctx, palettePath));
	const unsigned bytesPerTile = tilesheet.bpp == 8 ? 64 : 32;
	const auto tiles = tilesheet.pixels.size() / bytesPerTile;
	constexpr int width = 8;
	const int height = 8 * tiles;
	ox::Vector<uint32_t> pixels;
	if (bytesPerTile == 64) { // 8 BPP
		pixels.resize(tilesheet.pixels.size());
		for (std::size_t i = 0; i < tilesheet.pixels.size(); ++i) {
			pixels[i] = toColor32(palette.colors[tilesheet.pixels[i]]);
		}
	} else { // 4 BPP
		pixels.resize(tilesheet.pixels.size() * 2);
		for (std::size_t i = 0; i < tilesheet.pixels.size(); ++i) {
			pixels[i * 2 + 0] = toColor32(palette.colors[tilesheet.pixels[i] & 0xF]);
			pixels[i * 2 + 1] = toColor32(palette.colors[tilesheet.pixels[i] >> 4]);
		}
	}
	return renderer::loadBgTexture(ctx, section, pixels.data(), width, height);
}

void puts(Context *ctx, int column, int row, const char *str) {
	for (int i = 0; str[i]; ++i) {
		setTile(ctx, 0, column + i, row, static_cast<uint8_t>(charMap[static_cast<int>(str[i])]));
	}
}

}
