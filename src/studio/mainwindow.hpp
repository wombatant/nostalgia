/*
 * Copyright 2016-2017 gtalent2@gmail.com
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#pragma once

#include <ox/std/types.hpp>
#include <QModelIndex>
#include <QMainWindow>
#include <QPoint>
#include <QString>

namespace nostalgia {
namespace studio {

struct NostalgiaStudioProfile {
	QString app_name;
};

template<typename T>
int ioOp(T *io, NostalgiaStudioProfile *obj) {
	ox::Error err = 0;
	err |= io->op("app_name", &obj->app_name);
	return err;
}


class MainWindow: public QMainWindow {
	Q_OBJECT
	public:
		static const QString EditorSettings;
		static const QString AppTitle;

	private:
		QString m_projectPath;

	public:
		MainWindow(NostalgiaStudioProfile config, QWidget *parent = 0);
		virtual ~MainWindow();

		void openProject(QString);

	private:
		void setupDockWidgets();
		int readSettings(QString path);
		int writeSettings(QString path);

	public slots:
};

}
}
