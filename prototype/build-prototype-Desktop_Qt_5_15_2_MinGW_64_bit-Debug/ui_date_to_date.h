/********************************************************************************
** Form generated from reading UI file 'date_to_date.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATE_TO_DATE_H
#define UI_DATE_TO_DATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_date_to_date
{
public:
    QLineEdit *begin_edit;
    QLineEdit *end_edit;
    QLabel *begin_label;
    QLabel *end_label;
    QPushButton *show_data_button;
    QPushButton *cancel_date_button;
    QPlainTextEdit *instructions_edit;

    void setupUi(QWidget *date_to_date)
    {
        if (date_to_date->objectName().isEmpty())
            date_to_date->setObjectName(QString::fromUtf8("date_to_date"));
        date_to_date->resize(400, 162);
        begin_edit = new QLineEdit(date_to_date);
        begin_edit->setObjectName(QString::fromUtf8("begin_edit"));
        begin_edit->setGeometry(QRect(30, 50, 141, 21));
        end_edit = new QLineEdit(date_to_date);
        end_edit->setObjectName(QString::fromUtf8("end_edit"));
        end_edit->setGeometry(QRect(30, 110, 141, 21));
        begin_label = new QLabel(date_to_date);
        begin_label->setObjectName(QString::fromUtf8("begin_label"));
        begin_label->setGeometry(QRect(30, 25, 141, 21));
        end_label = new QLabel(date_to_date);
        end_label->setObjectName(QString::fromUtf8("end_label"));
        end_label->setGeometry(QRect(30, 86, 131, 20));
        show_data_button = new QPushButton(date_to_date);
        show_data_button->setObjectName(QString::fromUtf8("show_data_button"));
        show_data_button->setGeometry(QRect(189, 100, 91, 31));
        cancel_date_button = new QPushButton(date_to_date);
        cancel_date_button->setObjectName(QString::fromUtf8("cancel_date_button"));
        cancel_date_button->setGeometry(QRect(289, 100, 91, 31));
        instructions_edit = new QPlainTextEdit(date_to_date);
        instructions_edit->setObjectName(QString::fromUtf8("instructions_edit"));
        instructions_edit->setGeometry(QRect(190, 20, 181, 70));

        retranslateUi(date_to_date);

        QMetaObject::connectSlotsByName(date_to_date);
    } // setupUi

    void retranslateUi(QWidget *date_to_date)
    {
        date_to_date->setWindowTitle(QCoreApplication::translate("date_to_date", "Form", nullptr));
        begin_label->setText(QCoreApplication::translate("date_to_date", "Begin date (dd/mm/yyyy)", nullptr));
        end_label->setText(QCoreApplication::translate("date_to_date", "End date (dd/mm/yyyy)", nullptr));
        show_data_button->setText(QCoreApplication::translate("date_to_date", "Show data", nullptr));
        cancel_date_button->setText(QCoreApplication::translate("date_to_date", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class date_to_date: public Ui_date_to_date {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATE_TO_DATE_H
