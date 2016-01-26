/********************************************************************************
** Form generated from reading UI file 'visualizingwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISUALIZINGWINDOW_H
#define UI_VISUALIZINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VisualizingWindow
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *VisualizingWindow)
    {
        if (VisualizingWindow->objectName().isEmpty())
            VisualizingWindow->setObjectName(QStringLiteral("VisualizingWindow"));
        VisualizingWindow->resize(800, 600);
        menubar = new QMenuBar(VisualizingWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        VisualizingWindow->setMenuBar(menubar);
        centralwidget = new QWidget(VisualizingWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        VisualizingWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(VisualizingWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        VisualizingWindow->setStatusBar(statusbar);

        retranslateUi(VisualizingWindow);

        QMetaObject::connectSlotsByName(VisualizingWindow);
    } // setupUi

    void retranslateUi(QMainWindow *VisualizingWindow)
    {
        VisualizingWindow->setWindowTitle(QApplication::translate("VisualizingWindow", "MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class VisualizingWindow: public Ui_VisualizingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUALIZINGWINDOW_H
