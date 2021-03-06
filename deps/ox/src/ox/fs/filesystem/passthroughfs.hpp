/*
 * Copyright 2015 - 2021 gary@drinkingtea.net
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once

#if __has_include(<filesystem>) && defined(OX_USE_STDLIB)

#include <filesystem>
#include <string>

#include <ox/std/bit.hpp>
#include "filesystem.hpp"

#define OX_HAS_PASSTHROUGHFS

namespace ox {

constexpr auto HasPassThroughFS = true;

/**
 *
 */
class PassThroughFS: public FileSystem {
	private:
		std::filesystem::path m_path;

	public:
		explicit PassThroughFS(const char *dirPath);

		~PassThroughFS() override;

		[[nodiscard]]
		String basePath();

		Error mkdir(const char *path, bool recursive = false) noexcept override;

		Error move(const char *src, const char *dest) noexcept override;

		Error read(const char *path, void *buffer, std::size_t buffSize) noexcept override;

		Result<const char*> directAccess(const char*) noexcept override;

		Error read(uint64_t inode, void *buffer, std::size_t size) noexcept override;

		Error read(uint64_t inode, std::size_t readStart, std::size_t readSize, void *buffer, std::size_t *size) noexcept override;

		Result<const char*> directAccess(uint64_t) noexcept override;

		Result<Vector<String>> ls(const char *dir) noexcept override;

		template<typename F>
		Error ls(const char *dir, F cb) noexcept;

		Error remove(const char *path, bool recursive = false) noexcept override;

		Error resize(uint64_t size, void *buffer = nullptr) noexcept override;

		Error write(const char *path, const void *buffer, uint64_t size, FileType fileType = FileType::NormalFile) noexcept override;

		Error write(uint64_t inode, const void *buffer, uint64_t size, FileType fileType = FileType::NormalFile) noexcept override;

		Result<FileStat> stat(uint64_t inode) noexcept override;

		Result<FileStat> stat(const char *path) noexcept override;

		uint64_t spaceNeeded(uint64_t size) noexcept override;

		Result<uint64_t> available() noexcept override;

		Result<uint64_t> size() const noexcept override;

		char *buff() noexcept override;

		Error walk(Error(*cb)(uint8_t, uint64_t, uint64_t)) noexcept override;

		[[nodiscard]]
		bool valid() const noexcept override;

	private:
		/**
		 * Strips the leading slashes from a string.
		 */
		static const char *stripSlash(const char *path) noexcept;

};

template<typename F>
Error PassThroughFS::ls(const char *dir, F cb) noexcept {
	std::error_code ec;
	const auto di = std::filesystem::directory_iterator(m_path / stripSlash(dir), ec);
	oxReturnError(OxError(ec.value(), "PassThroughFS: ls failed"));
	for (auto &p : di) {
		const auto u8p = p.path().filename().u8string();
		oxReturnError(cb(bit_cast<const char*>(u8p.c_str()), 0));
	}
	return OxError(0);
}

}

#else

namespace ox {

constexpr auto HasPassThroughFS = false;

}

#endif
