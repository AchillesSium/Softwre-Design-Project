/********************************************************************************
** Form generated from reading UI file 'chartwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARTWINDOW_H
#define UI_CHARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QtCharts"

QT_BEGIN_NAMESPACE

class Ui_ChartWindow
{
public:
    QAction *actionNewWindow;
    QAction *actionLoadLoadout;
    QAction *actionSaveLoadout;
    QAction *actionPic;
    QAction *actionCloseWindow;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QChartView *chartView;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_4;
    QLabel *databaseLabel;
    QComboBox *databaseCombo;
    QLabel *stationLabel;
    QComboBox *stationCombo;
    QLabel *aggregationLabel;
    QComboBox *aggregationCombo;
    QSpacerItem *verticalSpacer_8;
    QHBoxLayout *horizontalLayout_3;
    QStackedWidget *stackedBoxes;
    QWidget *smearBox;
    QVBoxLayout *verticalLayout_5;
    QLabel *gasesLabel;
    QRadioButton *co2Radio;
    QRadioButton *so2Radio;
    QRadioButton *noxRadio;
    QSpacerItem *verticalSpacer_2;
    QWidget *statfiBox;
    QVBoxLayout *verticalLayout_6;
    QLabel *datasetsLabel;
    QRadioButton *co2DataRadio;
    QRadioButton *intensityRadio;
    QRadioButton *indexedRadio;
    QRadioButton *indexedIntensityRadio;
    QSpacerItem *verticalSpacer_7;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout;
    QPushButton *yearButton;
    QPushButton *monthButton;
    QPushButton *weekButton;
    QPushButton *dayButton;
    QLabel *spanLabel;
    QPushButton *timeButton;
    QSpacerItem *verticalSpacer_9;
    QPlainTextEdit *selected_time_display;
    QFrame *verticalLine;
    QSpacerItem *verticalSpacer_10;
    QPushButton *defaultButton;
    QPushButton *applyButton;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QMenu *menuWindow;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChartWindow)
    {
        if (ChartWindow->objectName().isEmpty())
            ChartWindow->setObjectName(QStringLiteral("ChartWindow"));
        ChartWindow->resize(1117, 624);
        actionNewWindow = new QAction(ChartWindow);
        actionNewWindow->setObjectName(QStringLiteral("actionNewWindow"));
        actionLoadLoadout = new QAction(ChartWindow);
        actionLoadLoadout->setObjectName(QStringLiteral("actionLoadLoadout"));
        actionSaveLoadout = new QAction(ChartWindow);
        actionSaveLoadout->setObjectName(QStringLiteral("actionSaveLoadout"));
        actionPic = new QAction(ChartWindow);
        actionPic->setObjectName(QStringLiteral("actionPic"));
        actionCloseWindow = new QAction(ChartWindow);
        actionCloseWindow->setObjectName(QStringLiteral("actionCloseWindow"));
        centralwidget = new QWidget(ChartWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        chartView = new QChartView(centralwidget);
        chartView->setObjectName(QStringLiteral("chartView"));

        horizontalLayout->addWidget(chartView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer_4);

        databaseLabel = new QLabel(centralwidget);
        databaseLabel->setObjectName(QStringLiteral("databaseLabel"));

        verticalLayout->addWidget(databaseLabel);

        databaseCombo = new QComboBox(centralwidget);
        databaseCombo->setObjectName(QStringLiteral("databaseCombo"));

        verticalLayout->addWidget(databaseCombo);

        stationLabel = new QLabel(centralwidget);
        stationLabel->setObjectName(QStringLiteral("stationLabel"));

        verticalLayout->addWidget(stationLabel);

        stationCombo = new QComboBox(centralwidget);
        stationCombo->setObjectName(QStringLiteral("stationCombo"));

        verticalLayout->addWidget(stationCombo);

        aggregationLabel = new QLabel(centralwidget);
        aggregationLabel->setObjectName(QStringLiteral("aggregationLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(aggregationLabel->sizePolicy().hasHeightForWidth());
        aggregationLabel->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(aggregationLabel);

        aggregationCombo = new QComboBox(centralwidget);
        aggregationCombo->setObjectName(QStringLiteral("aggregationCombo"));

        verticalLayout->addWidget(aggregationCombo);

        verticalSpacer_8 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_8);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 14, -1, -1);
        stackedBoxes = new QStackedWidget(centralwidget);
        stackedBoxes->setObjectName(QStringLiteral("stackedBoxes"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(stackedBoxes->sizePolicy().hasHeightForWidth());
        stackedBoxes->setSizePolicy(sizePolicy1);
        smearBox = new QWidget();
        smearBox->setObjectName(QStringLiteral("smearBox"));
        verticalLayout_5 = new QVBoxLayout(smearBox);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        gasesLabel = new QLabel(smearBox);
        gasesLabel->setObjectName(QStringLiteral("gasesLabel"));

        verticalLayout_5->addWidget(gasesLabel);

        co2Radio = new QRadioButton(smearBox);
        co2Radio->setObjectName(QStringLiteral("co2Radio"));

        verticalLayout_5->addWidget(co2Radio);

        so2Radio = new QRadioButton(smearBox);
        so2Radio->setObjectName(QStringLiteral("so2Radio"));

        verticalLayout_5->addWidget(so2Radio);

        noxRadio = new QRadioButton(smearBox);
        noxRadio->setObjectName(QStringLiteral("noxRadio"));

        verticalLayout_5->addWidget(noxRadio);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);

        stackedBoxes->addWidget(smearBox);
        statfiBox = new QWidget();
        statfiBox->setObjectName(QStringLiteral("statfiBox"));
        verticalLayout_6 = new QVBoxLayout(statfiBox);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        datasetsLabel = new QLabel(statfiBox);
        datasetsLabel->setObjectName(QStringLiteral("datasetsLabel"));

        verticalLayout_6->addWidget(datasetsLabel);

        co2DataRadio = new QRadioButton(statfiBox);
        co2DataRadio->setObjectName(QStringLiteral("co2DataRadio"));

        verticalLayout_6->addWidget(co2DataRadio);

        intensityRadio = new QRadioButton(statfiBox);
        intensityRadio->setObjectName(QStringLiteral("intensityRadio"));

        verticalLayout_6->addWidget(intensityRadio);

        indexedRadio = new QRadioButton(statfiBox);
        indexedRadio->setObjectName(QStringLiteral("indexedRadio"));

        verticalLayout_6->addWidget(indexedRadio);

        indexedIntensityRadio = new QRadioButton(statfiBox);
        indexedIntensityRadio->setObjectName(QStringLiteral("indexedIntensityRadio"));

        verticalLayout_6->addWidget(indexedIntensityRadio);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_7);

        stackedBoxes->addWidget(statfiBox);

        horizontalLayout_3->addWidget(stackedBoxes);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));

        verticalLayout->addLayout(horizontalLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        yearButton = new QPushButton(centralwidget);
        yearButton->setObjectName(QStringLiteral("yearButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(yearButton->sizePolicy().hasHeightForWidth());
        yearButton->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(yearButton, 1, 0, 1, 1);

        monthButton = new QPushButton(centralwidget);
        monthButton->setObjectName(QStringLiteral("monthButton"));

        gridLayout->addWidget(monthButton, 1, 1, 1, 1);

        weekButton = new QPushButton(centralwidget);
        weekButton->setObjectName(QStringLiteral("weekButton"));

        gridLayout->addWidget(weekButton, 2, 0, 1, 1);

        dayButton = new QPushButton(centralwidget);
        dayButton->setObjectName(QStringLiteral("dayButton"));

        gridLayout->addWidget(dayButton, 2, 1, 1, 1);

        spanLabel = new QLabel(centralwidget);
        spanLabel->setObjectName(QStringLiteral("spanLabel"));

        gridLayout->addWidget(spanLabel, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        timeButton = new QPushButton(centralwidget);
        timeButton->setObjectName(QStringLiteral("timeButton"));

        verticalLayout->addWidget(timeButton);

        verticalSpacer_9 = new QSpacerItem(40, 10, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer_9);

        selected_time_display = new QPlainTextEdit(centralwidget);
        selected_time_display->setObjectName(QStringLiteral("selected_time_display"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(selected_time_display->sizePolicy().hasHeightForWidth());
        selected_time_display->setSizePolicy(sizePolicy3);
        selected_time_display->setMaximumSize(QSize(168, 50));

        verticalLayout->addWidget(selected_time_display);

        verticalLine = new QFrame(centralwidget);
        verticalLine->setObjectName(QStringLiteral("verticalLine"));
        verticalLine->setFrameShape(QFrame::HLine);
        verticalLine->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(verticalLine);

        verticalSpacer_10 = new QSpacerItem(40, 10, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer_10);

        defaultButton = new QPushButton(centralwidget);
        defaultButton->setObjectName(QStringLiteral("defaultButton"));

        verticalLayout->addWidget(defaultButton);

        applyButton = new QPushButton(centralwidget);
        applyButton->setObjectName(QStringLiteral("applyButton"));

        verticalLayout->addWidget(applyButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        ChartWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ChartWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1117, 20));
        menuWindow = new QMenu(menubar);
        menuWindow->setObjectName(QStringLiteral("menuWindow"));
        ChartWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ChartWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ChartWindow->setStatusBar(statusbar);

        menubar->addAction(menuWindow->menuAction());
        menuWindow->addAction(actionNewWindow);
        menuWindow->addAction(actionLoadLoadout);
        menuWindow->addAction(actionSaveLoadout);
        menuWindow->addSeparator();
        menuWindow->addAction(actionPic);
        menuWindow->addAction(actionCloseWindow);

        retranslateUi(ChartWindow);

        stackedBoxes->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ChartWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ChartWindow)
    {
        ChartWindow->setWindowTitle(QApplication::translate("ChartWindow", "ChartWindow", Q_NULLPTR));
        actionNewWindow->setText(QApplication::translate("ChartWindow", "New Window", Q_NULLPTR));
        actionLoadLoadout->setText(QApplication::translate("ChartWindow", "Load Loadout", Q_NULLPTR));
        actionSaveLoadout->setText(QApplication::translate("ChartWindow", "Save Loadout", Q_NULLPTR));
        actionPic->setText(QApplication::translate("ChartWindow", "Save chart as a picture", Q_NULLPTR));
        actionCloseWindow->setText(QApplication::translate("ChartWindow", "Close Window", Q_NULLPTR));
        databaseLabel->setText(QApplication::translate("ChartWindow", "Database", Q_NULLPTR));
        databaseCombo->clear();
        databaseCombo->insertItems(0, QStringList()
         << QApplication::translate("ChartWindow", "STATFI", Q_NULLPTR)
         << QApplication::translate("ChartWindow", "SMEAR", Q_NULLPTR)
        );
        stationLabel->setText(QApplication::translate("ChartWindow", "Measuring Station", Q_NULLPTR));
        stationCombo->clear();
        stationCombo->insertItems(0, QStringList()
         << QApplication::translate("ChartWindow", "V\303\244rri\303\266", Q_NULLPTR)
         << QApplication::translate("ChartWindow", "Hyyti\303\244l\303\244", Q_NULLPTR)
         << QApplication::translate("ChartWindow", "Kumpula", Q_NULLPTR)
        );
        aggregationLabel->setText(QApplication::translate("ChartWindow", "Aggregation Type", Q_NULLPTR));
        aggregationCombo->clear();
        aggregationCombo->insertItems(0, QStringList()
         << QApplication::translate("ChartWindow", "Arithmetic", Q_NULLPTR)
         << QApplication::translate("ChartWindow", "Geometric", Q_NULLPTR)
         << QApplication::translate("ChartWindow", "Sum", Q_NULLPTR)
         << QApplication::translate("ChartWindow", "Median", Q_NULLPTR)
         << QApplication::translate("ChartWindow", "Min", Q_NULLPTR)
         << QApplication::translate("ChartWindow", "Max", Q_NULLPTR)
         << QApplication::translate("ChartWindow", "Availabiliy", Q_NULLPTR)
         << QApplication::translate("ChartWindow", "Circular", Q_NULLPTR)
        );
        gasesLabel->setText(QApplication::translate("ChartWindow", "Gases", Q_NULLPTR));
        co2Radio->setText(QApplication::translate("ChartWindow", "    CO2", Q_NULLPTR));
        so2Radio->setText(QApplication::translate("ChartWindow", "    SO2", Q_NULLPTR));
        noxRadio->setText(QApplication::translate("ChartWindow", "    NOx", Q_NULLPTR));
        datasetsLabel->setText(QApplication::translate("ChartWindow", "CO2 Data sets", Q_NULLPTR));
        co2DataRadio->setText(QApplication::translate("ChartWindow", "    CO2", Q_NULLPTR));
        intensityRadio->setText(QApplication::translate("ChartWindow", "    Intensity", Q_NULLPTR));
        indexedRadio->setText(QApplication::translate("ChartWindow", "    Indexed", Q_NULLPTR));
        indexedIntensityRadio->setText(QApplication::translate("ChartWindow", "    Indexed Intentisy", Q_NULLPTR));
        yearButton->setText(QApplication::translate("ChartWindow", "Year", Q_NULLPTR));
        monthButton->setText(QApplication::translate("ChartWindow", "Month", Q_NULLPTR));
        weekButton->setText(QApplication::translate("ChartWindow", "Week", Q_NULLPTR));
        dayButton->setText(QApplication::translate("ChartWindow", "24h", Q_NULLPTR));
        spanLabel->setText(QApplication::translate("ChartWindow", "Time span", Q_NULLPTR));
        timeButton->setText(QApplication::translate("ChartWindow", "Date-to-Date", Q_NULLPTR));
        defaultButton->setText(QApplication::translate("ChartWindow", "Default Loadout", Q_NULLPTR));
        applyButton->setText(QApplication::translate("ChartWindow", "Apply", Q_NULLPTR));
        menuWindow->setTitle(QApplication::translate("ChartWindow", "Window", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChartWindow: public Ui_ChartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARTWINDOW_H
