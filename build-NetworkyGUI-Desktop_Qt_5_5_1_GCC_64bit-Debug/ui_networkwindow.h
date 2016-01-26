/********************************************************************************
** Form generated from reading UI file 'networkwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETWORKWINDOW_H
#define UI_NETWORKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "openglwindow.h"

QT_BEGIN_NAMESPACE

class Ui_NetworkWindow
{
public:
    QWidget *centralWidget;
    QPushButton *updateB;
    QListView *personsLV;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *person_name_label;
    QLabel *person_address_label;
    QLabel *person_company_label;
    QLabel *person_title_label;
    QLabel *label_5;
    QListView *connectionsLV;
    QLineEdit *name_searchLE;
    QPushButton *name_searchB;
    QPushButton *visualizeNetB;
    OpenGLWindow *openGLWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *NetworkWindow)
    {
        if (NetworkWindow->objectName().isEmpty())
            NetworkWindow->setObjectName(QStringLiteral("NetworkWindow"));
        NetworkWindow->resize(406, 384);
        centralWidget = new QWidget(NetworkWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        updateB = new QPushButton(centralWidget);
        updateB->setObjectName(QStringLiteral("updateB"));
        updateB->setGeometry(QRect(20, 270, 121, 23));
        personsLV = new QListView(centralWidget);
        personsLV->setObjectName(QStringLiteral("personsLV"));
        personsLV->setGeometry(QRect(10, 70, 151, 192));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 10, 59, 15));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(170, 50, 59, 15));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(170, 70, 59, 15));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(170, 30, 59, 15));
        person_name_label = new QLabel(centralWidget);
        person_name_label->setObjectName(QStringLiteral("person_name_label"));
        person_name_label->setGeometry(QRect(250, 10, 141, 16));
        person_address_label = new QLabel(centralWidget);
        person_address_label->setObjectName(QStringLiteral("person_address_label"));
        person_address_label->setGeometry(QRect(250, 50, 141, 16));
        person_company_label = new QLabel(centralWidget);
        person_company_label->setObjectName(QStringLiteral("person_company_label"));
        person_company_label->setGeometry(QRect(250, 70, 141, 16));
        person_title_label = new QLabel(centralWidget);
        person_title_label->setObjectName(QStringLiteral("person_title_label"));
        person_title_label->setGeometry(QRect(250, 30, 141, 16));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(170, 100, 81, 16));
        connectionsLV = new QListView(centralWidget);
        connectionsLV->setObjectName(QStringLiteral("connectionsLV"));
        connectionsLV->setGeometry(QRect(250, 110, 141, 121));
        name_searchLE = new QLineEdit(centralWidget);
        name_searchLE->setObjectName(QStringLiteral("name_searchLE"));
        name_searchLE->setGeometry(QRect(10, 10, 151, 23));
        name_searchB = new QPushButton(centralWidget);
        name_searchB->setObjectName(QStringLiteral("name_searchB"));
        name_searchB->setGeometry(QRect(10, 40, 151, 23));
        visualizeNetB = new QPushButton(centralWidget);
        visualizeNetB->setObjectName(QStringLiteral("visualizeNetB"));
        visualizeNetB->setGeometry(QRect(20, 300, 121, 23));
        openGLWidget = new OpenGLWindow(centralWidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        openGLWidget->setGeometry(QRect(170, 240, 111, 71));
        NetworkWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(NetworkWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 406, 20));
        NetworkWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(NetworkWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        NetworkWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(NetworkWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        NetworkWindow->setStatusBar(statusBar);

        retranslateUi(NetworkWindow);

        QMetaObject::connectSlotsByName(NetworkWindow);
    } // setupUi

    void retranslateUi(QMainWindow *NetworkWindow)
    {
        NetworkWindow->setWindowTitle(QApplication::translate("NetworkWindow", "NetworkWindow", 0));
        updateB->setText(QApplication::translate("NetworkWindow", "Update Network", 0));
        label->setText(QApplication::translate("NetworkWindow", "Name", 0));
        label_2->setText(QApplication::translate("NetworkWindow", "Address", 0));
        label_3->setText(QApplication::translate("NetworkWindow", "Company", 0));
        label_4->setText(QApplication::translate("NetworkWindow", "Title", 0));
        person_name_label->setText(QString());
        person_address_label->setText(QString());
        person_company_label->setText(QString());
        person_title_label->setText(QString());
        label_5->setText(QApplication::translate("NetworkWindow", "Connections", 0));
        name_searchB->setText(QApplication::translate("NetworkWindow", "Search", 0));
        visualizeNetB->setText(QApplication::translate("NetworkWindow", "Visualize Network", 0));
    } // retranslateUi

};

namespace Ui {
    class NetworkWindow: public Ui_NetworkWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETWORKWINDOW_H
