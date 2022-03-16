/********************************************************************************
** Form generated from reading UI file 'settingswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWINDOW_H
#define UI_SETTINGSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_settingsWindow
{
public:
    QPushButton *pushButton;
    QPushButton *exit_settings_button;
    QPushButton *pushButton_3;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QSlider *horizontalSlider;
    QLabel *label;

    void setupUi(QWidget *settingsWindow)
    {
        if (settingsWindow->objectName().isEmpty())
            settingsWindow->setObjectName(QStringLiteral("settingsWindow"));
        settingsWindow->resize(357, 292);
        pushButton = new QPushButton(settingsWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(140, 250, 91, 31));
        exit_settings_button = new QPushButton(settingsWindow);
        exit_settings_button->setObjectName(QStringLiteral("exit_settings_button"));
        exit_settings_button->setGeometry(QRect(250, 250, 81, 31));
        pushButton_3 = new QPushButton(settingsWindow);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(30, 250, 91, 31));
        checkBox = new QCheckBox(settingsWindow);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(30, 30, 72, 19));
        checkBox_2 = new QCheckBox(settingsWindow);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(30, 60, 72, 19));
        checkBox_3 = new QCheckBox(settingsWindow);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(30, 90, 72, 19));
        horizontalSlider = new QSlider(settingsWindow);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(30, 170, 281, 31));
        horizontalSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(settingsWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 160, 47, 13));

        retranslateUi(settingsWindow);

        QMetaObject::connectSlotsByName(settingsWindow);
    } // setupUi

    void retranslateUi(QWidget *settingsWindow)
    {
        settingsWindow->setWindowTitle(QApplication::translate("settingsWindow", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("settingsWindow", "OK", Q_NULLPTR));
        exit_settings_button->setText(QApplication::translate("settingsWindow", "Cancel", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("settingsWindow", "Apply", Q_NULLPTR));
        checkBox->setText(QApplication::translate("settingsWindow", "Enable", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("settingsWindow", "Disable", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("settingsWindow", "Check", Q_NULLPTR));
        label->setText(QApplication::translate("settingsWindow", "Slider", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class settingsWindow: public Ui_settingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWINDOW_H
