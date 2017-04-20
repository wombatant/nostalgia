/*
 * Copyright 2016-2017 gtalent2@gmail.com
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <functional>
#include <QDir>
#include <QGridLayout>
#include <QLabel>
#include <QListWidget>
#include <QMap>
#include <QVector>
#include <QWizard>

namespace nostalgia {
namespace studio {

class WizardSelect: public QWizardPage {
	Q_OBJECT

	private:
		QMap<QString, std::function<QWizardPage*()>> m_options;
		QListWidget *m_listWidget = nullptr;
		bool m_complete = false;
		int m_nextId = -1;

	public:
		WizardSelect();

		void addOption(QString name, std::function<QWizardPage*()> makePage);

		void initializePage() override;

		bool isComplete() const override;

		int nextId() const override;

	private slots:
		void itemSelected(int row);
};

class WizardFormPage: public QWizardPage {
	Q_OBJECT
	private:
		struct Field {
			QString defaultValue = "";
			QString value = "";
			QLineEdit *lineEdit = nullptr;
			std::function<int(QString)> validator;
		};
		QLabel *m_errorMsg = nullptr;
		QGridLayout *m_layout = nullptr;
		QVector<QLayout*> m_subLayout;
		QMap<QString, Field> m_fields;
		int m_currentLine = 0;
		int m_validFields = 0;

	public:
		WizardFormPage();

		~WizardFormPage();

		void initializePage() override;

		bool validatePage() override;

		void addLineEdit(QString displayName, QString fieldName, QString defaultVal = "");

		void addDirBrowse(QString displayName, QString fieldName, QString defaultVal = QDir::homePath());

		void showValidationError(QString msg);
};


class Wizard: public QWizard {
	Q_OBJECT

	public:
		Wizard(QWidget *parent = 0);
};

}
}
