# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'dw_displays.ui'
#
# Created by: PyQt5 UI code generator 5.14.1
#
# WARNING! All changes made in this file will be lost!


from qtpy import QtCore, QtGui, QtWidgets


class Ui_DockWidget(object):
    def setupUi(self, DockWidget):
        DockWidget.setObjectName("DockWidget")
        DockWidget.resize(592, 557)
        self.dockWidgetContents = QtWidgets.QWidget()
        self.dockWidgetContents.setObjectName("dockWidgetContents")
        self.gridLayout = QtWidgets.QGridLayout(self.dockWidgetContents)
        self.gridLayout.setObjectName("gridLayout")
        self.textBrowser = QtWidgets.QTextBrowser(self.dockWidgetContents)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.textBrowser.sizePolicy().hasHeightForWidth())
        self.textBrowser.setSizePolicy(sizePolicy)
        self.textBrowser.setMinimumSize(QtCore.QSize(0, 0))
        self.textBrowser.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.textBrowser.setObjectName("textBrowser")
        self.gridLayout.addWidget(self.textBrowser, 2, 1, 1, 1)
        self.label_77 = QtWidgets.QLabel(self.dockWidgetContents)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_77.sizePolicy().hasHeightForWidth())
        self.label_77.setSizePolicy(sizePolicy)
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.label_77.setFont(font)
        self.label_77.setObjectName("label_77")
        self.gridLayout.addWidget(self.label_77, 0, 1, 1, 1)
        self.label_78 = QtWidgets.QLabel(self.dockWidgetContents)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_78.sizePolicy().hasHeightForWidth())
        self.label_78.setSizePolicy(sizePolicy)
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.label_78.setFont(font)
        self.label_78.setObjectName("label_78")
        self.gridLayout.addWidget(self.label_78, 0, 2, 1, 1)
        self.label_3 = QtWidgets.QLabel(self.dockWidgetContents)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_3.sizePolicy().hasHeightForWidth())
        self.label_3.setSizePolicy(sizePolicy)
        self.label_3.setMinimumSize(QtCore.QSize(0, 0))
        self.label_3.setMaximumSize(QtCore.QSize(16777215, 16777215))
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.label_3.setFont(font)
        self.label_3.setObjectName("label_3")
        self.gridLayout.addWidget(self.label_3, 1, 0, 1, 1)
        self.label_79 = QtWidgets.QLabel(self.dockWidgetContents)
        self.label_79.setEnabled(False)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_79.sizePolicy().hasHeightForWidth())
        self.label_79.setSizePolicy(sizePolicy)
        self.label_79.setObjectName("label_79")
        self.gridLayout.addWidget(self.label_79, 1, 2, 1, 1)
        self.label_4 = QtWidgets.QLabel(self.dockWidgetContents)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_4.sizePolicy().hasHeightForWidth())
        self.label_4.setSizePolicy(sizePolicy)
        self.label_4.setMinimumSize(QtCore.QSize(0, 0))
        self.label_4.setMaximumSize(QtCore.QSize(16777215, 16777215))
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.label_4.setFont(font)
        self.label_4.setObjectName("label_4")
        self.gridLayout.addWidget(self.label_4, 2, 0, 1, 1)
        self.textBrowserDis = QtWidgets.QTextBrowser(self.dockWidgetContents)
        self.textBrowserDis.setEnabled(False)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.textBrowserDis.sizePolicy().hasHeightForWidth())
        self.textBrowserDis.setSizePolicy(sizePolicy)
        self.textBrowserDis.setObjectName("textBrowserDis")
        self.gridLayout.addWidget(self.textBrowserDis, 2, 2, 1, 1)
        self.label_5 = QtWidgets.QLabel(self.dockWidgetContents)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_5.sizePolicy().hasHeightForWidth())
        self.label_5.setSizePolicy(sizePolicy)
        self.label_5.setMinimumSize(QtCore.QSize(0, 0))
        self.label_5.setMaximumSize(QtCore.QSize(16777215, 16777215))
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.label_5.setFont(font)
        self.label_5.setObjectName("label_5")
        self.gridLayout.addWidget(self.label_5, 3, 0, 1, 1)
        self.graphicsView = QtWidgets.QGraphicsView(self.dockWidgetContents)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.graphicsView.sizePolicy().hasHeightForWidth())
        self.graphicsView.setSizePolicy(sizePolicy)
        self.graphicsView.setMinimumSize(QtCore.QSize(0, 0))
        self.graphicsView.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.graphicsView.setObjectName("graphicsView")
        self.gridLayout.addWidget(self.graphicsView, 3, 1, 1, 1)
        self.graphicsViewDis = QtWidgets.QGraphicsView(self.dockWidgetContents)
        self.graphicsViewDis.setEnabled(False)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.graphicsViewDis.sizePolicy().hasHeightForWidth())
        self.graphicsViewDis.setSizePolicy(sizePolicy)
        self.graphicsViewDis.setObjectName("graphicsViewDis")
        self.gridLayout.addWidget(self.graphicsViewDis, 3, 2, 1, 1)
        self.label_6 = QtWidgets.QLabel(self.dockWidgetContents)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_6.sizePolicy().hasHeightForWidth())
        self.label_6.setSizePolicy(sizePolicy)
        self.label_6.setMinimumSize(QtCore.QSize(0, 0))
        self.label_6.setMaximumSize(QtCore.QSize(16777215, 16777215))
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.label_6.setFont(font)
        self.label_6.setObjectName("label_6")
        self.gridLayout.addWidget(self.label_6, 4, 0, 1, 1)
        self.calendarWidget = QtWidgets.QCalendarWidget(self.dockWidgetContents)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.calendarWidget.sizePolicy().hasHeightForWidth())
        self.calendarWidget.setSizePolicy(sizePolicy)
        self.calendarWidget.setMinimumSize(QtCore.QSize(0, 0))
        self.calendarWidget.setMaximumSize(QtCore.QSize(350, 16777215))
        font = QtGui.QFont()
        font.setFamily("Lato")
        font.setPointSize(8)
        font.setItalic(False)
        self.calendarWidget.setFont(font)
        self.calendarWidget.setObjectName("calendarWidget")
        self.gridLayout.addWidget(self.calendarWidget, 4, 1, 1, 1)
        self.lcdNumberDis = QtWidgets.QLCDNumber(self.dockWidgetContents)
        self.lcdNumberDis.setEnabled(False)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.lcdNumberDis.sizePolicy().hasHeightForWidth())
        self.lcdNumberDis.setSizePolicy(sizePolicy)
        self.lcdNumberDis.setObjectName("lcdNumberDis")
        self.gridLayout.addWidget(self.lcdNumberDis, 5, 2, 1, 1)
        self.label_7 = QtWidgets.QLabel(self.dockWidgetContents)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_7.sizePolicy().hasHeightForWidth())
        self.label_7.setSizePolicy(sizePolicy)
        self.label_7.setMinimumSize(QtCore.QSize(0, 0))
        self.label_7.setMaximumSize(QtCore.QSize(16777215, 16777215))
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.label_7.setFont(font)
        self.label_7.setObjectName("label_7")
        self.gridLayout.addWidget(self.label_7, 5, 0, 1, 1)
        self.lcdNumber = QtWidgets.QLCDNumber(self.dockWidgetContents)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.lcdNumber.sizePolicy().hasHeightForWidth())
        self.lcdNumber.setSizePolicy(sizePolicy)
        self.lcdNumber.setMinimumSize(QtCore.QSize(0, 0))
        self.lcdNumber.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.lcdNumber.setObjectName("lcdNumber")
        self.gridLayout.addWidget(self.lcdNumber, 5, 1, 1, 1)
        self.label_8 = QtWidgets.QLabel(self.dockWidgetContents)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_8.sizePolicy().hasHeightForWidth())
        self.label_8.setSizePolicy(sizePolicy)
        self.label_8.setMinimumSize(QtCore.QSize(0, 0))
        self.label_8.setMaximumSize(QtCore.QSize(16777215, 16777215))
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.label_8.setFont(font)
        self.label_8.setObjectName("label_8")
        self.gridLayout.addWidget(self.label_8, 6, 0, 1, 1)
        self.progressBar = QtWidgets.QProgressBar(self.dockWidgetContents)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.progressBar.sizePolicy().hasHeightForWidth())
        self.progressBar.setSizePolicy(sizePolicy)
        self.progressBar.setMinimumSize(QtCore.QSize(0, 0))
        self.progressBar.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.progressBar.setProperty("value", 24)
        self.progressBar.setObjectName("progressBar")
        self.gridLayout.addWidget(self.progressBar, 6, 1, 1, 1)
        self.progressBarDis = QtWidgets.QProgressBar(self.dockWidgetContents)
        self.progressBarDis.setEnabled(False)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.progressBarDis.sizePolicy().hasHeightForWidth())
        self.progressBarDis.setSizePolicy(sizePolicy)
        self.progressBarDis.setProperty("value", 24)
        self.progressBarDis.setObjectName("progressBarDis")
        self.gridLayout.addWidget(self.progressBarDis, 6, 2, 1, 1)
        self.label_9 = QtWidgets.QLabel(self.dockWidgetContents)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_9.sizePolicy().hasHeightForWidth())
        self.label_9.setSizePolicy(sizePolicy)
        self.label_9.setMinimumSize(QtCore.QSize(0, 0))
        self.label_9.setMaximumSize(QtCore.QSize(16777215, 16777215))
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.label_9.setFont(font)
        self.label_9.setObjectName("label_9")
        self.gridLayout.addWidget(self.label_9, 7, 0, 1, 1)
        self.lineH = QtWidgets.QFrame(self.dockWidgetContents)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.lineH.sizePolicy().hasHeightForWidth())
        self.lineH.setSizePolicy(sizePolicy)
        self.lineH.setMinimumSize(QtCore.QSize(0, 0))
        self.lineH.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.lineH.setFrameShape(QtWidgets.QFrame.HLine)
        self.lineH.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.lineH.setObjectName("lineH")
        self.gridLayout.addWidget(self.lineH, 7, 1, 1, 1)
        self.lineHDis = QtWidgets.QFrame(self.dockWidgetContents)
        self.lineHDis.setEnabled(False)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.lineHDis.sizePolicy().hasHeightForWidth())
        self.lineHDis.setSizePolicy(sizePolicy)
        self.lineHDis.setFrameShape(QtWidgets.QFrame.HLine)
        self.lineHDis.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.lineHDis.setObjectName("lineHDis")
        self.gridLayout.addWidget(self.lineHDis, 7, 2, 1, 1)
        self.label_10 = QtWidgets.QLabel(self.dockWidgetContents)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_10.sizePolicy().hasHeightForWidth())
        self.label_10.setSizePolicy(sizePolicy)
        self.label_10.setMinimumSize(QtCore.QSize(0, 0))
        self.label_10.setMaximumSize(QtCore.QSize(16777215, 16777215))
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.label_10.setFont(font)
        self.label_10.setObjectName("label_10")
        self.gridLayout.addWidget(self.label_10, 8, 0, 1, 1)
        self.lineV = QtWidgets.QFrame(self.dockWidgetContents)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.lineV.sizePolicy().hasHeightForWidth())
        self.lineV.setSizePolicy(sizePolicy)
        self.lineV.setMinimumSize(QtCore.QSize(0, 50))
        self.lineV.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.lineV.setFrameShape(QtWidgets.QFrame.VLine)
        self.lineV.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.lineV.setObjectName("lineV")
        self.gridLayout.addWidget(self.lineV, 8, 1, 1, 1)
        self.lineVDis = QtWidgets.QFrame(self.dockWidgetContents)
        self.lineVDis.setEnabled(False)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.lineVDis.sizePolicy().hasHeightForWidth())
        self.lineVDis.setSizePolicy(sizePolicy)
        self.lineVDis.setMinimumSize(QtCore.QSize(0, 50))
        self.lineVDis.setFrameShape(QtWidgets.QFrame.VLine)
        self.lineVDis.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.lineVDis.setObjectName("lineVDis")
        self.gridLayout.addWidget(self.lineVDis, 8, 2, 1, 1)
        spacerItem = QtWidgets.QSpacerItem(20, 40, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        self.gridLayout.addItem(spacerItem, 9, 0, 1, 1)
        self.label_37 = QtWidgets.QLabel(self.dockWidgetContents)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_37.sizePolicy().hasHeightForWidth())
        self.label_37.setSizePolicy(sizePolicy)
        self.label_37.setAlignment(QtCore.Qt.AlignCenter)
        self.label_37.setObjectName("label_37")
        self.gridLayout.addWidget(self.label_37, 10, 0, 1, 3)
        self.label_2 = QtWidgets.QLabel(self.dockWidgetContents)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_2.sizePolicy().hasHeightForWidth())
        self.label_2.setSizePolicy(sizePolicy)
        self.label_2.setMinimumSize(QtCore.QSize(0, 0))
        self.label_2.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.label_2.setObjectName("label_2")
        self.gridLayout.addWidget(self.label_2, 1, 1, 1, 1)
        self.calendarWidgetDis = QtWidgets.QCalendarWidget(self.dockWidgetContents)
        self.calendarWidgetDis.setEnabled(False)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.calendarWidgetDis.sizePolicy().hasHeightForWidth())
        self.calendarWidgetDis.setSizePolicy(sizePolicy)
        self.calendarWidgetDis.setMaximumSize(QtCore.QSize(350, 16777215))
        font = QtGui.QFont()
        font.setFamily("Lato")
        font.setPointSize(8)
        font.setItalic(False)
        self.calendarWidgetDis.setFont(font)
        self.calendarWidgetDis.setObjectName("calendarWidgetDis")
        self.gridLayout.addWidget(self.calendarWidgetDis, 4, 2, 1, 1)
        DockWidget.setWidget(self.dockWidgetContents)

        self.retranslateUi(DockWidget)
        self.progressBar.valueChanged['int'].connect(self.progressBarDis.setValue)
        self.calendarWidget.currentPageChanged['int','int'].connect(self.calendarWidgetDis.setCurrentPage)
        self.calendarWidget.clicked['QDate'].connect(self.calendarWidgetDis.setSelectedDate)
        QtCore.QMetaObject.connectSlotsByName(DockWidget)

    def retranslateUi(self, DockWidget):
        _translate = QtCore.QCoreApplication.translate
        DockWidget.setWindowTitle(_translate("DockWidget", "Displays"))
        self.textBrowser.setToolTip(_translate("DockWidget", "This is a tool tip"))
        self.textBrowser.setStatusTip(_translate("DockWidget", "This is a status tip"))
        self.textBrowser.setWhatsThis(_translate("DockWidget", "This is \"what is this\""))
        self.textBrowser.setHtml(_translate("DockWidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'Ubuntu\'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:\'Cantarell\';\">Testing</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:\'Cantarell\';\"><br /></p></body></html>"))
        self.label_77.setText(_translate("DockWidget", "Enabled"))
        self.label_78.setText(_translate("DockWidget", "Disabled"))
        self.label_3.setToolTip(_translate("DockWidget", "This is a tool tip"))
        self.label_3.setStatusTip(_translate("DockWidget", "This is a status tip"))
        self.label_3.setWhatsThis(_translate("DockWidget", "This is \"what is this\""))
        self.label_3.setText(_translate("DockWidget", "Label"))
        self.label_79.setText(_translate("DockWidget", "Testing"))
        self.label_4.setToolTip(_translate("DockWidget", "This is a tool tip"))
        self.label_4.setStatusTip(_translate("DockWidget", "This is a status tip"))
        self.label_4.setWhatsThis(_translate("DockWidget", "This is \"what is this\""))
        self.label_4.setText(_translate("DockWidget", "TextBrowser"))
        self.textBrowserDis.setHtml(_translate("DockWidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'Ubuntu\'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:\'Cantarell\';\">Testing</span></p></body></html>"))
        self.label_5.setToolTip(_translate("DockWidget", "This is a tool tip"))
        self.label_5.setStatusTip(_translate("DockWidget", "This is a status tip"))
        self.label_5.setWhatsThis(_translate("DockWidget", "This is \"what is this\""))
        self.label_5.setText(_translate("DockWidget", "GraphicsView"))
        self.graphicsView.setToolTip(_translate("DockWidget", "This is a tool tip"))
        self.graphicsView.setStatusTip(_translate("DockWidget", "This is a status tip"))
        self.graphicsView.setWhatsThis(_translate("DockWidget", "This is \"what is this\""))
        self.label_6.setToolTip(_translate("DockWidget", "This is a tool tip"))
        self.label_6.setStatusTip(_translate("DockWidget", "This is a status tip"))
        self.label_6.setWhatsThis(_translate("DockWidget", "This is \"what is this\""))
        self.label_6.setText(_translate("DockWidget", "CalendarWidget"))
        self.calendarWidget.setToolTip(_translate("DockWidget", "This is a tool tip"))
        self.calendarWidget.setStatusTip(_translate("DockWidget", "This is a status tip"))
        self.calendarWidget.setWhatsThis(_translate("DockWidget", "This is \"what is this\""))
        self.label_7.setToolTip(_translate("DockWidget", "This is a tool tip"))
        self.label_7.setStatusTip(_translate("DockWidget", "This is a status tip"))
        self.label_7.setWhatsThis(_translate("DockWidget", "This is \"what is this\""))
        self.label_7.setText(_translate("DockWidget", "LCDNumber"))
        self.lcdNumber.setToolTip(_translate("DockWidget", "This is a tool tip"))
        self.lcdNumber.setStatusTip(_translate("DockWidget", "This is a status tip"))
        self.lcdNumber.setWhatsThis(_translate("DockWidget", "This is \"what is this\""))
        self.label_8.setToolTip(_translate("DockWidget", "This is a tool tip"))
        self.label_8.setStatusTip(_translate("DockWidget", "This is a status tip"))
        self.label_8.setWhatsThis(_translate("DockWidget", "This is \"what is this\""))
        self.label_8.setText(_translate("DockWidget", "ProgressBar"))
        self.progressBar.setToolTip(_translate("DockWidget", "This is a tool tip"))
        self.progressBar.setStatusTip(_translate("DockWidget", "This is a status tip"))
        self.progressBar.setWhatsThis(_translate("DockWidget", "This is \"what is this\""))
        self.label_9.setToolTip(_translate("DockWidget", "This is a tool tip"))
        self.label_9.setStatusTip(_translate("DockWidget", "This is a status tip"))
        self.label_9.setWhatsThis(_translate("DockWidget", "This is \"what is this\""))
        self.label_9.setText(_translate("DockWidget", "Line - H"))
        self.lineH.setToolTip(_translate("DockWidget", "This is a tool tip"))
        self.lineH.setStatusTip(_translate("DockWidget", "This is a status tip"))
        self.lineH.setWhatsThis(_translate("DockWidget", "This is \"what is this\""))
        self.label_10.setToolTip(_translate("DockWidget", "This is a tool tip"))
        self.label_10.setStatusTip(_translate("DockWidget", "This is a status tip"))
        self.label_10.setWhatsThis(_translate("DockWidget", "This is \"what is this\""))
        self.label_10.setText(_translate("DockWidget", "Line - V"))
        self.lineV.setToolTip(_translate("DockWidget", "This is a tool tip"))
        self.lineV.setStatusTip(_translate("DockWidget", "This is a status tip"))
        self.lineV.setWhatsThis(_translate("DockWidget", "This is \"what is this\""))
        self.label_37.setToolTip(_translate("DockWidget", "This is a tool tip"))
        self.label_37.setStatusTip(_translate("DockWidget", "This is a status tip"))
        self.label_37.setWhatsThis(_translate("DockWidget", "This is \"what is this\""))
        self.label_37.setText(_translate("DockWidget", "Inside DockWidget"))
        self.label_2.setToolTip(_translate("DockWidget", "This is a tool tip"))
        self.label_2.setStatusTip(_translate("DockWidget", "This is a status tip"))
        self.label_2.setWhatsThis(_translate("DockWidget", "This is \"what is this\""))
        self.label_2.setText(_translate("DockWidget", "Testing"))
