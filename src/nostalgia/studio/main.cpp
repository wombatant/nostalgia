/*
 * Copyright 2016 - 2021 gary@drinkingtea.net
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <QApplication>
#include <QDebug>
#include <QQuickWindow>
#include <ox/clargs/clargs.hpp>
#include <ox/std/trace.hpp>
#include <qdark/theme.hpp>
#include "mainwindow.hpp"

using namespace nostalgia::studio;

int main(int argc, char **args) {
	ox::trace::init();
	// get profile path from command args
	ox::ClArgs clargs(argc, const_cast<const char**>(args));
	QString argProfilePath = clargs.getString("profile", ":/profiles/nostalgia-studio.json").c_str();
	QApplication app(argc, args);
	// load theme
	if constexpr(ox::defines::OS != ox::defines::OS::Darwin) {
		qdark::load(&app);
	}
	// force QtQuick to use OpenGL (https://doc.qt.io/qt-6/quick-changes-qt6.html#changes-to-qquickwidget)
#if QT_VERSION >= 0x060000
	QQuickWindow::setGraphicsApi(QSGRendererInterface::OpenGLRhi);
#endif
	// open window
	try {
		MainWindow w(argProfilePath);
		app.setApplicationName(w.windowTitle());
		w.show();
		QObject::connect(&app, &QApplication::aboutToQuit, &w, &MainWindow::onExit);
		return app.exec();
	} catch (const ox::Error &err) {
		oxPanic(err, "Unhandled ox::Error");
	}
}
