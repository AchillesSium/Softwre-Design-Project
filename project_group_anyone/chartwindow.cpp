#include "chartwindow.h"
#include "ui_chartwindow.h"
#include "userselections.h"
#include "controller.h"
#include "date.h"
#include <QDebug>
#include <sstream>
#include <QString>

ChartWindow::ChartWindow(QWidget *parent) :
      QMainWindow(parent),
      ui(new Ui::ChartWindow),
      view_elements(new ViewObject)
{
    ui->setupUi(this);

    // Initialize the chart
    QtCharts::QChart *graph = new QtCharts::QChart();
    graph->setTitle("Gasses in your environment");

    // Initialize the X-axis
    QtCharts::QValueAxis *axis_x = new QtCharts::QValueAxis();
    axis_x->setRange(0, 24);
    axis_x->setTickCount(24);
    axis_x->setGridLineVisible(true);
    axis_x->setLabelFormat("%.1i");
    axis_x->setTitleText("Hours");
    view_elements->selected_preset_time = Day;

    // Initialize the Y-axis
    QtCharts::QValueAxis *axis_y = new QtCharts::QValueAxis();
    axis_y->setRange(0, 2000);
    axis_y->setTickCount(9);
    axis_y->setGridLineVisible(true);
    axis_y->setLabelFormat("%.1i");
    axis_y->setTitleText("Tonnes");

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

    // Initialize the chart view
    ui->chartView->setChart(graph);
    ui->chartView->setRenderHint(QPainter::Antialiasing);

    // Set correct combo box and stacked widget
    ui->databaseCombo->blockSignals(true);

    ui->databaseCombo->setCurrentText("SMEAR");
    view_elements->current_database = DataSource::SMEAR;
    ui->stackedBoxes->setCurrentIndex(0);
    view_elements->current_station = MeasuringStation::Varrio;
    view_elements->radioselection_smear = None;
    view_elements->radioselection_statfi = None;

    ui->databaseCombo->blockSignals(false);

}

ChartWindow::~ChartWindow()
{
    ui->chartView->chart()->removeAllSeries();
    delete ui;
}

//----------------------------------------------------------------------------------------------
// Initialization

