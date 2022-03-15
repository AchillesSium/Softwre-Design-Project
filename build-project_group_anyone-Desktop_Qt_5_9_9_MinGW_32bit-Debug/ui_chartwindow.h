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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
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
    QAction *actionChooseLoadout;
    QAction *actionSaveLoadout;
    QAction *actionSettings;
    QAction *actionCloseWindow;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QChartView *chartView;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_4;
    QComboBox *databaseCombo;
    QComboBox *stationCombo;
    QSpacerItem *verticalSpacer_8;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *stackedBoxes;
    QWidget *smearBox;
    QVBoxLayout *verticalLayout_5;
    QLabel *gasesLabel;
    QCheckBox *co2Box;
    QCheckBox *so2Box;
    QCheckBox *noxBox;
    QCheckBox *otherBox;
    QSpacerItem *verticalSpacer_2;
    QWidget *statfiBox;
    QVBoxLayout *verticalLayout_6;
    QLabel *datasetsLabel;
    QRadioButton *co2DataRadio;
    QRadioButton *intensityRadio;
    QRadioButton *indexedRadio;
    QRadioButton *indexedIntensityRadio;
    QSpacerItem *verticalSpacer_7;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QFrame *line_2;
    QSpacerItem *verticalSpacer_5;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_6;
    QLabel *additionalLabel;
    QCheckBox *maxBox;
    QCheckBox *minBox;
    QCheckBox *avgBox;
    QSpacerItem *verticalSpacer_3;
    QGridLayout *gridLayout;
    QPushButton *yearButton;
    QPushButton *monthButton;
    QPushButton *weekButton;
    QPushButton *dayButton;
    QPushButton *timeButton;
    QSpacerItem *verticalSpacer_9;
    QFrame *line;
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
        ChartWindow->resize(1003, 604);
        actionNewWindow = new QAction(ChartWindow);
        actionNewWindow->setObjectName(QStringLiteral("actionNewWindow"));
        actionChooseLoadout = new QAction(ChartWindow);
        actionChooseLoadout->setObjectName(QStringLiteral("actionChooseLoadout"));
        actionSaveLoadout = new QAction(ChartWindow);
        actionSaveLoadout->setObjectName(QStringLiteral("actionSaveLoadout"));
        actionSettings = new QAction(ChartWindow);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
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

        databaseCombo = new QComboBox(centralwidget);
        databaseCombo->setObjectName(QStringLiteral("databaseCombo"));

        verticalLayout->addWidget(databaseCombo);

        stationCombo = new QComboBox(centralwidget);
        stationCombo->setObjectName(QStringLiteral("stationCombo"));

        verticalLayout->addWidget(stationCombo);

        verticalSpacer_8 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_8);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        stackedBoxes = new QStackedWidget(centralwidget);
        stackedBoxes->setObjectName(QStringLiteral("stackedBoxes"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stackedBoxes->sizePolicy().hasHeightForWidth());
        stackedBoxes->setSizePolicy(sizePolicy);
        smearBox = new QWidget();
        smearBox->setObjectName(QStringLiteral("smearBox"));
        verticalLayout_5 = new QVBoxLayout(smearBox);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        gasesLabel = new QLabel(smearBox);
        gasesLabel->setObjectName(QStringLiteral("gasesLabel"));

        verticalLayout_5->addWidget(gasesLabel);

        co2Box = new QCheckBox(smearBox);
        co2Box->setObjectName(QStringLiteral("co2Box"));

        verticalLayout_5->addWidget(co2Box);

        so2Box = new QCheckBox(smearBox);
        so2Box->setObjectName(QStringLiteral("so2Box"));

        verticalLayout_5->addWidget(so2Box);

        noxBox = new QCheckBox(smearBox);
        noxBox->setObjectName(QStringLiteral("noxBox"));

        verticalLayout_5->addWidget(noxBox);

        otherBox = new QCheckBox(smearBox);
        otherBox->setObjectName(QStringLiteral("otherBox"));

        verticalLayout_5->addWidget(otherBox);

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

        verticalLayout_2->addWidget(stackedBoxes);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_2);


        verticalLayout_4->addLayout(horizontalLayout_3);

        verticalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_4->addItem(verticalSpacer_5);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalSpacer_6 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_6);

        additionalLabel = new QLabel(centralwidget);
        additionalLabel->setObjectName(QStringLiteral("additionalLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(additionalLabel->sizePolicy().hasHeightForWidth());
        additionalLabel->setSizePolicy(sizePolicy1);

        verticalLayout_3->addWidget(additionalLabel);

        maxBox = new QCheckBox(centralwidget);
        maxBox->setObjectName(QStringLiteral("maxBox"));

        verticalLayout_3->addWidget(maxBox);

        minBox = new QCheckBox(centralwidget);
        minBox->setObjectName(QStringLiteral("minBox"));

        verticalLayout_3->addWidget(minBox);

        avgBox = new QCheckBox(centralwidget);
        avgBox->setObjectName(QStringLiteral("avgBox"));

        verticalLayout_3->addWidget(avgBox);

        verticalSpacer_3 = new QSpacerItem(20, 73, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_3->addItem(verticalSpacer_3);


        horizontalLayout_2->addLayout(verticalLayout_3);


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

        gridLayout->addWidget(yearButton, 0, 0, 1, 1);

        monthButton = new QPushButton(centralwidget);
        monthButton->setObjectName(QStringLiteral("monthButton"));

        gridLayout->addWidget(monthButton, 0, 1, 1, 1);

        weekButton = new QPushButton(centralwidget);
        weekButton->setObjectName(QStringLiteral("weekButton"));

        gridLayout->addWidget(weekButton, 1, 0, 1, 1);

        dayButton = new QPushButton(centralwidget);
        dayButton->setObjectName(QStringLiteral("dayButton"));

        gridLayout->addWidget(dayButton, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        timeButton = new QPushButton(centralwidget);
        timeButton->setObjectName(QStringLiteral("timeButton"));

        verticalLayout->addWidget(timeButton);

        verticalSpacer_9 = new QSpacerItem(40, 10, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer_9);

        line = new QFrame(centralwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

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
        menubar->setGeometry(QRect(0, 0, 1003, 20));
        menuWindow = new QMenu(menubar);
        menuWindow->setObjectName(QStringLiteral("menuWindow"));
        ChartWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ChartWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ChartWindow->setStatusBar(statusbar);

        menubar->addAction(menuWindow->menuAction());
        menuWindow->addAction(actionNewWindow);
        menuWindow->addAction(actionChooseLoadout);
        menuWindow->addAction(actionSaveLoadout);
        menuWindow->addSeparator();
        menuWindow->addAction(actionSettings);
        menuWindow->addAction(actionCloseWindow);

        retranslateUi(ChartWindow);

        stackedBoxes->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ChartWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ChartWindow)
    {
        ChartWindow->setWindowTitle(QApplication::translate("ChartWindow", "ChartWindow", Q_NULLPTR));
        actionNewWindow->setText(QApplication::translate("ChartWindow", "New Window", Q_NULLPTR));
        actionChooseLoadout->setText(QApplication::translate("ChartWindow", "Choose Loadout", Q_NULLPTR));
        actionSaveLoadout->setText(QApplication::translate("ChartWindow", "Save Loadout", Q_NULLPTR));
        actionSettings->setText(QApplication::translate("ChartWindow", "Settings", Q_NULLPTR));
        actionCloseWindow->setText(QApplication::translate("ChartWindow", "Close Window", Q_NULLPTR));
        databaseCombo->clear();
        databaseCombo->insertItems(0, QStringList()
         << QApplication::translate("ChartWindow", "STATFI", Q_NULLPTR)
         << QApplication::translate("ChartWindow", "SMEAR", Q_NULLPTR)
        );
        stationCombo->clear();
        stationCombo->insertItems(0, QStringList()
         << QApplication::translate("ChartWindow", "Measuring Station 1", Q_NULLPTR)
         << QApplication::translate("ChartWindow", "Measuring Station 2", Q_NULLPTR)
         << QApplication::translate("ChartWindow", "Measuring Station 3", Q_NULLPTR)
         << QApplication::translate("ChartWindow", "Measuring Station 4", Q_NULLPTR)
        );
        gasesLabel->setText(QApplication::translate("ChartWindow", "Gases", Q_NULLPTR));
        co2Box->setText(QApplication::translate("ChartWindow", "CO2", Q_NULLPTR));
        so2Box->setText(QApplication::translate("ChartWindow", "SO2", Q_NULLPTR));
        noxBox->setText(QApplication::translate("ChartWindow", "NOx", Q_NULLPTR));
        otherBox->setText(QApplication::translate("ChartWindow", "Other", Q_NULLPTR));
        datasetsLabel->setText(QApplication::translate("ChartWindow", "CO2 Data sets", Q_NULLPTR));
        co2DataRadio->setText(QApplication::translate("ChartWindow", "CO2", Q_NULLPTR));
        intensityRadio->setText(QApplication::translate("ChartWindow", "Intensity", Q_NULLPTR));
        indexedRadio->setText(QApplication::translate("ChartWindow", "Indexed", Q_NULLPTR));
        indexedIntensityRadio->setText(QApplication::translate("ChartWindow", "Indexed\n"
"Intentisy", Q_NULLPTR));
        additionalLabel->setText(QApplication::translate("ChartWindow", "Additional data", Q_NULLPTR));
        maxBox->setText(QApplication::translate("ChartWindow", "Maximum", Q_NULLPTR));
        minBox->setText(QApplication::translate("ChartWindow", "Minimum", Q_NULLPTR));
        avgBox->setText(QApplication::translate("ChartWindow", "Average", Q_NULLPTR));
        yearButton->setText(QApplication::translate("ChartWindow", "Year", Q_NULLPTR));
        monthButton->setText(QApplication::translate("ChartWindow", "Month", Q_NULLPTR));
        weekButton->setText(QApplication::translate("ChartWindow", "Week", Q_NULLPTR));
        dayButton->setText(QApplication::translate("ChartWindow", "24h", Q_NULLPTR));
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
