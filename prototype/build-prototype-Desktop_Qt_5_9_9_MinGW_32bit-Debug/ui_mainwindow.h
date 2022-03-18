/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "QtCharts"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_PDF;
    QAction *action_PNG;
    QAction *action_JPEG;
    QAction *actionSave_loadout;
    QAction *actionCompare;
    QAction *actionSettings;
    QAction *actionDefault_loadout;
    QWidget *centralwidget;
    QChartView *chart_main_view;
    QComboBox *station_main_combo;
    QPushButton *compare_button;
    QPushButton *settings_main_button;
    QPushButton *exit_main_button;
    QCheckBox *co2_main_check;
    QCheckBox *so2_main_check;
    QCheckBox *nox_main_check;
    QCheckBox *other_main_check;
    QComboBox *data_main_combo;
    QPushButton *default_main_button;
    QPushButton *month_main_button;
    QPushButton *day_main_button;
    QPushButton *week_main_button;
    QPushButton *date_to_main_button;
    QPushButton *year_main_button;
    QFrame *line;
    QLabel *gas_main_label;
    QLabel *data_main_label;
    QFrame *line_2;
    QCheckBox *min_main_check;
    QCheckBox *max_main_check;
    QCheckBox *avg_main_check;
    QMenuBar *menubar;
    QMenu *menuWeather_Report;
    QMenu *menuExport;
    QMenu *menuChoose_loadout;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1200, 641);
        action_PDF = new QAction(MainWindow);
        action_PDF->setObjectName(QStringLiteral("action_PDF"));
        action_PNG = new QAction(MainWindow);
        action_PNG->setObjectName(QStringLiteral("action_PNG"));
        action_JPEG = new QAction(MainWindow);
        action_JPEG->setObjectName(QStringLiteral("action_JPEG"));
        actionSave_loadout = new QAction(MainWindow);
        actionSave_loadout->setObjectName(QStringLiteral("actionSave_loadout"));
        actionCompare = new QAction(MainWindow);
        actionCompare->setObjectName(QStringLiteral("actionCompare"));
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        actionDefault_loadout = new QAction(MainWindow);
        actionDefault_loadout->setObjectName(QStringLiteral("actionDefault_loadout"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        chart_main_view = new QChartView(centralwidget);
        chart_main_view->setObjectName(QStringLiteral("chart_main_view"));
        chart_main_view->setGeometry(QRect(20, 20, 981, 571));
        station_main_combo = new QComboBox(centralwidget);
        station_main_combo->setObjectName(QStringLiteral("station_main_combo"));
        station_main_combo->setGeometry(QRect(1020, 80, 161, 22));
        compare_button = new QPushButton(centralwidget);
        compare_button->setObjectName(QStringLiteral("compare_button"));
        compare_button->setGeometry(QRect(1030, 510, 141, 21));
        settings_main_button = new QPushButton(centralwidget);
        settings_main_button->setObjectName(QStringLiteral("settings_main_button"));
        settings_main_button->setGeometry(QRect(1030, 540, 141, 21));
        exit_main_button = new QPushButton(centralwidget);
        exit_main_button->setObjectName(QStringLiteral("exit_main_button"));
        exit_main_button->setGeometry(QRect(1030, 570, 141, 21));
        co2_main_check = new QCheckBox(centralwidget);
        co2_main_check->setObjectName(QStringLiteral("co2_main_check"));
        co2_main_check->setGeometry(QRect(1030, 170, 72, 19));
        so2_main_check = new QCheckBox(centralwidget);
        so2_main_check->setObjectName(QStringLiteral("so2_main_check"));
        so2_main_check->setGeometry(QRect(1030, 190, 72, 19));
        nox_main_check = new QCheckBox(centralwidget);
        nox_main_check->setObjectName(QStringLiteral("nox_main_check"));
        nox_main_check->setGeometry(QRect(1030, 210, 72, 19));
        other_main_check = new QCheckBox(centralwidget);
        other_main_check->setObjectName(QStringLiteral("other_main_check"));
        other_main_check->setGeometry(QRect(1030, 230, 61, 19));
        data_main_combo = new QComboBox(centralwidget);
        data_main_combo->setObjectName(QStringLiteral("data_main_combo"));
        data_main_combo->setGeometry(QRect(1020, 50, 161, 22));
        default_main_button = new QPushButton(centralwidget);
        default_main_button->setObjectName(QStringLiteral("default_main_button"));
        default_main_button->setGeometry(QRect(1030, 480, 141, 21));
        month_main_button = new QPushButton(centralwidget);
        month_main_button->setObjectName(QStringLiteral("month_main_button"));
        month_main_button->setGeometry(QRect(1030, 330, 141, 21));
        day_main_button = new QPushButton(centralwidget);
        day_main_button->setObjectName(QStringLiteral("day_main_button"));
        day_main_button->setGeometry(QRect(1030, 390, 141, 21));
        week_main_button = new QPushButton(centralwidget);
        week_main_button->setObjectName(QStringLiteral("week_main_button"));
        week_main_button->setGeometry(QRect(1030, 360, 141, 21));
        date_to_main_button = new QPushButton(centralwidget);
        date_to_main_button->setObjectName(QStringLiteral("date_to_main_button"));
        date_to_main_button->setGeometry(QRect(1030, 420, 141, 21));
        year_main_button = new QPushButton(centralwidget);
        year_main_button->setObjectName(QStringLiteral("year_main_button"));
        year_main_button->setGeometry(QRect(1030, 300, 141, 21));
        line = new QFrame(centralwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(1020, 450, 161, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        gas_main_label = new QLabel(centralwidget);
        gas_main_label->setObjectName(QStringLiteral("gas_main_label"));
        gas_main_label->setGeometry(QRect(1030, 150, 47, 13));
        data_main_label = new QLabel(centralwidget);
        data_main_label->setObjectName(QStringLiteral("data_main_label"));
        data_main_label->setGeometry(QRect(1100, 150, 81, 16));
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(1080, 130, 16, 131));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        min_main_check = new QCheckBox(centralwidget);
        min_main_check->setObjectName(QStringLiteral("min_main_check"));
        min_main_check->setGeometry(QRect(1110, 200, 72, 19));
        max_main_check = new QCheckBox(centralwidget);
        max_main_check->setObjectName(QStringLiteral("max_main_check"));
        max_main_check->setGeometry(QRect(1110, 180, 72, 19));
        avg_main_check = new QCheckBox(centralwidget);
        avg_main_check->setObjectName(QStringLiteral("avg_main_check"));
        avg_main_check->setGeometry(QRect(1110, 220, 72, 19));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 20));
        menuWeather_Report = new QMenu(menubar);
        menuWeather_Report->setObjectName(QStringLiteral("menuWeather_Report"));
        menuExport = new QMenu(menuWeather_Report);
        menuExport->setObjectName(QStringLiteral("menuExport"));
        menuChoose_loadout = new QMenu(menuWeather_Report);
        menuChoose_loadout->setObjectName(QStringLiteral("menuChoose_loadout"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuWeather_Report->menuAction());
        menuWeather_Report->addAction(menuExport->menuAction());
        menuWeather_Report->addSeparator();
        menuWeather_Report->addAction(actionSave_loadout);
        menuWeather_Report->addAction(menuChoose_loadout->menuAction());
        menuWeather_Report->addSeparator();
        menuWeather_Report->addAction(actionSettings);
        menuExport->addAction(action_PDF);
        menuExport->addAction(action_PNG);
        menuExport->addAction(action_JPEG);
        menuChoose_loadout->addAction(actionDefault_loadout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        action_PDF->setText(QApplication::translate("MainWindow", ".pdf", Q_NULLPTR));
        action_PNG->setText(QApplication::translate("MainWindow", ".PNG", Q_NULLPTR));
        action_JPEG->setText(QApplication::translate("MainWindow", ".JPEG", Q_NULLPTR));
        actionSave_loadout->setText(QApplication::translate("MainWindow", "Save loadout", Q_NULLPTR));
        actionCompare->setText(QApplication::translate("MainWindow", "Compare", Q_NULLPTR));
        actionSettings->setText(QApplication::translate("MainWindow", "Settings", Q_NULLPTR));
        actionDefault_loadout->setText(QApplication::translate("MainWindow", "Default loadout", Q_NULLPTR));
        station_main_combo->clear();
        station_main_combo->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "MeasuringStation1", Q_NULLPTR)
         << QApplication::translate("MainWindow", "MeasuringStation2", Q_NULLPTR)
         << QApplication::translate("MainWindow", "MeasuringStation3", Q_NULLPTR)
        );
        compare_button->setText(QApplication::translate("MainWindow", "Compare", Q_NULLPTR));
        settings_main_button->setText(QApplication::translate("MainWindow", "Settings", Q_NULLPTR));
        exit_main_button->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        co2_main_check->setText(QApplication::translate("MainWindow", "CO2", Q_NULLPTR));
        so2_main_check->setText(QApplication::translate("MainWindow", "SO2", Q_NULLPTR));
        nox_main_check->setText(QApplication::translate("MainWindow", "NOx", Q_NULLPTR));
        other_main_check->setText(QApplication::translate("MainWindow", "(other)", Q_NULLPTR));
        data_main_combo->clear();
        data_main_combo->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "SMEAR", Q_NULLPTR)
         << QApplication::translate("MainWindow", "STATFI", Q_NULLPTR)
        );
        default_main_button->setText(QApplication::translate("MainWindow", "Default loadout", Q_NULLPTR));
        month_main_button->setText(QApplication::translate("MainWindow", "Month", Q_NULLPTR));
        day_main_button->setText(QApplication::translate("MainWindow", "24h", Q_NULLPTR));
        week_main_button->setText(QApplication::translate("MainWindow", "Week", Q_NULLPTR));
        date_to_main_button->setText(QApplication::translate("MainWindow", "Date-to-Date", Q_NULLPTR));
        year_main_button->setText(QApplication::translate("MainWindow", "Year", Q_NULLPTR));
        gas_main_label->setText(QApplication::translate("MainWindow", "Gas:", Q_NULLPTR));
        data_main_label->setText(QApplication::translate("MainWindow", "Additional data:", Q_NULLPTR));
        min_main_check->setText(QApplication::translate("MainWindow", "min.", Q_NULLPTR));
        max_main_check->setText(QApplication::translate("MainWindow", "max.", Q_NULLPTR));
        avg_main_check->setText(QApplication::translate("MainWindow", "avg.", Q_NULLPTR));
        menuWeather_Report->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuExport->setTitle(QApplication::translate("MainWindow", "Export data", Q_NULLPTR));
        menuChoose_loadout->setTitle(QApplication::translate("MainWindow", "Choose loadout", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
