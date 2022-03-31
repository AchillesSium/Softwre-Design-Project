#include "chartwindow.h"
#include "ui_chartwindow.h"
#include "userselections.h"
#include "controller.h"
#include "date.h"
#include <QDebug>

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
    ui->chartView->setChart(graph);
    ui->chartView->setRenderHint(QPainter::Antialiasing);

    // Check correct checkboxes
    ui->co2Box->setChecked(true);
    ui->so2Box->setChecked(true);
    ui->noxBox->setChecked(true);

    // Might need to add the checkboxes for calculated values
    view_elements->checks.insert(std::make_pair(CO2_Checkbox, true));
    view_elements->checks.insert(std::make_pair(SO2_Checkbox, true));
    view_elements->checks.insert(std::make_pair(NOx_Checkbox, true));
    view_elements->checks.insert(std::make_pair(Other_Checkbox, false));

    // Set correct combo box and stacked widget
    ui->databaseCombo->blockSignals(true);

    ui->databaseCombo->setCurrentText("SMEAR");
    view_elements->current_database = SMEAR;
    ui->stackedBoxes->setCurrentIndex(0);
    view_elements->current_station = Station_1;
    view_elements->radioselection = None;

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

    if(view_elements->current_database == SMEAR)
    {
        // Gasses checked
        ui->co2Box->setChecked(false);
        ui->so2Box->setChecked(false);
        ui->noxBox->setChecked(false);
        ui->otherBox->setChecked(false);
    }
    else if(view_elements->current_database == STATFI)
    {
        // Uncheck the checked radio button
        switch(view_elements->radioselection)
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
        view_elements->radioselection = None;
    }

    // Min, max, average unchecked
    ui->maxBox->setChecked(false);
    ui->minBox->setChecked(false);
    ui->avgBox->setChecked(false);

    // Inform the struct
    view_elements->checks.at(CO2_Checkbox) = false;
    view_elements->checks.at(SO2_Checkbox) = false;
    view_elements->checks.at(NOx_Checkbox) = false;
    view_elements->checks.at(Other_Checkbox) = false;
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

void ChartWindow::react_to_checkbox(bool state, std::vector<QtCharts::QLineSeries *> &pointers)
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

    if(ui->co2Box->isChecked())
    {
        remove_graph_series(co2_series.at(view_elements->selected_preset_time));
    }

    if(ui->so2Box->isChecked())
    {
        remove_graph_series(so2_series.at(view_elements->selected_preset_time));
    }

    if(ui->noxBox->isChecked())
    {
        remove_graph_series(nox_series.at(view_elements->selected_preset_time));
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

    if(ui->co2Box->isChecked())
    {
        add_graph_series(co2_series.at(view_elements->selected_preset_time));
    }

    if(ui->so2Box->isChecked())
    {
        add_graph_series(so2_series.at(view_elements->selected_preset_time));
    }

    if(ui->noxBox->isChecked())
    {
        add_graph_series(nox_series.at(view_elements->selected_preset_time));
    }
}

