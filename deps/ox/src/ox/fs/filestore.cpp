/*
 * Copyright 2015 - 2018 gtalent2@gmail.com
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "filestore.hpp"

namespace ox {

template class FileStore<FileStoreHeader<uint16_t, uint16_t>>;
template class FileStore<FileStoreHeader<uint32_t, uint32_t>>;
template class FileStore<FileStoreHeader<uint64_t, uint64_t>>;

}