/*
 * Copyright 2015 - 2018 gtalent2@gmail.com
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#if defined(OX_USE_STDLIB)
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#endif

#include <ox/mc/write.hpp>

#include "trace.hpp"

namespace ox::trace {

#if defined(OX_USE_STDLIB)
static const auto OxPrintTrace = std::getenv("OXTRACE");
#else
static const auto OxPrintTrace = false;
#endif

namespace gdblogger {

void captureLogFunc([[maybe_unused]] const char *file, [[maybe_unused]] int line,
                    [[maybe_unused]] const char *ch, [[maybe_unused]] const char *msg) {
}

void logFunc(const char *file, int line, const char *ch, const char *msg) {
	captureLogFunc(file, line, ch, msg);
}

}

OutStream::OutStream(const char *file, int line, const char *ch, const char *msg) {
	m_msg.file = file;
	m_msg.line = line;
	m_msg.ch = ch;
	m_msg.msg = msg;
}

OutStream::~OutStream() {
	gdblogger::logFunc(m_msg.file.c_str(), m_msg.line, m_msg.ch.c_str(), m_msg.msg.c_str());
#if defined(OX_USE_STDLIB)
	if (OxPrintTrace) {
		auto pipe = fopen(OxPrintTrace, "a");
		if (pipe) {
			constexpr std::size_t buffLen = 1024;
			std::size_t size = 0;
			uint8_t buff[buffLen];
			writeMC(buff, buffLen, &m_msg, &size);

			//write(pipe, buff, size);
			fclose(pipe);
		}
	}
#endif
}


StdOutStream::StdOutStream(const char *file, int line, const char *ch, const char *msg) {
	m_msg.file = file;
	m_msg.line = line;
	m_msg.ch = ch;
	m_msg.msg = msg;
}

StdOutStream::~StdOutStream() {
	gdblogger::logFunc(m_msg.file.c_str(), m_msg.line, m_msg.ch.c_str(), m_msg.msg.c_str());
#if defined(OX_USE_STDLIB)
	if (OxPrintTrace) {
		std::cout << std::setw(53) << std::left << m_msg.ch.c_str() << '|';
		std::cout << std::setw(65) << std::left << m_msg.msg.c_str() << '|';
		std::cout << " " << m_msg.file.c_str() << ':' << m_msg.line << "\n";
	}
#endif
}


void logError(const char *file, int line, Error err) {
	if (err) {
		ErrorInfo ei(err);
		TraceStream trc(file, line, "ox::error");
		trc <<  "Error:" << ei.errCode;
		if (ei.file != nullptr) {
			trc << "(" << reinterpret_cast<const char*>(ei.file) << ":" << ei.line << ")";
		}
	}
}

}