int ChartWindow::check_for_actual_values(const std::vector<std::pair<int, double>> &possible_values)
{
    unsigned int counter = 0;
    double current_value;

    while(counter < possible_values.size())
    {
        current_value = possible_values.at(counter).second;
        if(current_value != 0)
        {
            return counter;
        }

        counter++;
    }

    return -1;
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

    int start = check_for_actual_values(filtered);

    if(start == -1)
    {
        //Nothing to show!
        return;
    }

    remove_all_graph_series();

    double max_value = filtered.at(0).second;
    double previous_value = 1;
    double current_value;
    std::vector<QList<QPointF>> points;

    for(unsigned int data_point = start ; data_point < filtered.size() ; data_point++)
    {
        current_value = filtered.at(data_point).second;

        if(current_value == 0 && previous_value != 0)
        {
            qDebug() << "new series chosen bcause of a zero value";
            points.push_back(make_custom_series(filtered, start, data_point -1));
            qDebug() << "new series ready";
        }
        else if(current_value != 0 && previous_value == 0)
        {
            qDebug() << "start index changed";
            start = data_point;
        }
        else if(current_value != 0 && data_point == filtered.size() - 1)
        {
            qDebug() << "new series chosen bcause of end of the list";
            points.push_back(make_custom_series(filtered, start, data_point));
        }

        previous_value = current_value;

        // Max value checker
        if(current_value > max_value)
        {
            max_value = current_value;
        }
    }



    max_value = ceil(max_value);

    // Y-axis
    ui->chartView->chart()->removeAxis(ui->chartView->chart()->axisY());
    axis_y = new QValueAxis();

    axis_y->setRange(0, max_value);
    axis_y->setTickCount(9);
    axis_y->setTitleText("Tonnes");
    axis_y->setGridLineVisible(true);
    axis_y->setLabelFormat("%.1i");
    ui->chartView->chart()->addAxis(axis_y, Qt::AlignLeft);
    view_elements->selected_preset_time = Custom;

    // X-axis
    ui->chartView->chart()->removeAxis(ui->chartView->chart()->axisX());
    axis_x = new QValueAxis();

    axis_x->setRange(filtered.at(0).first, filtered.at(filtered.size() - 1).first);
    axis_x->setTickCount(filtered.size());
    axis_x->setTitleText("Years");
    axis_x->setGridLineVisible(true);
    axis_x->setLabelFormat("%.1i");
    ui->chartView->chart()->addAxis(axis_x, Qt::AlignBottom);

    for(QList<QPointF> points_list : qAsConst(points))
    {
        QLineSeries *series = new QLineSeries();
        series->append(points_list);
        add_graph_series(series);
    }

    /*double max_value = filtered.at(0).second;
    double current_value;

    std::vector<QList<QPointF>> datapoints;
    for(std::pair<int, double> data_point : filtered)
    {


        current_value = data_point.second;

        if(current_value == 0)
        {
            continue;
        }
        else
        {
            custom_series->append(data_point.first, current_value);
        }

        if(current_value > max_value)
        {
            max_value = current_value;
        }
    }
*/

//    add_graph_series(custom_series);
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
    Database current = view_elements->current_database;

    if(current == STATFI && view_elements->radioselection != None)
    {
        selections = new UserSelections(DataSource::STATFI);
        selections->setDataSet(view_elements->radioselection);
        selections->setStart(Date(1,1,view_elements->selected_custom_time.first.toInt(),0,0));
        selections->setEnd(Date(1,1,view_elements->selected_custom_time.second.toInt(),0,0));

        qDebug().nospace() << "abc" << qPrintable(view_elements->radioselection) << "def";
        std::vector<std::pair<int, double>> filteredVector = Controller::getSTATFIData(selections);
        qDebug() << "Filtered Vecor in Chart Window" << filteredVector;

        display_custom_series(filteredVector);
    }

    else if(current == SMEAR)
    {
        selections = new UserSelections(DataSource::SMEAR);
        selections->setMeasuringStation(MeasuringStation::Varrio); // Later get the actual user selection
        selections->setDataSet(DataSet::CO2); // Later use view_elements->radioselection when it is updated to handle SMEAR dataSets
        selections->setStart(Date(view_elements->selected_custom_time.first.toStdString()));
        selections->setEnd(Date(view_elements->selected_custom_time.second.toStdString()));
        selections->setAggregateType(AggregateType::Arithmetic); // Later get the actual user selection

        Controller::getSMEARData(selections);

        for(unsigned int box_count = 0; box_count < 4; box_count++)
        {
            switch(box_count)
            {
            case CO2_Checkbox:
                // TODO Fetch the correct information and display it on the graph
                react_to_checkbox(view_elements->checks.at(CO2_Checkbox), co2_series);
                break;

            case SO2_Checkbox:
                // TODO -||-
                react_to_checkbox(view_elements->checks.at(SO2_Checkbox), so2_series);
                break;

            case NOx_Checkbox:
                // TODO -||-
                react_to_checkbox(view_elements->checks.at(NOx_Checkbox), nox_series);
                break;

            case Other_Checkbox:
                // TODO -||-
                break;
            }
        }
    }

    delete selections;
}


//----------------------------------------------------------------------------------------------
// Combo Box slots

void ChartWindow::on_databaseCombo_currentIndexChanged(const int index)
{
    default_check_boxes();

    bool min_max = false;
    bool quick_times = false;
    QString button_text;
    QWidget *widget = nullptr;

    switch(index)
    {
    case STATFI:
        min_max = false;
        quick_times = false;
        button_text = "Year-to_Year";
        widget = ui->stackedBoxes->widget(1);
        quick_time_change(Year);
        view_elements->current_database = STATFI;
        view_elements->current_station = NONE;
        break;

    case SMEAR:
        min_max = true;
        quick_times = true;
        button_text = "Date-to-Date";
        widget = ui->stackedBoxes->widget(0);
        view_elements->current_database = SMEAR;
        view_elements->current_station = static_cast<Station>(ui->stationCombo->currentIndex());

        if(view_elements->selected_preset_time == Custom)
        {
            //TODO (At the moment just changes things so that program can keep working)
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
        break;
    }

    // Measuring stations combo box visibility
    ui->stationCombo->setVisible(quick_times);

    //Max, min and average
    ui->maxBox->setEnabled(min_max);
    ui->minBox->setEnabled(min_max);
    ui->avgBox->setEnabled(min_max);

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

void ChartWindow::on_stationCombo_currentIndexChanged(const int index)
{
    view_elements->current_station = static_cast<Station>(index);
}


//----------------------------------------------------------------------------------------------
// Check Box and Radio Button slots

void ChartWindow::on_co2Box_clicked(bool state)
{
    view_elements->checks.at(CO2_Checkbox) = state;
}

void ChartWindow::on_so2Box_clicked(bool state)
{
    view_elements->checks.at(SO2_Checkbox) = state;
}

void ChartWindow::on_noxBox_clicked(bool state)
{
    view_elements->checks.at(NOx_Checkbox) = state;
}

void ChartWindow::on_otherBox_clicked(bool state)
{
    view_elements->checks.at(Other_Checkbox) = state;
}



void ChartWindow::on_co2DataRadio_clicked(bool state)
{
    if(state == true)
    {
        view_elements->radioselection = CO2tonnes;
    }
}

void ChartWindow::on_intensityRadio_clicked(bool state)
{
    if(state == true)
    {
        view_elements->radioselection = CO2intensity;
    }
}

void ChartWindow::on_indexedRadio_clicked(bool state)
{
    if(state == true)
    {
        view_elements->radioselection = CO2indexed;
    }
}

void ChartWindow::on_indexedIntensityRadio_clicked(bool state)
{
    if(state == true)
    {
        view_elements->radioselection = CO2intensityIndexed;
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
