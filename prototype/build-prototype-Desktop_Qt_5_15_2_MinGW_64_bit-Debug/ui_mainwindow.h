/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
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
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 641);
        action_PDF = new QAction(MainWindow);
        action_PDF->setObjectName(QString::fromUtf8("action_PDF"));
        action_PNG = new QAction(MainWindow);
        action_PNG->setObjectName(QString::fromUtf8("action_PNG"));
        action_JPEG = new QAction(MainWindow);
        action_JPEG->setObjectName(QString::fromUtf8("action_JPEG"));
        actionSave_loadout = new QAction(MainWindow);
        actionSave_loadout->setObjectName(QString::fromUtf8("actionSave_loadout"));
        actionCompare = new QAction(MainWindow);
        actionCompare->setObjectName(QString::fromUtf8("actionCompare"));
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        actionDefault_loadout = new QAction(MainWindow);
        actionDefault_loadout->setObjectName(QString::fromUtf8("actionDefault_loadout"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        chart_main_view = new QChartView(centralwidget);
        chart_main_view->setObjectName(QString::fromUtf8("chart_main_view"));
        chart_main_view->setGeometry(QRect(20, 20, 981, 571));
        station_main_combo = new QComboBox(centralwidget);
        station_main_combo->addItem(QString());
        station_main_combo->addItem(QString());
        station_main_combo->addItem(QString());
        station_main_combo->setObjectName(QString::fromUtf8("station_main_combo"));
        station_main_combo->setGeometry(QRect(1020, 80, 161, 22));
        compare_button = new QPushButton(centralwidget);
        compare_button->setObjectName(QString::fromUtf8("compare_button"));
        compare_button->setGeometry(QRect(1030, 510, 141, 21));
        settings_main_button = new QPushButton(centralwidget);
        settings_main_button->setObjectName(QString::fromUtf8("settings_main_button"));
        settings_main_button->setGeometry(QRect(1030, 540, 141, 21));
        exit_main_button = new QPushButton(centralwidget);
        exit_main_button->setObjectName(QString::fromUtf8("exit_main_button"));
        exit_main_button->setGeometry(QRect(1030, 570, 141, 21));
        co2_main_check = new QCheckBox(centralwidget);
        co2_main_check->setObjectName(QString::fromUtf8("co2_main_check"));
        co2_main_check->setGeometry(QRect(1030, 170, 72, 19));
        so2_main_check = new QCheckBox(centralwidget);
        so2_main_check->setObjectName(QString::fromUtf8("so2_main_check"));
        so2_main_check->setGeometry(QRect(1030, 190, 72, 19));
        nox_main_check = new QCheckBox(centralwidget);
        nox_main_check->setObjectName(QString::fromUtf8("nox_main_check"));
        nox_main_check->setGeometry(QRect(1030, 210, 72, 19));
        other_main_check = new QCheckBox(centralwidget);
        other_main_check->setObjectName(QString::fromUtf8("other_main_check"));
        other_main_check->setGeometry(QRect(1030, 230, 61, 19));
        data_main_combo = new QComboBox(centralwidget);
        data_main_combo->addItem(QString());
        data_main_combo->addItem(QString());
        data_main_combo->setObjectName(QString::fromUtf8("data_main_combo"));
        data_main_combo->setGeometry(QRect(1020, 50, 161, 22));
        default_main_button = new QPushButton(centralwidget);
        default_main_button->setObjectName(QString::fromUtf8("default_main_button"));
        default_main_button->setGeometry(QRect(1030, 480, 141, 21));
        month_main_button = new QPushButton(centralwidget);
        month_main_button->setObjectName(QString::fromUtf8("month_main_button"));
        month_main_button->setGeometry(QRect(1030, 330, 141, 21));
        day_main_button = new QPushButton(centralwidget);
        day_main_button->setObjectName(QString::fromUtf8("day_main_button"));
        day_main_button->setGeometry(QRect(1030, 390, 141, 21));
        week_main_button = new QPushButton(centralwidget);
        week_main_button->setObjectName(QString::fromUtf8("week_main_button"));
        week_main_button->setGeometry(QRect(1030, 360, 141, 21));
        date_to_main_button = new QPushButton(centralwidget);
        date_to_main_button->setObjectName(QString::fromUtf8("date_to_main_button"));
        date_to_main_button->setGeometry(QRect(1030, 420, 141, 21));
        year_main_button = new QPushButton(centralwidget);
        year_main_button->setObjectName(QString::fromUtf8("year_main_button"));
        year_main_button->setGeometry(QRect(1030, 300, 141, 21));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(1020, 450, 161, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        gas_main_label = new QLabel(centralwidget);
        gas_main_label->setObjectName(QString::fromUtf8("gas_main_label"));
        gas_main_label->setGeometry(QRect(1030, 150, 47, 13));
        data_main_label = new QLabel(centralwidget);
        data_main_label->setObjectName(QString::fromUtf8("data_main_label"));
        data_main_label->setGeometry(QRect(1100, 150, 81, 16));
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(1080, 130, 16, 131));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        min_main_check = new QCheckBox(centralwidget);
        min_main_check->setObjectName(QString::fromUtf8("min_main_check"));
        min_main_check->setGeometry(QRect(1110, 200, 72, 19));
        max_main_check = new QCheckBox(centralwidget);
        max_main_check->setObjectName(QString::fromUtf8("max_main_check"));
        max_main_check->setGeometry(QRect(1110, 180, 72, 19));
        avg_main_check = new QCheckBox(centralwidget);
        avg_main_check->setObjectName(QString::fromUtf8("avg_main_check"));
        avg_main_check->setGeometry(QRect(1110, 220, 72, 19));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 20));
        menuWeather_Report = new QMenu(menubar);
        menuWeather_Report->setObjectName(QString::fromUtf8("menuWeather_Report"));
        menuExport = new QMenu(menuWeather_Report);
        menuExport->setObjectName(QString::fromUtf8("menuExport"));
        menuChoose_loadout = new QMenu(menuWeather_Report);
        menuChoose_loadout->setObjectName(QString::fromUtf8("menuChoose_loadout"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
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
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action_PDF->setText(QCoreApplication::translate("MainWindow", ".pdf", nullptr));
        action_PNG->setText(QCoreApplication::translate("MainWindow", ".PNG", nullptr));
        action_JPEG->setText(QCoreApplication::translate("MainWindow", ".JPEG", nullptr));
        actionSave_loadout->setText(QCoreApplication::translate("MainWindow", "Save loadout", nullptr));
        actionCompare->setText(QCoreApplication::translate("MainWindow", "Compare", nullptr));
        actionSettings->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        actionDefault_loadout->setText(QCoreApplication::translate("MainWindow", "Default loadout", nullptr));
        station_main_combo->setItemText(0, QCoreApplication::translate("MainWindow", "MeasuringStation1", nullptr));
        station_main_combo->setItemText(1, QCoreApplication::translate("MainWindow", "MeasuringStation2", nullptr));
        station_main_combo->setItemText(2, QCoreApplication::translate("MainWindow", "MeasuringStation3", nullptr));

        compare_button->setText(QCoreApplication::translate("MainWindow", "Compare", nullptr));
        settings_main_button->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        exit_main_button->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        co2_main_check->setText(QCoreApplication::translate("MainWindow", "CO2", nullptr));
        so2_main_check->setText(QCoreApplication::translate("MainWindow", "SO2", nullptr));
        nox_main_check->setText(QCoreApplication::translate("MainWindow", "NOx", nullptr));
        other_main_check->setText(QCoreApplication::translate("MainWindow", "(other)", nullptr));
        data_main_combo->setItemText(0, QCoreApplication::translate("MainWindow", "SMEAR", nullptr));
        data_main_combo->setItemText(1, QCoreApplication::translate("MainWindow", "STATFI", nullptr));

        default_main_button->setText(QCoreApplication::translate("MainWindow", "Default loadout", nullptr));
        month_main_button->setText(QCoreApplication::translate("MainWindow", "Month", nullptr));
        day_main_button->setText(QCoreApplication::translate("MainWindow", "24h", nullptr));
        week_main_button->setText(QCoreApplication::translate("MainWindow", "Week", nullptr));
        date_to_main_button->setText(QCoreApplication::translate("MainWindow", "Date-to-Date", nullptr));
        year_main_button->setText(QCoreApplication::translate("MainWindow", "Year", nullptr));
        gas_main_label->setText(QCoreApplication::translate("MainWindow", "Gas:", nullptr));
        data_main_label->setText(QCoreApplication::translate("MainWindow", "Additional data:", nullptr));
        min_main_check->setText(QCoreApplication::translate("MainWindow", "min.", nullptr));
        max_main_check->setText(QCoreApplication::translate("MainWindow", "max.", nullptr));
        avg_main_check->setText(QCoreApplication::translate("MainWindow", "avg.", nullptr));
        menuWeather_Report->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuExport->setTitle(QCoreApplication::translate("MainWindow", "Export data", nullptr));
        menuChoose_loadout->setTitle(QCoreApplication::translate("MainWindow", "Choose loadout", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
