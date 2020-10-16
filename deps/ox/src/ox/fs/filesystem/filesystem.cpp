/*
 * Copyright 2015 - 2018 gtalent2@gmail.com
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "filesystem.hpp"

namespace ox {

ValErr<uint8_t*> FileSystem::read(FileAddress addr) {
	switch (addr.type()) {
		case FileAddressType::Inode:
			return read(addr.getInode().value);
		case FileAddressType::ConstPath:
		case FileAddressType::Path:
			return read(addr.getPath().value);
		default:
			return OxError(1);
	}
}

Error FileSystem::read(FileAddress addr, void *buffer, std::size_t size) {
	switch (addr.type()) {
		case FileAddressType::Inode:
			return read(addr.getInode().value, buffer, size);
		case FileAddressType::ConstPath:
		case FileAddressType::Path:
			return read(addr.getPath().value, buffer, size);
		default:
			return OxError(1);
	}
}

Error FileSystem::read(FileAddress addr, std::size_t readStart, std::size_t readSize, void *buffer, std::size_t *size) {
	switch (addr.type()) {
		case FileAddressType::Inode:
			return read(addr.getInode().value, readStart, readSize, buffer, size);
		case FileAddressType::ConstPath:
		case FileAddressType::Path:
			return read(addr.getPath().value, readStart, readSize, buffer, size);
		default:
			return OxError(1);
	}
}

Error FileSystem::remove(FileAddress addr, bool recursive) {
	switch (addr.type()) {
		case FileAddressType::Inode:
			return remove(addr.getInode().value, recursive);
		case FileAddressType::ConstPath:
		case FileAddressType::Path:
			return remove(addr.getPath().value, recursive);
		default:
			return OxError(1);
	}
}

ox::Error FileSystem::write(FileAddress addr, void *buffer, uint64_t size, uint8_t fileType) {
	switch (addr.type()) {
		case FileAddressType::Inode:
			return write(addr.getInode().value, buffer, size, fileType);
		case FileAddressType::ConstPath:
		case FileAddressType::Path:
			return write(addr.getPath().value, buffer, size, fileType);
		default:
			return OxError(1);
	}
}

ox::ValErr<FileStat> FileSystem::stat(FileAddress addr) {
	switch (addr.type()) {
		case FileAddressType::Inode:
			return stat(addr.getInode().value);
		case FileAddressType::ConstPath:
		case FileAddressType::Path:
			return stat(addr.getPath().value);
		default:
			return OxError(1);
	}
}

template class FileSystemTemplate<FileStore16, Directory16>;
template class FileSystemTemplate<FileStore32, Directory32>;

}
