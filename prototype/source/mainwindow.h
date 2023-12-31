#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"settingswindow.h"
#include "date_to_date.h"

#include <QMainWindow>
#include <QString>
#include <QChart>
#include <QLineSeries>
#include <QValueAxis>
#include <vector>

enum Time {Day = 0, Week = 1, Month = 2, Year = 3};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Initialization
    void make_chart_line(const std::vector<int> &x_axis, const std::vector<int> &y_axis, QtCharts::QLineSeries *chart_line);

    // Default functions
    void default_combo_boxes();
    void default_check_boxes();

    // Chart functions
    void remove_graph_series(QtCharts::QLineSeries *old_series);
    void add_graph_series(QtCharts::QLineSeries *new_series);
    void react_to_checkbox(int check, std::vector<QtCharts::QLineSeries*> &pointers);
    void quick_time_change(Time period);

private slots:

    // Button slots
    void on_exit_main_button_clicked();
    void on_default_main_button_clicked();

    void on_settings_main_button_clicked();
    void on_compare_button_clicked();
    void on_date_to_main_button_clicked();

    void on_day_main_button_clicked();
    void on_week_main_button_clicked();
    void on_month_main_button_clicked();
    void on_year_main_button_clicked();

    // Combo box slots
    void on_data_main_combo_currentTextChanged(const QString &arg1);

    void on_co2_main_check_stateChanged(int arg1);
    void on_so2_main_check_stateChanged(int arg2);
    void on_nox_main_check_stateChanged(int arg3);

private:

    // Additional windows
    Ui::MainWindow *ui;
    settingsWindow *settings;
    MainWindow *history;
    date_to_date *date;


    // Chart elemnets

        // Enum to clarify timescale of the graph
        Time current_time;

        // CO2 series
        QtCharts::QLineSeries *co2_day_series;
        QtCharts::QLineSeries *co2_week_series;
        QtCharts::QLineSeries *co2_month_series;
        QtCharts::QLineSeries *co2_year_series;

        // SO2 series
        QtCharts::QLineSeries *so2_day_series;
        QtCharts::QLineSeries *so2_week_series;
        QtCharts::QLineSeries *so2_month_series;
        QtCharts::QLineSeries *so2_year_series;

        // NOx series
        QtCharts::QLineSeries *nox_day_series;
        QtCharts::QLineSeries *nox_week_series;
        QtCharts::QLineSeries *nox_month_series;
        QtCharts::QLineSeries *nox_year_series;

        std::vector<QtCharts::QLineSeries*> co2_series;
        std::vector<QtCharts::QLineSeries*> so2_series;
        std::vector<QtCharts::QLineSeries*> nox_series;

        // Chart
        QtCharts::QChart *graph;

        // Axis
        QtCharts::QValueAxis *axis_x;
        QtCharts::QValueAxis *axis_y;
        int max_tick;


    // Chart data elements

        // Time values
        const std::vector<int> time_day = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};
        const std::vector<int> time_week = {1, 2, 3, 4, 5, 6, 7};
        const std::vector<int> time_month = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30};
        const std::vector<int> time_year = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

        // CO2 values
        const std::vector<int> co2_day = {1407, 1506, 1111, 363, 758, 1541, 1980, 656, 919, 1913, 1494, 1103, 946, 1762, 553, 1217, 609, 1369, 595, 790, 751, 305, 1590, 470};
        const std::vector<int> co2_week = {1761, 1941, 368, 1584, 951, 769, 1126};
        const std::vector<int> co2_month = {1458, 856, 755, 1322, 1387, 535, 322, 1269, 1125, 1283, 1472, 1536, 785, 473, 1274, 1405, 1063, 1865, 1837, 743, 939, 449, 1816, 1890, 440, 391, 423, 1388, 713, 421};
        const std::vector<int> co2_year = {1119, 693, 971, 1955, 624, 329, 1818, 1925, 1410, 977, 780, 1488};

        // SO2 values
        const std::vector<int> so2_day = {724, 315, 952, 177, 1400, 924, 309, 1248, 980, 1338, 353, 916, 763, 998, 568, 275, 1438, 533, 1071, 1121, 945, 1465, 1329, 1485};
        const std::vector<int> so2_week = {156, 212, 1044, 1077, 210, 613, 511};
        const std::vector<int> so2_month = {1381, 871, 1412, 607, 1043, 1382, 790, 773, 1330, 1105, 756, 490, 1076, 1490, 1205, 835, 356, 1467, 970, 584, 445, 725, 280, 1223, 1232, 730, 242, 914, 338, 876};
        const std::vector<int> so2_year = {1317, 1124, 783, 923, 1174, 1480, 913, 1481, 1176, 691, 1009, 769};

        // NOx values
        const std::vector<int> nox_day = {878, 736, 635, 764, 852, 1118, 834, 1149, 1054, 1157, 977, 803, 879, 978, 638, 1074, 898, 608, 658, 1392, 1002, 780, 999, 1542};
        const std::vector<int> nox_week = {1152, 759, 1547, 1520, 680, 1246, 1571};
        const std::vector<int> nox_month = {1003, 960, 1315, 704, 636, 981, 653, 1674, 1424, 1664, 1471, 1196, 1683, 1747, 1638, 1614, 1581, 1710, 1409, 1609, 1129, 637, 888, 892, 842, 1516, 1420, 1070, 1016, 1491};
        const std::vector<int> nox_year = {1473, 1502, 1215, 1267, 742, 1115, 1071, 804, 1387, 708, 1708, 1231};


};
#endif // MAINWINDOW_H
