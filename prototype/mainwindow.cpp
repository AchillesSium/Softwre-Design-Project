#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize the chart
    QChart *graph = new QChart();
    graph->setTitle("Gasses in your environment");

    // Initialize the X-axis
    QValueAxis *axis_x = new QValueAxis();
    axis_x->setRange(0, 24);
    axis_x->setTickCount(24);
    axis_x->setGridLineVisible(true);
    axis_x->setLabelFormat("%.1i");
    axis_x->setTitleText("Hours");
    current_time = Day;

    // Initialize the Y-axis
    QValueAxis *axis_y = new QValueAxis();
    axis_y->setRange(0, 2000);
    axis_y->setTickCount(9);
    axis_y->setGridLineVisible(true);
    axis_y->setLabelFormat("%.1i");
    axis_y->setTitleText("ppm");

    // Add axis to the graph
    graph->addAxis(axis_x, Qt::AlignBottom);
    graph->addAxis(axis_y, Qt::AlignLeft);

    // Initialize the lines
    QtCharts::QLineSeries *co2_day_series = new QtCharts::QLineSeries(graph);
    QtCharts::QLineSeries *co2_week_series = new QtCharts::QLineSeries(graph);
    QtCharts::QLineSeries *co2_month_series = new QtCharts::QLineSeries(graph);
    QtCharts::QLineSeries *co2_year_series = new QtCharts::QLineSeries(graph);

    QtCharts::QLineSeries *so2_day_series = new QtCharts::QLineSeries(graph);
    QtCharts::QLineSeries *so2_week_series = new QtCharts::QLineSeries(graph);
    QtCharts::QLineSeries *so2_month_series = new QtCharts::QLineSeries(graph);
    QtCharts::QLineSeries *so2_year_series = new QtCharts::QLineSeries(graph);

    QtCharts::QLineSeries *nox_day_series = new QtCharts::QLineSeries(graph);
    QtCharts::QLineSeries *nox_week_series = new QtCharts::QLineSeries(graph);
    QtCharts::QLineSeries *nox_month_series = new QtCharts::QLineSeries(graph);
    QtCharts::QLineSeries *nox_year_series = new QtCharts::QLineSeries(graph);

    // Adding lines to the vectors
    co2_series.push_back(co2_day_series);
    co2_series.push_back(co2_week_series);
    co2_series.push_back(co2_month_series);
    co2_series.push_back(co2_year_series);

    so2_series.push_back(so2_day_series);
    so2_series.push_back(so2_week_series);
    so2_series.push_back(so2_month_series);
    so2_series.push_back(so2_year_series);

    nox_series.push_back(nox_day_series);
    nox_series.push_back(nox_week_series);
    nox_series.push_back(nox_month_series);
    nox_series.push_back(nox_year_series);

    // Fill lines with data
    make_chart_line(time_day, co2_day, co2_day_series);
    make_chart_line(time_week, co2_week, co2_week_series);
    make_chart_line(time_month, co2_month, co2_month_series);
    make_chart_line(time_year, co2_year, co2_year_series);

    make_chart_line(time_day, so2_day, so2_day_series);
    make_chart_line(time_week, so2_week, so2_week_series);
    make_chart_line(time_month, so2_month, so2_month_series);
    make_chart_line(time_year, so2_year, so2_year_series);

    make_chart_line(time_day, nox_day, nox_day_series);
    make_chart_line(time_week, nox_week, nox_week_series);
    make_chart_line(time_month, nox_month, nox_month_series);
    make_chart_line(time_year, nox_year, nox_year_series);

    // Add series to chart
    graph->addSeries(co2_day_series);
    graph->addSeries(so2_day_series);
    graph->addSeries(nox_day_series);

    // Attach series to axis
    co2_day_series->attachAxis(axis_x);
    co2_day_series->attachAxis(axis_y);

    so2_day_series->attachAxis(axis_x);
    so2_day_series->attachAxis(axis_y);

    nox_day_series->attachAxis(axis_x);
    nox_day_series->attachAxis(axis_y);

    // Initialize the chart view
    ui->chart_main_view->setChart(graph);
    ui->chart_main_view->setRenderHint(QPainter::Antialiasing);

    // Checking Checkboxes and blocking signals to avoid problems
    ui->co2_main_check->blockSignals(true);
    ui->so2_main_check->blockSignals(true);
    ui->nox_main_check->blockSignals(true);

    ui->co2_main_check->setChecked(true);
    ui->so2_main_check->setChecked(true);
    ui->nox_main_check->setChecked(true);

    ui->co2_main_check->blockSignals(false);
    ui->so2_main_check->blockSignals(false);
    ui->nox_main_check->blockSignals(false);

}

MainWindow::~MainWindow()
{
    // Deleting every pointer created with the "new" command

    delete co2_day_series;
    delete co2_week_series;
    delete co2_month_series;
    delete co2_year_series;

    delete so2_day_series;
    delete so2_week_series;
    delete so2_month_series;
    delete so2_year_series;

    delete nox_day_series;
    delete nox_week_series;
    delete nox_month_series;
    delete nox_year_series;

    delete axis_x;
    delete axis_y;

    delete graph;

    delete ui;
}


//----------------------------------------------------------------------------------------------
// Initialization

void MainWindow::make_chart_line(const std::vector<int> &x_axis,
                                 const std::vector<int> &y_axis,
                                 QtCharts::QLineSeries *chart_line)
{
    unsigned int axis_length = x_axis.size();

    if(axis_length == y_axis.size())
    {
        for(unsigned int point = 0 ; point < axis_length ; point++)
        {
            chart_line->append(x_axis.at(point), y_axis.at(point));
        }
    }
}


