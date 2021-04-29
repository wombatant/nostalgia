/*
 * Copyright 2016 - 2021 gary@drinkingtea.net
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <GLFW/glfw3.h>

#include <nostalgia/core/config.hpp>
#include <nostalgia/core/core.hpp>
#include <nostalgia/core/gfx.hpp>
#include <nostalgia/core/input.hpp>

#include "core.hpp"

namespace nostalgia::core {

static event_handler g_eventHandler = nullptr;
static uint64_t g_wakeupTime;

void draw(Context *ctx);

ox::Error init(Context *ctx) noexcept {
	const auto id = new GlfwImplData;
	ctx->setWindowerData(id);
	using namespace std::chrono;
	id->startTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
	glfwInit();
	oxReturnError(initGfx(ctx));
	return OxError(0);
}

static void handleGlfwKeyEvent(GLFWwindow *window, int key, int, int action, int) {
	const auto ctx = ox::bit_cast<Context*>(glfwGetWindowUserPointer(window));
	const auto id = ctx->windowerData<GlfwImplData>();
	switch (action) {
		case GLFW_PRESS:
			switch (key) {
				case GLFW_KEY_Q:
					id->running = false;
					break;
			}
			break;
	}
}

ox::Error run(Context *ctx) noexcept {
	const auto id = ctx->windowerData<GlfwImplData>();
	id->running = true;
	// try adaptive vsync
	//if (SDL_GL_SetSwapInterval(config::SdlVsyncOption) < 0) {
	//	oxTrace("nostalgia::core::sdl", "Could not enable adaptive vsync, falling back on vsync");
	//	SDL_GL_SetSwapInterval(1); // fallback on normal vsync
	//}
	glfwSetKeyCallback(id->window, handleGlfwKeyEvent);
	while (id->running && !glfwWindowShouldClose(id->window)) {
		glfwPollEvents();
		const auto ticks = ticksMs(ctx);
		if (g_wakeupTime <= ticks && g_eventHandler) {
			auto sleepTime = g_eventHandler(ctx);
			if (sleepTime >= 0) {
				g_wakeupTime = ticks + static_cast<unsigned>(sleepTime);
			} else {
				g_wakeupTime = ~uint64_t(0);
			}
		}
		draw(ctx);
		glfwSwapBuffers(id->window);
	}
	return OxError(0);
}

void setEventHandler(Context *ctx, event_handler h) noexcept {
	const auto id = ctx->windowerData<GlfwImplData>();
	id->eventHandler = h;
}

uint64_t ticksMs(Context *ctx) noexcept {
	using namespace std::chrono;
	const auto id = ctx->windowerData<GlfwImplData>();
	const auto now = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
	return static_cast<uint64_t>(now - id->startTime);
}

bool buttonDown(Key) noexcept {
	return false;
}

}
