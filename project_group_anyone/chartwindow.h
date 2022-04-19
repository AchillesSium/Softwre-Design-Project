#ifndef CHARTWINDOW_H
#define CHARTWINDOW_H

#include "timewindow.h"
#include "userselections.h"

#include <QMainWindow>
#include <QString>
#include <QChart>
#include <QLineSeries>
#include <QValueAxis>
#include <QDateTime>
#include <QDateTimeAxis>
#include <QPen>
#include <vector>
#include <algorithm>
#include <memory>
#include <unordered_map>
#include <limits>


// Enum to clarify timescale of the graph
enum Time {Day = 0, Week = 1, Month = 2, Year = 3, Custom = 4, No_time = 5};

QT_BEGIN_NAMESPACE
namespace Ui { class ChartWindow; }
QT_END_NAMESPACE

class ChartWindow : public QMainWindow
{
    Q_OBJECT

public:
    ChartWindow(QWidget *parent = nullptr);
    ~ChartWindow();

    // Default functions
    void default_combo_boxes();
    void default_radio_buttons();
    void set_smear();
    void set_statfi();

    // Quality of life functions
    unsigned int round_to_nearest(double minmax);
    //QDateTime make_datetime(Date from_date);
    unsigned int largest_divider(unsigned int point_count);
    QtCharts::QDateTimeAxis* smear_axis(const std::vector<std::pair<double, QDateTime>> &filtered);

    // Chart functions
    void remove_all_graph_series();
    void react_to_selection(bool state, std::vector<QtCharts::QLineSeries*> &pointers);
    void quick_time_change(Time period);
    QList<QPointF> make_statfi_series(const std::vector<std::pair<int, double>> &filtered, unsigned int to_start, unsigned int to_end);
    QtCharts::QLineSeries* make_smear_series(const std::vector<std::pair<double, QDateTime>> &pre_series, unsigned int start, unsigned int ending);
    void display_statfi(const std::vector<std::pair<int, double>> &filtered);
    void display_smear(const std::vector<std::pair<double, QDateTime>> &filtered);

public slots:

    // TimeWindow slot
    void get_pair(std::pair<QString,QString> time_pair);

private slots:

    // Button slots
    void on_dayButton_clicked();
    void on_weekButton_clicked();
    void on_monthButton_clicked();
    void on_yearButton_clicked();
    void on_timeButton_clicked();
    void on_defaultButton_clicked();
    void on_applyButton_clicked();

    // Combo box slots
    void on_databaseCombo_currentIndexChanged(const QString current_database);
    void on_stationCombo_currentIndexChanged(const QString current_station);
    void on_aggregationCombo_currentIndexChanged(const QString current_aggregate);

    // SMEAR Radio Button slots
    void on_co2Radio_clicked(bool state);
    void on_so2Radio_clicked(bool state);
    void on_noxRadio_clicked(bool state);

    // STATFI Radio Button slots
    void on_co2DataRadio_clicked(bool state);
    void on_intensityRadio_clicked(bool state);
    void on_indexedRadio_clicked(bool state);
    void on_indexedIntensityRadio_clicked(bool state);

    // Menubar slots
    void on_actionNewWindow_triggered();
    void on_actionCloseWindow_triggered();

    // TODO?
    //void on_actionChooseLoadout_triggered();
    //void on_actionSaveLoadout_triggered();
    //void on_actionSettings_triggered();

private:
    Ui::ChartWindow *ui;
    ChartWindow *history;
    TimeWindow *date;

    // Struct for tracking the state of the view elements
    struct ViewObject
    {
        DataSource current_database;
        MeasuringStation current_station;
        DataSet radioselection_statfi;
        DataSet radioselection_smear;
        std::pair<QString, QString> selected_time; // From beginning date to end date
        AggregateType selected_aggregation;
    };

    std::shared_ptr<ViewObject> view_elements;

    Time selected_preset_time;


    // Chart elements

        // Chart
        QtCharts::QChart *graph;

        // Axis
        QtCharts::QValueAxis *axis_x;
        QtCharts::QValueAxis *axis_y;

        // Series pen
        QPen chart_pen = QPen(QBrush(QColor(204, 0, 0), Qt::SolidPattern), 3, Qt::SolidLine, Qt::RoundCap);

};
#endif // CHARTWINDOW_H
