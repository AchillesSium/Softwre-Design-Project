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
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TimeWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_3;
    QStackedWidget *stackedSelection;
    QWidget *statfi_query;
    QVBoxLayout *verticalLayout_3;
    QLabel *beginYear;
    QLineEdit *beginEdit;
    QSpacerItem *verticalSpacer;
    QLabel *endYear;
    QLineEdit *endEdit;
    QSpacerItem *verticalSpacer_5;
    QWidget *smear_query;
    QVBoxLayout *verticalLayout_4;
    QCalendarWidget *calendar;
    QSpacerItem *verticalSpacer_4;
    QGridLayout *gridLayout_2;
    QPushButton *endButton;
    QLabel *endDate;
    QLabel *beginDate;
    QLabel *beginDateLabel;
    QPushButton *beginButton;
    QLabel *endDateLabel;
    QPushButton *resetBeginButton;
    QPushButton *resetEndButton;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *infoEdit;
    QPushButton *showButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *TimeWindow)
    {
        if (TimeWindow->objectName().isEmpty())
            TimeWindow->setObjectName(QStringLiteral("TimeWindow"));
        TimeWindow->resize(806, 332);
        horizontalLayout = new QHBoxLayout(TimeWindow);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer_3);

        stackedSelection = new QStackedWidget(TimeWindow);
        stackedSelection->setObjectName(QStringLiteral("stackedSelection"));
        statfi_query = new QWidget();
        statfi_query->setObjectName(QStringLiteral("statfi_query"));
        verticalLayout_3 = new QVBoxLayout(statfi_query);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        beginYear = new QLabel(statfi_query);
        beginYear->setObjectName(QStringLiteral("beginYear"));

        verticalLayout_3->addWidget(beginYear);

        beginEdit = new QLineEdit(statfi_query);
        beginEdit->setObjectName(QStringLiteral("beginEdit"));

        verticalLayout_3->addWidget(beginEdit);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_3->addItem(verticalSpacer);

        endYear = new QLabel(statfi_query);
        endYear->setObjectName(QStringLiteral("endYear"));

        verticalLayout_3->addWidget(endYear);

        endEdit = new QLineEdit(statfi_query);
        endEdit->setObjectName(QStringLiteral("endEdit"));

        verticalLayout_3->addWidget(endEdit);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_5);

        stackedSelection->addWidget(statfi_query);
        smear_query = new QWidget();
        smear_query->setObjectName(QStringLiteral("smear_query"));
        verticalLayout_4 = new QVBoxLayout(smear_query);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        calendar = new QCalendarWidget(smear_query);
        calendar->setObjectName(QStringLiteral("calendar"));

        verticalLayout_4->addWidget(calendar);

        verticalSpacer_4 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_4->addItem(verticalSpacer_4);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, -1, -1, 0);
        endButton = new QPushButton(smear_query);
        endButton->setObjectName(QStringLiteral("endButton"));

        gridLayout_2->addWidget(endButton, 2, 2, 1, 1);

        endDate = new QLabel(smear_query);
        endDate->setObjectName(QStringLiteral("endDate"));

        gridLayout_2->addWidget(endDate, 2, 1, 1, 1);

        beginDate = new QLabel(smear_query);
        beginDate->setObjectName(QStringLiteral("beginDate"));

        gridLayout_2->addWidget(beginDate, 0, 1, 1, 1);

        beginDateLabel = new QLabel(smear_query);
        beginDateLabel->setObjectName(QStringLiteral("beginDateLabel"));

        gridLayout_2->addWidget(beginDateLabel, 0, 0, 1, 1);

        beginButton = new QPushButton(smear_query);
        beginButton->setObjectName(QStringLiteral("beginButton"));

        gridLayout_2->addWidget(beginButton, 0, 2, 1, 1);

        endDateLabel = new QLabel(smear_query);
        endDateLabel->setObjectName(QStringLiteral("endDateLabel"));

        gridLayout_2->addWidget(endDateLabel, 2, 0, 1, 1);

        resetBeginButton = new QPushButton(smear_query);
        resetBeginButton->setObjectName(QStringLiteral("resetBeginButton"));

        gridLayout_2->addWidget(resetBeginButton, 0, 3, 1, 1);

        resetEndButton = new QPushButton(smear_query);
        resetEndButton->setObjectName(QStringLiteral("resetEndButton"));

        gridLayout_2->addWidget(resetEndButton, 2, 3, 1, 1);


        verticalLayout_4->addLayout(gridLayout_2);

        stackedSelection->addWidget(smear_query);

        verticalLayout->addWidget(stackedSelection);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        infoEdit = new QTextEdit(TimeWindow);
        infoEdit->setObjectName(QStringLiteral("infoEdit"));
        infoEdit->setMaximumSize(QSize(400, 16777215));

        verticalLayout_2->addWidget(infoEdit);

        showButton = new QPushButton(TimeWindow);
        showButton->setObjectName(QStringLiteral("showButton"));
        showButton->setMaximumSize(QSize(400, 16777215));

        verticalLayout_2->addWidget(showButton);

        cancelButton = new QPushButton(TimeWindow);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setMaximumSize(QSize(400, 16777215));

        verticalLayout_2->addWidget(cancelButton);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(TimeWindow);

        stackedSelection->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TimeWindow);
    } // setupUi

    void retranslateUi(QDialog *TimeWindow)
    {
        TimeWindow->setWindowTitle(QApplication::translate("TimeWindow", "Dialog", Q_NULLPTR));
        beginYear->setText(QApplication::translate("TimeWindow", "Begin year (yyyy)", Q_NULLPTR));
        endYear->setText(QApplication::translate("TimeWindow", "End year (yyyy)", Q_NULLPTR));
        endButton->setText(QApplication::translate("TimeWindow", "Select Ending", Q_NULLPTR));
        endDate->setText(QApplication::translate("TimeWindow", "Not Selected", Q_NULLPTR));
        beginDate->setText(QApplication::translate("TimeWindow", "Not Selected", Q_NULLPTR));
        beginDateLabel->setText(QApplication::translate("TimeWindow", "Begin date:", Q_NULLPTR));
        beginButton->setText(QApplication::translate("TimeWindow", "Select Beginning", Q_NULLPTR));
        endDateLabel->setText(QApplication::translate("TimeWindow", "End date:", Q_NULLPTR));
        resetBeginButton->setText(QApplication::translate("TimeWindow", "Reset Beginning", Q_NULLPTR));
        resetEndButton->setText(QApplication::translate("TimeWindow", "Reset Ending", Q_NULLPTR));
        showButton->setText(QApplication::translate("TimeWindow", "Show data", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("TimeWindow", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TimeWindow: public Ui_TimeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMEWINDOW_H
