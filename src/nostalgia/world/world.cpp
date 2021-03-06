/*
 * Copyright 2016 - 2021 gary@drinkingtea.net
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "world.hpp"

namespace nostalgia::world {

using namespace common;
using namespace core;

ox::Error Zone::init(Context *ctx, Bounds bnds, ox::FileAddress tileSheet, ox::FileAddress palette) {
	const auto size = static_cast<std::size_t>(bnds.width * bnds.height);
	m_tiles = new Tile[size];
	m_bounds = bnds;
	return core::loadBgTileSheet(ctx, 0, tileSheet, palette);
}

Zone::~Zone() {
	delete[] m_tiles;
}

void Zone::draw(Context *ctx) {
	for (int x = 0; x < m_bounds.width; x++) {
		for (int y = 0; y < m_bounds.height; y++) {
			auto t = tile(x, y);
			core::setTile(ctx, 0, x * 2, y * 2, t->bgTile);
			core::setTile(ctx, 0, x * 2 + 1, y * 2, t->bgTile + 1);
			core::setTile(ctx, 0, x * 2 + 1, y * 2 + 1, t->bgTile + 2);
			core::setTile(ctx, 0, x * 2, y * 2 + 1, t->bgTile + 3);
		}
	}
}

std::size_t Zone::size() {
	return sizeof(Zone) + static_cast<std::size_t>(m_bounds.width * m_bounds.height) * sizeof(Tile);
}

Tile *Zone::tile(int x, int y) {
	return &m_tiles[x * m_bounds.width + y];
}

void Zone::setTile(int x, int y, Tile *td) {
	m_tiles[x * m_bounds.width + y] = *td;
}

}
