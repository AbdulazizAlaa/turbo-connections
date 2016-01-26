/********************************************************************************
** Form generated from reading UI file 'visualizingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISUALIZINGDIALOG_H
#define UI_VISUALIZINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_VisualizingDialog
{
public:
    QVBoxLayout *verticalLayout;
    QOpenGLWidget *openGLWidget;
    QPushButton *closeB;

    void setupUi(QDialog *VisualizingDialog)
    {
        if (VisualizingDialog->objectName().isEmpty())
            VisualizingDialog->setObjectName(QStringLiteral("VisualizingDialog"));
        VisualizingDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(VisualizingDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        openGLWidget = new QOpenGLWidget(VisualizingDialog);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));

        verticalLayout->addWidget(openGLWidget);

        closeB = new QPushButton(VisualizingDialog);
        closeB->setObjectName(QStringLiteral("closeB"));

        verticalLayout->addWidget(closeB);


        retranslateUi(VisualizingDialog);
        QObject::connect(closeB, SIGNAL(clicked()), VisualizingDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(VisualizingDialog);
    } // setupUi

    void retranslateUi(QDialog *VisualizingDialog)
    {
        VisualizingDialog->setWindowTitle(QApplication::translate("VisualizingDialog", "Dialog", 0));
        closeB->setText(QApplication::translate("VisualizingDialog", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class VisualizingDialog: public Ui_VisualizingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUALIZINGDIALOG_H
