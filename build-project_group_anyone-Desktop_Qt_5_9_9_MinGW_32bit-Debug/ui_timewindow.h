/********************************************************************************
** Form generated from reading UI file 'timewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMEWINDOW_H
#define UI_TIMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TimeWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_3;
    QLabel *beginLabel;
    QLineEdit *beginEdit;
    QSpacerItem *verticalSpacer;
    QLabel *endLabel;
    QLineEdit *endEdit;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QTextBrowser *infoBrowser;
    QPushButton *showButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *TimeWindow)
    {
        if (TimeWindow->objectName().isEmpty())
            TimeWindow->setObjectName(QStringLiteral("TimeWindow"));
        TimeWindow->resize(376, 300);
        horizontalLayout = new QHBoxLayout(TimeWindow);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer_3);

        beginLabel = new QLabel(TimeWindow);
        beginLabel->setObjectName(QStringLiteral("beginLabel"));

        verticalLayout->addWidget(beginLabel);

        beginEdit = new QLineEdit(TimeWindow);
        beginEdit->setObjectName(QStringLiteral("beginEdit"));

        verticalLayout->addWidget(beginEdit);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer);

        endLabel = new QLabel(TimeWindow);
        endLabel->setObjectName(QStringLiteral("endLabel"));

        verticalLayout->addWidget(endLabel);

        endEdit = new QLineEdit(TimeWindow);
        endEdit->setObjectName(QStringLiteral("endEdit"));

        verticalLayout->addWidget(endEdit);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        infoBrowser = new QTextBrowser(TimeWindow);
        infoBrowser->setObjectName(QStringLiteral("infoBrowser"));

        verticalLayout_2->addWidget(infoBrowser);

        showButton = new QPushButton(TimeWindow);
        showButton->setObjectName(QStringLiteral("showButton"));

        verticalLayout_2->addWidget(showButton);

        cancelButton = new QPushButton(TimeWindow);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        verticalLayout_2->addWidget(cancelButton);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(TimeWindow);

        QMetaObject::connectSlotsByName(TimeWindow);
    } // setupUi

    void retranslateUi(QDialog *TimeWindow)
    {
        TimeWindow->setWindowTitle(QApplication::translate("TimeWindow", "Dialog", Q_NULLPTR));
        beginLabel->setText(QApplication::translate("TimeWindow", "Begin date (dd/mm/yyyy)", Q_NULLPTR));
        endLabel->setText(QApplication::translate("TimeWindow", "End date (dd/mm/yyyy)", Q_NULLPTR));
        showButton->setText(QApplication::translate("TimeWindow", "Show data", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("TimeWindow", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TimeWindow: public Ui_TimeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMEWINDOW_H