void ChartWindow::make_chart_line(const std::vector<int> &x_axis,
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

void ChartWindow::default_combo_boxes()
{
    // Sets the comboboxes to the first index
    ui->databaseCombo->setCurrentIndex(0);
    ui->stationCombo->setCurrentIndex(0);
}

void ChartWindow::default_check_boxes()
{
    remove_all_graph_series();

    if(view_elements->current_database == DataSource::SMEAR)
    {
        // Uncheck the checked radio button
        switch(view_elements->radioselection_smear)
        {
        case CO2:
            ui->co2Radio->setAutoExclusive(false);
            ui->co2Radio->setChecked(false);
            ui->co2Radio->setAutoExclusive(true);
            break;

        case SO2:
            ui->so2Radio->setAutoExclusive(false);
            ui->so2Radio->setChecked(false);
            ui->so2Radio->setAutoExclusive(true);
            break;

        case NO:
            ui->noxRadio->setAutoExclusive(false);
            ui->noxRadio->setChecked(false);
            ui->noxRadio->setAutoExclusive(true);
            break;

        default:
            // Nothing needs to be done
            break;
        }
    }
    else if(view_elements->current_database == DataSource::STATFI)
    {
        // Uncheck the checked radio button
        switch(view_elements->radioselection_statfi)
        {
        case CO2tonnes:
            ui->co2DataRadio->setAutoExclusive(false);
            ui->co2DataRadio->setChecked(false);
            ui->co2DataRadio->setAutoExclusive(true);
            break;

        case CO2intensity:
            ui->intensityRadio->setAutoExclusive(false);
            ui->intensityRadio->setChecked(false);
            ui->intensityRadio->setAutoExclusive(true);
            break;

        case CO2indexed:
            ui->indexedRadio->setAutoExclusive(false);
            ui->indexedRadio->setChecked(false);
            ui->indexedRadio->setAutoExclusive(true);
            break;

        case CO2intensityIndexed:
            ui->indexedIntensityRadio->setAutoExclusive(false);
            ui->indexedIntensityRadio->setChecked(false);
            ui->indexedIntensityRadio->setAutoExclusive(true);
            break;

        default:
            // Nothing needs to be done
            break;
        }
        view_elements->radioselection_statfi = None;
        view_elements->radioselection_smear = None;
    }

    // Reset aggregation type
    ui->aggregationCombo->setCurrentIndex(0);
}



//----------------------------------------------------------------------------------------------
// Chart functions

void ChartWindow::remove_graph_series(QtCharts::QLineSeries *old_series)
{
    ui->chartView->chart()->removeSeries(old_series);

}

void ChartWindow::remove_all_graph_series()
{
    QList<QAbstractSeries*> all_series = ui->chartView->chart()->series();

    if(all_series.size() == 0)
    {
        return;
    }

    for(QAbstractSeries* pointer : qAsConst(all_series)) //qAsConst() makes the loop safer
    {
        ui->chartView->chart()->removeSeries(pointer);
    }
}

void ChartWindow::add_graph_series(QtCharts::QLineSeries *new_series)
{
    ui->chartView->chart()->addSeries(new_series);
}

void ChartWindow::react_to_selection(bool state, std::vector<QtCharts::QLineSeries *> &pointers)
{
    QtCharts::QAbstractSeries *current_pointer = pointers.at(view_elements->selected_preset_time);
    QList<QAbstractSeries*> all_series = ui->chartView->chart()->series();
    QList<QAbstractSeries*>::iterator all;

    all = std::find(all_series.begin(), all_series.end(), current_pointer);

    if(state == true && all == all_series.end())
    {
       add_graph_series(pointers.at(view_elements->selected_preset_time));
    }
    else if(state == false && all != all_series.end())
    {
        remove_graph_series(pointers.at(view_elements->selected_preset_time));
    }
}

void ChartWindow::quick_time_change(Time period)
{

    if(view_elements->selected_preset_time == period)
    {
        return;
    }


    switch(view_elements->radioselection_smear)
    {
    case CO2:
        remove_graph_series(co2_series.at(view_elements->selected_preset_time));
        break;

    case SO2:
        remove_graph_series(so2_series.at(view_elements->selected_preset_time));
        break;

    case NO:
        remove_graph_series(nox_series.at(view_elements->selected_preset_time));
        break;

    default:
        // Nothing needs to be done
        break;
    }

    ui->chartView->chart()->removeAxis(ui->chartView->chart()->axisX());
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

    default:
        max_tick = 10;
        title_text = "Years";
        break;
    }

    axis_x->setMax(max_tick);
    axis_x->setTickCount(max_tick);
    axis_x->setTitleText(title_text);
    axis_x->setGridLineVisible(true);
    axis_x->setLabelFormat("%.1i");
    ui->chartView->chart()->addAxis(axis_x, Qt::AlignBottom);
    view_elements->selected_preset_time = period;

    switch(view_elements->radioselection_smear)
    {
    case CO2:
        add_graph_series(co2_series.at(view_elements->selected_preset_time));
        break;

    case SO2:
        add_graph_series(so2_series.at(view_elements->selected_preset_time));
        break;

    case NO:
        add_graph_series(nox_series.at(view_elements->selected_preset_time));
        break;

    default:
        // Nothing needs to be done
        break;
    }
}

QList<QPointF> ChartWindow::make_custom_series(const std::vector<std::pair<int, double>> &filtered, int to_start, int to_end)
{
    int counter = to_start;
    QList<QPointF> points;

    while(counter <= to_end)
    {
        qDebug() << filtered.at(counter).first << "year to be in series";
        points.append(QPointF(filtered.at(counter).first, filtered.at(counter).second));
        counter++;
    }

    return points;
}


void ChartWindow::display_custom_series(const std::vector<std::pair<int, double>> &filtered)
{

    remove_all_graph_series();

    int start = 0;
    double max_value = 0;
    double previous_value = -1;
    double current_value;
    std::vector<QList<QPointF>> points;

    for(unsigned int data_point = start ; data_point < filtered.size() ; data_point++)
    {
        current_value = filtered.at(data_point).second;

        if(current_value == 0 && previous_value > 0)
        {
            points.push_back(make_custom_series(filtered, start, data_point -1));
            start = data_point;
        }
        else if(current_value > 0 && previous_value == 0)
        {
            points.push_back(make_custom_series(filtered, start, data_point -1));
            start = data_point;
        }
        else if(data_point == filtered.size() - 1)
        {
            points.push_back(make_custom_series(filtered, start, data_point));
        }

        previous_value = current_value;

        //Max value checker
        if(current_value > max_value)
        {
            max_value = current_value;
        }
    }

    unsigned int point_amount = 0;

    for(QList<QPointF> points_list : qAsConst(points))
    {
        QLineSeries *series = new QLineSeries();
        point_amount = point_amount + points_list.size();
        series->append(points_list);

        if(series->at(0).y() == 0)
        {
            series->setVisible(false);
        }

        ui->chartView->chart()->addSeries(series);
    }

    ui->chartView->chart()->createDefaultAxes();

    QValueAxis *x_axis = static_cast<QValueAxis*>(ui->chartView->chart()->axisX());
    x_axis->setTitleText("Years");
    x_axis->setTickCount(point_amount);
    x_axis->setGridLineVisible(true);
    x_axis->setLabelFormat("%.1i");

    QValueAxis *y_axis = static_cast<QValueAxis*>(ui->chartView->chart()->axisY());
    y_axis->setRange(0, ceil(max_value));
    y_axis->setTitleText("Tonnes");
    y_axis->setTickCount(10);
    y_axis->setGridLineVisible(true);
    y_axis->setLabelFormat("%.1i");

    view_elements->selected_preset_time = Custom;
}


