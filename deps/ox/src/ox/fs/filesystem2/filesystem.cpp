/*
 * Copyright 2015 - 2018 gtalent2@gmail.com
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "filesystem.hpp"

namespace ox::fs {

template class Directory<uint16_t>;
template class Directory<uint32_t>;

template class FileSystemTemplate<uint16_t>;
template class FileSystemTemplate<uint32_t>;

}