//----------------------------------------------------------------------------------------------
// Default functions

void MainWindow::default_combo_boxes()
{
    // Sets the comboboxes to the first index
    ui->data_main_combo->setCurrentIndex(0);
    ui->station_main_combo->setCurrentIndex(0);
}

void MainWindow::default_check_boxes()
{
    // Gasses checked
    ui->co2_main_check->setChecked(true);
    ui->so2_main_check->setChecked(true);
    ui->nox_main_check->setChecked(true);
    ui->other_main_check->setChecked(false);

    // Min, max, average unchecked
    ui->max_main_check->setChecked(false);
    ui->min_main_check->setChecked(false);
    ui->avg_main_check->setChecked(false);
}


//----------------------------------------------------------------------------------------------
// Chart functions

void MainWindow::remove_graph_series(QtCharts::QLineSeries *old_series)
{
    ui->chart_main_view->chart()->removeSeries(old_series);

}

void MainWindow::add_graph_series(QtCharts::QLineSeries *new_series)
{
    ui->chart_main_view->chart()->addSeries(new_series);
}

void MainWindow::react_to_checkbox(int check, std::vector<QtCharts::QLineSeries *> &pointers)
{
    if(check == 2)
    {
       add_graph_series(pointers.at(current_time));
    }
    else // if false
    {
        remove_graph_series(pointers.at(current_time));
    }
}

void MainWindow::quick_time_change(Time period)
{

    if(current_time == period)
    {
        return;
    }

    if(ui->co2_main_check->isChecked())
    {
        remove_graph_series(co2_series.at(current_time));
    }

    if(ui->so2_main_check->isChecked())
    {
        remove_graph_series(so2_series.at(current_time));
    }

    if(ui->nox_main_check->isChecked())
    {
        remove_graph_series(nox_series.at(current_time));
    }

    ui->chart_main_view->chart()->removeAxis(ui->chart_main_view->chart()->axisX());
    axis_x = new QValueAxis();
    int max_tick;
    QString title_text;

    switch(period)
    {
    case Day:
        max_tick = 24;
        title_text = "Hours";
        break;

    case Week:
        max_tick = 7;
        title_text = "Days";
        break;

    case Month:
        max_tick = 30;
        title_text = "Days";
        break;

    case Year:
        max_tick = 12;
        title_text = "Months";
        break;
    }

    axis_x->setMax(max_tick);
    axis_x->setTickCount(max_tick);
    axis_x->setTitleText(title_text);
    axis_x->setGridLineVisible(true);
    axis_x->setLabelFormat("%.1i");
    ui->chart_main_view->chart()->addAxis(axis_x, Qt::AlignBottom);
    current_time = period;

    if(ui->co2_main_check->isChecked())
    {
        add_graph_series(co2_series.at(current_time));
    }

    if(ui->so2_main_check->isChecked())
    {
        add_graph_series(so2_series.at(current_time));
    }

    if(ui->nox_main_check->isChecked())
    {
        add_graph_series(nox_series.at(current_time));
    }
}


//==============================================================================================
//SLOTS

//----------------------------------------------------------------------------------------------
// Button slots

void MainWindow::on_exit_main_button_clicked()
{
    this->close();
}

void MainWindow::on_default_main_button_clicked()
{
    default_combo_boxes();
    default_check_boxes();
}


void MainWindow::on_settings_main_button_clicked()
{
    settingsWindow *settings = new settingsWindow();
    settings->setModal(true);
    settings->show();
}

void MainWindow::on_compare_button_clicked()
{
    MainWindow *history = new MainWindow();
    history->show();
}

void MainWindow::on_date_to_main_button_clicked()
{
    date_to_date *date = new date_to_date();
    date->setModal(true);
    date->change_data(ui->data_main_combo->currentText());
    date->show();
}


void MainWindow::on_day_main_button_clicked()
{
    quick_time_change(Day);
}

void MainWindow::on_week_main_button_clicked()
{
    quick_time_change(Week);
}

void MainWindow::on_month_main_button_clicked()
{
    quick_time_change(Month);
}

void MainWindow::on_year_main_button_clicked()
{
    quick_time_change(Year);
}


//----------------------------------------------------------------------------------------------
// Combo and Check box slots

void MainWindow::on_data_main_combo_currentTextChanged(const QString &arg1)
{
    default_check_boxes();

    bool min_max;
    bool quick_times;
    QString button_text;

    if(arg1 == "SMEAR")
    {
        min_max = true;
        quick_times = true;
        button_text = "Date-to-Date";
    }

    else // if "STATFI"
    {
        min_max = false;
        quick_times = false;
        button_text = "Year-to_Year";
    }

    //Max, min and average
    ui->max_main_check->setEnabled(min_max);
    ui->min_main_check->setEnabled(min_max);
    ui->avg_main_check->setEnabled(min_max);

    //Quick time selection buttons
    ui->year_main_button->setEnabled(quick_times);
    ui->month_main_button->setEnabled(quick_times);
    ui->week_main_button->setEnabled(quick_times);
    ui->day_main_button->setEnabled(quick_times);

    //Specific time period button changed
    ui->date_to_main_button->setText(button_text);
}


void MainWindow::on_co2_main_check_stateChanged(int arg1)
{
    react_to_checkbox(arg1, co2_series);
}

void MainWindow::on_so2_main_check_stateChanged(int arg2)
{
react_to_checkbox(arg2, so2_series);
}

void MainWindow::on_nox_main_check_stateChanged(int arg3)
{
react_to_checkbox(arg3, nox_series);
}