//==============================================================================================
//SLOTS

//----------------------------------------------------------------------------------------------
// Public slots


// TimeWindow slot

void ChartWindow::get_pair(std::pair<QString,QString> time_pair)
{
    view_elements->selected_custom_time = time_pair;
    on_applyButton_clicked();
}



//----------------------------------------------------------------------------------------------
// Button slots

void ChartWindow::on_defaultButton_clicked()
{
    default_combo_boxes();
    default_check_boxes();
}

void ChartWindow::on_dayButton_clicked()
{
    quick_time_change(Day);
}

void ChartWindow::on_weekButton_clicked()
{
    quick_time_change(Week);
}

void ChartWindow::on_monthButton_clicked()
{
    quick_time_change(Month);
}

void ChartWindow::on_yearButton_clicked()
{
    quick_time_change(Year);
}

void ChartWindow::on_timeButton_clicked()
{
    TimeWindow *date = new TimeWindow();
    connect(date, &TimeWindow::send_pair, this, &ChartWindow::get_pair);
    date->setModal(true);
    date->change_data(ui->databaseCombo->currentText());
    date->show();
}

void ChartWindow::on_applyButton_clicked()
{
    // Send ViewObject pointer to controller
    UserSelections* selections = nullptr;
    DataSource current = view_elements->current_database;

    if(current == DataSource::STATFI && view_elements->radioselection_statfi != DataSet::None)
    {
        selections = new UserSelections(DataSource::STATFI);
        selections->setDataSet(view_elements->radioselection_statfi);
        selections->setStart(Date(1,1,view_elements->selected_custom_time.first.toInt(),0,0));
        selections->setEnd(Date(1,1,view_elements->selected_custom_time.second.toInt(),0,0));

        qDebug().nospace() << "abc" << qPrintable(view_elements->radioselection_statfi) << "def";

        std::vector<std::pair<int, double>> filteredVector = Controller::getSTATFIData(selections);
        qDebug() << "Filtered Vecor in Chart Window" << filteredVector;

        display_custom_series(filteredVector);
    }

    else if(current == DataSource::SMEAR && view_elements->radioselection_smear != DataSet::None)
    {
        if(view_elements->selected_preset_time == Custom)
        {
            selections = new UserSelections(DataSource::SMEAR);
            selections->setMeasuringStation(view_elements->current_station);
            selections->setDataSet(view_elements->radioselection_smear);
            selections->setStart(Date(view_elements->selected_custom_time.first.toStdString()));
            selections->setEnd(Date(view_elements->selected_custom_time.second.toStdString()));
            selections->setAggregateType(view_elements->selected_aggregation);

            std::vector<DataPoint> gasDp = Controller::getSMEARData(selections);


        }
        else
        {
            switch(view_elements->radioselection_smear)
            {
            case CO2:
                // TODO Fetch the correct information and display it on the graph
                react_to_selection(true, co2_series);
                break;

            case SO2:
                // TODO -||-
                react_to_selection(true, so2_series);
                break;

            case NO:
                // TODO -||-
                react_to_selection(true, nox_series);
                break;

            default:
                // Nothing to be done
                break;
            }
        }
    }

    delete selections;
}


//----------------------------------------------------------------------------------------------
// Combo Box slots

void ChartWindow::on_databaseCombo_currentIndexChanged(const QString current_database)
{
    default_check_boxes();

    bool quick_times = false;
    QString button_text;
    QWidget *widget = nullptr;

    if(current_database == "STATFI")
    {
        quick_times = false;
        button_text = "Year-to_Year";
        widget = ui->stackedBoxes->widget(1);
        quick_time_change(Year);
        view_elements->current_database = DataSource::STATFI;
        view_elements->current_station = MeasuringStation::None;
    }

    else if(current_database == "SMEAR")
    {
        quick_times = true;
        button_text = "Date-to-Date";
        widget = ui->stackedBoxes->widget(0);
        view_elements->current_database = DataSource::SMEAR;
        view_elements->current_station = static_cast<MeasuringStation>(ui->stationCombo->currentIndex());

        remove_all_graph_series();
        quick_time_change(Day);

        // Re-make the Y-axis
        ui->chartView->chart()->removeAxis(ui->chartView->chart()->axisY());
        QValueAxis *axis_y = new QtCharts::QValueAxis();
        axis_y->setRange(0, 2000);
        axis_y->setTickCount(9);
        axis_y->setGridLineVisible(true);
        axis_y->setLabelFormat("%.1i");
        axis_y->setTitleText("Tonnes");
        ui->chartView->chart()->addAxis(axis_y, Qt::AlignLeft);
    }

    // Combo box and label visibility
    ui->stationCombo->setVisible(quick_times);
    ui->aggregationCombo->setVisible(quick_times);

    ui->stationLabel->setVisible(quick_times);
    ui->aggregationLabel->setVisible(quick_times);

    //Quick time selection buttons
    ui->yearButton->setEnabled(quick_times);
    ui->monthButton->setEnabled(quick_times);
    ui->weekButton->setEnabled(quick_times);
    ui->dayButton->setEnabled(quick_times);

    //Specific time period button changed
    ui->timeButton->setText(button_text);

    //Change the check boxes
    ui->stackedBoxes->setCurrentWidget(widget);

    //Default the check boxes
    default_check_boxes();

    //Take Lines of the graph
    remove_all_graph_series();
}

void ChartWindow::on_stationCombo_currentIndexChanged(const QString current_station)
{
    if(current_station == "Värriö")
    {
        view_elements->current_station = MeasuringStation::Varrio;
    }
    else if(current_station == "Hyytiälä")
    {
        view_elements->current_station = MeasuringStation::Hyytiala;
    }
    else if(current_station == "Kumpula")
    {
        view_elements->current_station = MeasuringStation::Kumpula;
    }
}

void ChartWindow::on_aggregationCombo_currentIndexChanged(const QString current_aggregate)
{
    if(current_aggregate == "Arithmetic")
    {
        view_elements->selected_aggregation = AggregateType::Arithmetic;
    }
    else if(current_aggregate == "Geometric")
    {
        view_elements->selected_aggregation = AggregateType::Geometric;
    }
    else if(current_aggregate == "Sum")
    {
        view_elements->selected_aggregation = AggregateType::Sum;
    }
    else if(current_aggregate == "Median")
    {
        view_elements->selected_aggregation = AggregateType::Median;
    }
    else if(current_aggregate == "Min")
    {
        view_elements->selected_aggregation = AggregateType::Min;
    }
    else if(current_aggregate == "Max")
    {
        view_elements->selected_aggregation = AggregateType::Max;
    }
    else if(current_aggregate == "Availability")
    {
        view_elements->selected_aggregation = AggregateType::Availability;
    }
    else if(current_aggregate == "Circular")
    {
        view_elements->selected_aggregation = AggregateType::Circular;
    }
    else
    {
        view_elements->selected_aggregation = AggregateType::None;
    }

}
//----------------------------------------------------------------------------------------------
// Check Box and Radio Button slots

void ChartWindow::on_co2Radio_clicked(bool state)
{
    if(state == true)
    {
        view_elements->radioselection_smear = CO2;
    }
}

void ChartWindow::on_so2Radio_clicked(bool state)
{
    if(state == true)
    {
        view_elements->radioselection_smear = SO2;
    }
}

void ChartWindow::on_noxRadio_clicked(bool state)
{
    if(state == true)
    {
        view_elements->radioselection_smear = NO;
    }
}



void ChartWindow::on_co2DataRadio_clicked(bool state)
{
    if(state == true)
    {
        view_elements->radioselection_statfi = CO2tonnes;
    }
}

void ChartWindow::on_intensityRadio_clicked(bool state)
{
    if(state == true)
    {
        view_elements->radioselection_statfi = CO2intensity;
    }
}

void ChartWindow::on_indexedRadio_clicked(bool state)
{
    if(state == true)
    {
        view_elements->radioselection_statfi = CO2indexed;
    }
}

void ChartWindow::on_indexedIntensityRadio_clicked(bool state)
{
    if(state == true)
    {
        view_elements->radioselection_statfi = CO2intensityIndexed;
    }
}

//----------------------------------------------------------------------------------------------
// Menu Bar slots

void ChartWindow::on_actionNewWindow_triggered()
{
    ChartWindow *history = new ChartWindow();
    history->show();
}

void ChartWindow::on_actionCloseWindow_triggered()
{
    this->close();
}
