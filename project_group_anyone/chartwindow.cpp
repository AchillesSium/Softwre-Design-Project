#include "chartwindow.h"
#include "ui_chartwindow.h"
#include "userselections.h"
#include "controller.h"
#include "date.h"
#include <QDebug>
#include <sstream>
#include <QString>


/**
 * @brief ChartWindow::ChartWindow handles everything in the view. It is the GUI of the program.
 *        Every change of every element in the UI is made trough this object for it has the ownership
 *        of every view element.
 * @param parent is a pointer to a possible parent object.
 */
ChartWindow::ChartWindow(QWidget *parent) :
      QMainWindow(parent),
      ui(new Ui::ChartWindow),
      view_elements(new ViewObject)
{
    ui->setupUi(this);

    // Initialize the chart
    QtCharts::QChart *graph = new QtCharts::QChart();
    graph->setTitle("Gasses in your environment");
    graph->legend()->setVisible(false);

    // Initialize the chart view
    ui->chartView->setChart(graph);
    ui->chartView->setRenderHint(QPainter::Antialiasing);

    set_statfi();
}

ChartWindow::~ChartWindow()
{
    ui->chartView->chart()->removeAllSeries();
    delete ui;
}

//----------------------------------------------------------------------------------------------
// Default functions


/**
 * @brief ChartWindow::default_radio_buttons defaults a set of radiobuttons depending on the
 *        Database currently used.
 */
void ChartWindow::default_radio_buttons()
{
    //remove_all_graph_series();
    ui->chartView->chart()->removeAllSeries();

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
    }

    // Empty out the view element
    view_elements->radioselection_statfi = None;
    view_elements->radioselection_smear = None;

}

/**
 * @brief ChartWindow::set_smear sets the View so SMEAR data can be fetched. This includes changing
 *        some visibility values and resetting changes made when STATFI was the current database.
 */
void ChartWindow::set_smear()
{
    // Set the viewObject
    view_elements->current_database = DataSource::SMEAR;
    view_elements->selected_aggregation = AggregateType::Arithmetic;
    view_elements->current_station = MeasuringStation::Varrio;
    view_elements->radioselection_smear = DataSet::None;
    view_elements->radioselection_statfi = DataSet::None;
    selected_preset_time = Time::No_time;
    view_elements->selected_time = std::make_pair("", "");


    // Set view elements for STATFI

        // Quick time buttons
        ui->yearButton->setVisible(true);
        ui->monthButton->setVisible(true);
        ui->weekButton->setVisible(true);
        ui->dayButton->setVisible(true);

        // Radio buttons
        ui->stackedBoxes->setCurrentWidget(ui->smearBox);

        // Combo boxes
        ui->stationCombo->setVisible(true);
        ui->stationLabel->setVisible(true);
        ui->aggregationCombo->setVisible(true);
        ui->aggregationLabel->setVisible(true);

        ui->stationCombo->blockSignals(true);
        ui->aggregationCombo->blockSignals(true);

        ui->stationCombo->setCurrentIndex(0);
        ui->aggregationCombo->setCurrentIndex(0);

        ui->stationCombo->blockSignals(false);
        ui->aggregationCombo->blockSignals(false);

        // Custom time button text
        ui->timeButton->setText("Date-to_Date");

        // Time span display
        ui->selected_time_display->setPlainText(not_selected);
}


/**
 * @brief ChartWindow::set_statfi is similar to ChartWindow::set_smear, but opposite regarding the
 *        databases.
 */
void ChartWindow::set_statfi()
{
    // Set the viewObject
    view_elements->current_database = DataSource::STATFI;
    view_elements->selected_aggregation = AggregateType::Arithmetic;
    view_elements->current_station = MeasuringStation::None;
    view_elements->radioselection_smear = DataSet::None;
    view_elements->radioselection_statfi = DataSet::None;
    selected_preset_time = Time::No_time;
    view_elements->selected_time = std::make_pair("", "");


    // Set view elements for STATFI

        // Quick time buttons
        ui->yearButton->setVisible(false);
        ui->monthButton->setVisible(false);
        ui->weekButton->setVisible(false);
        ui->dayButton->setVisible(false);

        // Radio buttons
        ui->stackedBoxes->setCurrentWidget(ui->statfiBox);

        // Combo boxes
        ui->stationCombo->setVisible(false);
        ui->stationLabel->setVisible(false);
        ui->aggregationCombo->setVisible(false);
        ui->aggregationLabel->setVisible(false);

        // Custom time button text
        ui->timeButton->setText("Year-to_Year");

        // Time span display
        ui->selected_time_display->setPlainText(not_selected);
}


//----------------------------------------------------------------------------------------------
// Quality of life functions


/**
 * @brief ChartWindow::round_to_nearest rounds the given value to the nearest integer depending
 *        on the size of the number.
 * @param minmax is the number to be rounded.
 * @return Method returns the rounded number.
 */
unsigned int ChartWindow::round_to_nearest(double minmax)
{
    unsigned int rounder = 1;

    if(minmax < 10)
    {
        rounder = 1;
    }
    else if (minmax < 100)
    {
        rounder = 10;
    }
    else if (minmax < 1000)
    {
        rounder = 100;
    }
    else if (minmax < 10000)
    {
        rounder = 1000;
    }
    else if (minmax < 100000)
    {
        rounder = 10000;
    }
    else if (minmax < 1000000)
    {
        rounder = 100000;
    }

    return ceil(minmax/rounder)*rounder;
}


/**
 * @brief ChartWindow::largest_divider finds out the biggest number the given number can be divided
 *        without a remainder. If such number cannot be found, other than 1, the number is returned
 *        with +1. This is because the method is used determening the "tick count" for the chart and
 *        one tick must be reseved for the y-axis.
 * @param point_count is the int number to be observed
 * @return Returns the biggest divider with +1.
 */
unsigned int ChartWindow::largest_divider(unsigned int point_count)
{
    if(point_count <= 5)
    {
        return point_count;
    }

    unsigned int counter = 1;
    unsigned int max_divider = 1;

    while(counter < point_count)
    {
        if(point_count % counter == 0)
        {
            max_divider = counter;
        }

        counter++;
    }

    if(max_divider == 1) // point_count is a prime number
    {
        max_divider = point_count;
    }

    return max_divider + 1;
}

/**
 * @brief ChartWindow::smear_axis creates an axis for SMEAR data. Method determines the time span
 *        at hand is with given data and follows the path to a correct form of an axis.
 * @param dates is a vector of data about the values and times the values happened.
 * @return Method returns a pointer to the correct axis.
 */
QtCharts::QDateTimeAxis* ChartWindow::smear_axis(const std::vector<std::pair<long double, QDateTime>> &dates)
{
    QDateTime begin = dates.front().second;
    QDateTime end = dates.back().second;

    QDateTimeAxis *time_axis = new QDateTimeAxis;
    time_axis->setGridLineVisible(true);

    qDebug() << "Startted";
    if(begin.date().year() == end.date().year())
    {
            qDebug() << "In year";
        if(begin.date().month() == end.date().month())
        {
            qDebug() << "In month";
            if(begin.date().day() == end.date().day())
            {
                qDebug() << "In day";
                time_axis->setTickCount(largest_divider(end.time().hour() - begin.time().hour()));
                time_axis->setFormat("d hh:mm");
            }
            else
            {
                if(begin.daysTo(end) > 1)
                {
                    time_axis->setTickCount(largest_divider(end.date().day() - begin.date().day()));
                    time_axis->setFormat("dd/M");
                }
                else // Only one day difference
                {
                    time_axis->setTickCount(largest_divider(end.time().hour() - begin.time().hour()));
                    time_axis->setFormat("hh:mm");
                }
            }
        }
        else
        {
            if(end.date().month() - begin.date().month() > 1)
            {
                time_axis->setTickCount(end.date().month() - begin.date().month() + 1);
                time_axis->setFormat("MMM");
            }
            else // Only one month difference
            {
                qDebug() << "Month else";

                time_axis->setTickCount(largest_divider(begin.daysTo(end)));
                time_axis->setFormat("dd/M");
            }
        }
    }
    else
    {
        if(end.date().year() - begin.date().year() > 1)
        {
            time_axis->setTickCount(end.date().year() - begin.date().year() + 1);
            time_axis->setFormat("yyyy");
        }
        else // Only one year difference
        {
            time_axis->setTickCount(13);
            time_axis->setFormat("MMM/yy");
        }
    }

    time_axis->setRange(begin, end);
    time_axis->setTitleText("Time");
    return time_axis;
}

/**
 * @brief ChartWindow::enum_to_string is made to get the corresponding QString to an enum.
 * @param type is the given enum.
 * @return Returns the QString determined by the enum given.
 */
QString ChartWindow::enum_to_string(AggregateType type)
{
    QString returnable;

    switch(type)
    {
    case AggregateType::Arithmetic:
        returnable = "Arithmetic";
        break;
    case AggregateType::Geometric:
        returnable = "Geometric";
        break;
    case AggregateType::Sum:
        returnable = "Sum";
        break;
    case AggregateType::Median:
        returnable = "Sum";
        break;
    case AggregateType::Min:
        returnable = "Min";
        break;
    case AggregateType::Max:
        returnable = "Max";
        break;
    case AggregateType::Availability:
        returnable = "Availability";
        break;
    case AggregateType::Circular:
        returnable = "Circular";
        break;
    default:
        returnable = "Arithmetic";
        break;
    }

    return returnable;
}


//----------------------------------------------------------------------------------------------
// Chart functions

/**
 * @brief ChartWindow::quick_time_change changes the time span quickly to one of the preset time spans.
 *        Which setting is used is determined by the enum given.
 * @param period.is the given enum.
 */
void ChartWindow::quick_time_change(Time period)
{
    QDateTime begin;
    QDateTime end = begin.currentDateTime();
    qDebug() << end;

    QString title_text;

    switch(period)
    {
    case Day:
        begin = end.addDays(-1);
        title_text = "Hours";
        break;

    case Week:
        begin = end.addDays(-7);
        title_text = "Days";
        break;

    case Month:
        begin = end.addMonths(-1);
        title_text = "Days";
        break;

    case Year:
        begin = end.addYears(-1);
        title_text = "Months";
        break;

    default:
        title_text = "Custom";
        break;
    }

    view_elements->selected_time = std::make_pair(begin.toString("dd/MM/yyyy"), end.toString("dd/MM/yyyy"));
    ui->selected_time_display->setPlainText(selected + begin.toString("dd/MM/yyyy") + " - " + end.toString("dd/MM/yyyy"));

    selected_preset_time = period;
}


/**
 * @brief ChartWindow::make_statfi_series method makes a list of QPoints that can later be formed into
 *        a QLineSeries. Given vector gives the bulk of the data which is then iterated trough according
 *        to given starting and ending indexes of the vector. This method is used specifically
 *        when visualizin STATFI data.
 * @param filtered is the vector of all the datapoins as pairs.
 * @param to_start is the starting index.
 * @param to_end is the ending index.
 * @return Method returns the list of QPoints.
 */
QList<QPointF> ChartWindow::make_statfi_series(const std::vector<std::pair<int, double>> &filtered, unsigned int to_start, unsigned int to_end)
{
    unsigned int counter = to_start;
    QList<QPointF> points;

    while(counter <= to_end)
    {
        points.append(QPointF(filtered.at(counter).first, filtered.at(counter).second));
        counter++;
    }

    return points;
}

/**
 * @brief ChartWindow::make_smear_series is similar to the ChartWindow::make_statfi_series method.
 *        However here the method makes a finished QLineSeries instead of a list of QPoints.
 *        The variables work in similar manner.
 * @param pre_series has the all datapoints as pairs.
 * @param start is the starting index of the series in the given vector.
 * @param ending is the ending index of the series in the given vector.
 * @return
 *        Method returns a pointer to the finished QLineSeries.
 */
QtCharts::QLineSeries* ChartWindow::make_smear_series(const std::vector<std::pair<long double, QDateTime>> &pre_series, unsigned int start, unsigned int ending)
{
    qDebug() << "In make_smear_series";
    unsigned int counter = start;
    QLineSeries *series = new QLineSeries();

    while(counter <= ending)
    {
        series->append(pre_series.at(counter).second.toMSecsSinceEpoch(), pre_series.at(counter).first);
        counter++;
    }

    qDebug() << "Made it, returning...";
    return series;
}

/**
 * @brief ChartWindow::display_statfi iterates trough the data the controller gives to the view
 *        and visualizes it to the ChartView. Given data is transformed into QLineSerieses and
 *        based on this data the chart axes are also formed and scaled accordingly.
 * @param filtered includes all the data that is wanted to be a series as datapoint pairs.
 */
void ChartWindow::display_statfi(const std::vector<std::pair<int, double>> &filtered)
{
    ui->chartView->chart()->removeAllSeries();

    int start = 0;
    double max_value = 0;
    double min_value = std::numeric_limits<unsigned int>::max();
    double previous_value = -1;
    double current_value;
    std::vector<QList<QPointF>> points;

    for(unsigned int data_point = 0 ; data_point < filtered.size() ; data_point++)
    {
        current_value = filtered.at(data_point).second;

        if(current_value == 0 && (previous_value > 0 || previous_value == -1))
        {
            if(data_point == 0)
            {
                points.push_back(make_statfi_series(filtered, start, data_point));
            }
            else
            {
                points.push_back(make_statfi_series(filtered, start, data_point -1));
            }

            start = data_point;
        }
        else if(current_value > 0 && previous_value == 0)
        {
            points.push_back(make_statfi_series(filtered, start, data_point -1));
            start = data_point;
        }
        else if(data_point == filtered.size() - 1)
        {
            points.push_back(make_statfi_series(filtered, start, data_point));
        }

        previous_value = current_value;

        //Max value checker
        if(current_value > max_value)
        {
            max_value = current_value;
        }

        //Min value checker
        if(current_value < min_value)
        {
            min_value = current_value;
        }
    }

    unsigned int point_amount = 0;

    for(auto& points_list : qAsConst(points))
    {
        QLineSeries *series = new QLineSeries();
        point_amount = point_amount + points_list.size();
        series->append(points_list);

        if(series->at(0).y() == 0)
        {
            series->setVisible(false);
        }
        else
        {
            series->setPen(chart_pen);
        }

        ui->chartView->chart()->addSeries(series);
    }

    ui->chartView->chart()->createDefaultAxes();

    QValueAxis *x_axis = static_cast<QValueAxis*>(ui->chartView->chart()->axisX());
    x_axis->setTitleText("Years");
    x_axis->setTickCount(largest_divider(filtered.size()));
    x_axis->setGridLineVisible(true);
    x_axis->setLabelFormat("%.1i");

    unsigned int max_range = round_to_nearest(max_value + (min_value/10));
    unsigned int min_range;


    if(min_value - (max_range - max_value) > 0)
    {
        min_range = round_to_nearest(min_value - (max_range - max_value));

        if(min_range > min_value)
        {
            min_range = 0;
        }
    }
    else
    {
        min_range = 0;
    }

    QValueAxis *y_axis = static_cast<QValueAxis*>(ui->chartView->chart()->axisY());
    y_axis->setRange(min_range, max_range);

    QString title = "";

    switch(view_elements->radioselection_statfi)
    {
    case DataSet::CO2tonnes:
        title = tonnes;
        break;
    case DataSet::CO2indexed:
        break;
    case DataSet::CO2intensity:
        title = intensity;
        break;
    case DataSet::CO2intensityIndexed:
        break;
    default:
        break;
    }

    y_axis->setTitleText(title);

    if(max_value < 10)
    {
        y_axis->setTickCount(round_to_nearest(max_value) + 1);
    }
    else
    {
        y_axis->setTickCount(11);
    }

    y_axis->setGridLineVisible(true);
    y_axis->setLabelFormat("%.1i");

    selected_preset_time = Time::Custom;
}

/**
 * @brief ChartWindow::display_smear is similar to the ChartWindow::display_statfi method, but
 *        this method is only for SMEAR data as they require different visualization tools.
 * @param filtered includes all the data that is wanted to be a series as datapoint pairs.
 */
void ChartWindow::display_smear(const std::vector<std::pair<long double, QDateTime>> &filtered)
{
    ui->chartView->chart()->removeAllSeries();

    if (filtered.empty())
        return;

    unsigned int start = 0;
    double max_value = 0;
    double min_value = std::numeric_limits<unsigned int>::max();
    double previous_value = -1;
    double current_value;
    std::vector<QLineSeries*> all_series;

    for(unsigned int data_point = 0 ; data_point < filtered.size() ; data_point++)
    {
        current_value = filtered.at(data_point).first;

        if(current_value == 0 && (previous_value > 0 || previous_value == -1))
        {
            if(data_point == 0)
            {
                all_series.push_back(make_smear_series(filtered, start, data_point));
            }
            else
            {
                all_series.push_back(make_smear_series(filtered, start, data_point-1));
            }
            start = data_point;
        }
        else if(current_value > 0 && previous_value == 0)
        {
            all_series.push_back(make_smear_series(filtered, start, data_point-1));
            start = data_point;
        }
        else if(data_point == filtered.size() - 1)
        {
            all_series.push_back(make_smear_series(filtered, start, data_point));
        }

        previous_value = current_value;

        //Max value checker
        if(current_value > max_value)
        {
            max_value = current_value;
        }

        //Min value checker
        if(current_value < min_value)
        {
            min_value = current_value;
        }
    }

    // Create both axes
    QDateTimeAxis *time_axis = smear_axis(filtered);

    unsigned int max_range = round_to_nearest(max_value + (min_value/10));
    unsigned int min_range;

    if(min_value - (max_range - max_value) > 0)
    {
        min_range = round_to_nearest(min_value - (max_range - max_value));

        if(min_range > min_value)
        {
            min_range = 0;
        }
    }
    else
    {
        min_range = 0;
    }

    QValueAxis *value_axis = new QValueAxis;
    value_axis->setRange(min_range, max_range);
    value_axis->setTitleText(tonnes);

    if(max_value < 10)
    {
        value_axis->setTickCount(round_to_nearest(max_value) + 1);
    }
    else
    {
        value_axis->setTickCount(11);
    }

    value_axis->setGridLineVisible(true);
    value_axis->setLabelFormat("%.1i");

    if(ui->chartView->chart()->axisX())
    {
        ui->chartView->chart()->removeAxis(ui->chartView->chart()->axisX());
    }
    if(ui->chartView->chart()->axisY())
    {
        ui->chartView->chart()->removeAxis(ui->chartView->chart()->axisY());
    }

    // Add new axes to the chart
    ui->chartView->chart()->addAxis(time_axis, Qt::AlignBottom);
    ui->chartView->chart()->addAxis(value_axis, Qt::AlignLeft);

    for(QLineSeries* point_series : all_series)
    {
        ui->chartView->chart()->addSeries(point_series);
        point_series->attachAxis(time_axis);
        point_series->attachAxis(value_axis);

        if(point_series->at(0).y() == 0)
        {
            point_series->setVisible(false);
        }
        else
        {
            point_series->setPen(chart_pen);
        }
    }

    selected_preset_time = Time::Custom;
}


//==============================================================================================
//SLOTS

//----------------------------------------------------------------------------------------------
// Public slots


// TimeWindow slot

void ChartWindow::get_pair(std::pair<QString,QString> time_pair)
{
    view_elements->selected_time = time_pair;
    selected_preset_time = Time::Custom;

    ui->selected_time_display->setPlainText(selected + time_pair.first + " - " + time_pair.second);

    on_applyButton_clicked();
}



//----------------------------------------------------------------------------------------------
// Button slots

/**
 * @brief ChartWindow::on_defaultButton_clicked defaults all the view elements and deletes all the axes
 */
void ChartWindow::on_defaultButton_clicked()
{
    default_radio_buttons();

    if(view_elements->current_database == DataSource::STATFI)
    {
        set_statfi();
    }
    else if(view_elements->current_database == DataSource::SMEAR)
    {
        set_smear();
    }

    QAbstractAxis* x_axis = ui->chartView->chart()->axisX();
    QAbstractAxis* y_axis = ui->chartView->chart()->axisY();

    if(x_axis)
    {
        ui->chartView->chart()->removeAxis(x_axis);
    }
    if(y_axis)
    {
        ui->chartView->chart()->removeAxis(y_axis);
    }
}

/**
 * @brief ChartWindow::on_dayButton_clicked (and other preset time buttons clicked)
 *        These Methods set the current time span to be same as the button associated with it.
 *        These slots is only a shortcut to quick_time_change method.
 */
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

/**
 * @brief ChartWindow::on_timeButton_clicked creates a new TimeWindow where user can select the
 *        time span for their data.
 */
void ChartWindow::on_timeButton_clicked()
{
    TimeWindow *date = new TimeWindow();
    connect(date, &TimeWindow::send_pair, this, &ChartWindow::get_pair);
    date->setModal(true);
    date->change_data(view_elements->current_database, view_elements->current_station, view_elements->radioselection_smear);
    date->adjustSize();
    date->show();
}

/**
 * @brief ChartWindow::on_applyButton_clicked slot fetches the data the user requested.
 *        It creates the UserSelections object with data the user has given. Nature of the data
 *        is determined by the databases so they need to have their separate commands.
 */
void ChartWindow::on_applyButton_clicked()
{
    // Send ViewObject pointer to controller
    UserSelections* selections = nullptr;
    DataSource current = view_elements->current_database;

    if(current == DataSource::STATFI && view_elements->radioselection_statfi != DataSet::None)
    {
        selections = new UserSelections(DataSource::STATFI);
        selections->setDataSet(view_elements->radioselection_statfi);
        selections->setStart(Date(1,1,view_elements->selected_time.first.toInt(),0,0));
        selections->setEnd(Date(1,1,view_elements->selected_time.second.toInt(),0,0));

        std::vector<std::pair<int, double>> filtered_statfi = Controller::getSTATFIData(selections);
        display_statfi(filtered_statfi);
    }

    else if(current == DataSource::SMEAR && view_elements->radioselection_smear != DataSet::None && selected_preset_time != Time::No_time)
    {
        selections = new UserSelections(DataSource::SMEAR);
        selections->setMeasuringStation(view_elements->current_station);
        selections->setDataSet(view_elements->radioselection_smear);
        selections->setStart(Date(view_elements->selected_time.first.toStdString()));
        selections->setEnd(Date(view_elements->selected_time.second.toStdString()));
        selections->setAggregateType(view_elements->selected_aggregation);

        std::vector<std::pair<long double, QDateTime>> filtered_smear = Controller::getSMEARData(selections);

        display_smear(filtered_smear);

    }
    delete selections;
}


//----------------------------------------------------------------------------------------------
// Combo Box slots

/**
 * @brief ChartWindow::on_databaseCombo_currentIndexChanged (and other combo box slots)
 *        Generally all combo box slots have similar structure. Get the text from combo box when its data is
 *        changed and do actions according to this change.
 * @param current_database is the current text of the combo box after the change.
 */
void ChartWindow::on_databaseCombo_currentIndexChanged(const QString current_database)
{
    default_radio_buttons();

    if(current_database == "STATFI")
    {
        set_statfi();
    }

    else if(current_database == "SMEAR")
    {
        set_smear();
    }
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

/**
 * @brief ChartWindow::on_co2Radio_clicked (and other radio button slots)
 *        Radio button slots work all in the same way. If a radio buttons is clicked the slot
 *        activates and takes the booleon value of the button and changes the view_element accordingly.
 * @param state is the booleon value the radio button has been changed into after its clicked.
 */
void ChartWindow::on_co2Radio_clicked(bool state)
{
    if(state == true)
    {
        view_elements->radioselection_smear = DataSet::CO2;
    }
}

void ChartWindow::on_so2Radio_clicked(bool state)
{
    if(state == true)
    {
        view_elements->radioselection_smear = DataSet::SO2;
    }
}

void ChartWindow::on_noxRadio_clicked(bool state)
{
    if(state == true)
    {
        view_elements->radioselection_smear = DataSet::NO;
    }
}



void ChartWindow::on_co2DataRadio_clicked(bool state)
{
    if(state == true)
    {
        view_elements->radioselection_statfi = DataSet::CO2tonnes;
    }
}

void ChartWindow::on_intensityRadio_clicked(bool state)
{
    if(state == true)
    {
        view_elements->radioselection_statfi = DataSet::CO2intensity;
    }
}

void ChartWindow::on_indexedRadio_clicked(bool state)
{
    if(state == true)
    {
        view_elements->radioselection_statfi = DataSet::CO2indexed;
    }
}

void ChartWindow::on_indexedIntensityRadio_clicked(bool state)
{
    if(state == true)
    {
        view_elements->radioselection_statfi = DataSet::CO2intensityIndexed;
    }
}

//----------------------------------------------------------------------------------------------
// Menu Bar slots

/**
 * @brief ChartWindow::on_actionNewWindow_triggered opens a identical window to the main main window
 *        where user can compare charts.
 */
void ChartWindow::on_actionNewWindow_triggered()
{
    ChartWindow *history = new ChartWindow();
    history->show();
}

/**
 * @brief ChartWindow::on_actionCloseWindow_triggered closes the main window and thus the whole program.
 */
void ChartWindow::on_actionCloseWindow_triggered()
{
    this->close();
}

/**
 * @brief ChartWindow::on_actionPic_triggered takes a picture of the chart view window and lets the user
 *        save it on their computer.
 */
void ChartWindow::on_actionPic_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Save QChart"), "", tr("Images (*.png)"));
    QPixmap p = ui->chartView->grab();
    p.save(filename, "PNG");
}
/**
 * @brief ChartWindow::on_actionLoadLoadout_triggered
 * loads a loadout from the .json file and makes changes to
 * the state of the view accordingly.
 * Does nothing if there is no loadout saved.
 */
void ChartWindow::on_actionLoadLoadout_triggered()
{
    LoadoutHandler* lh = new LoadoutHandler();
    UserSelections* us = lh->load();

    if(us == nullptr){
        delete us;
        delete lh;
        return;
    }

    on_defaultButton_clicked();

    view_elements->current_database = us->getSource();

    if(view_elements->current_database == DataSource::STATFI)
    {
        ui->databaseCombo->setCurrentText("STATFI");

        switch(us->getDataSet())
        {
        case DataSet::CO2tonnes:
            ui->co2DataRadio->clicked(true);
            ui->co2DataRadio->setChecked(true);
            break;
        case DataSet::CO2indexed:
            ui->indexedRadio->clicked(true);
            ui->indexedRadio->setChecked(true);
            break;
        case DataSet::CO2intensity:
            ui->intensityRadio->clicked(true);
            ui->intensityRadio->setChecked(true);
            break;
        case DataSet::CO2intensityIndexed:
            ui->indexedIntensityRadio->clicked(true);
            ui->indexedIntensityRadio->setChecked(true);
            break;
        default:
            break;
        }

        view_elements->radioselection_smear = DataSet::None;

        // set start
        int year = us->getStart().getYear();
        std::string test = std::to_string(year);
        view_elements->selected_time.first = QString::fromStdString(test);

        // set end
        year = us->getEnd().getYear();
        test = std::to_string(year);
        view_elements->selected_time.second = QString::fromStdString(test);

        ui->selected_time_display->setPlainText(selected + view_elements->selected_time.first + " - " + view_elements->selected_time.second);

        selected_preset_time = Time::Custom;

    }
    else if(view_elements->current_database == DataSource::SMEAR)
    {
        ui->databaseCombo->setCurrentText("SMEAR");

        view_elements->radioselection_smear = us->getDataSet();

        switch(view_elements->radioselection_smear)
        {
        case DataSet::CO2:
            ui->co2Radio->clicked(true);
            ui->co2Radio->setChecked(true);
            break;
        case DataSet::SO2:
            ui->so2Radio->clicked(true);
            ui->so2Radio->setChecked(true);
            break;
        case DataSet::NO:
            ui->noxRadio->clicked(true);
            ui->noxRadio->setChecked(true);
            break;
        default:
            break;
        }

        view_elements->radioselection_statfi = DataSet::None;

        // set start
        int year = us->getStart().getYear();
        int month = us->getStart().getMonth();
        int day = us->getStart().getDay();

        QDate start = QDate(year, month, day);

        QString start_date = start.toString("dd/MM/yyyy");
        view_elements->selected_time.first = start_date;

        // set end
        year = us->getEnd().getYear();
        month = us->getEnd().getMonth();
        day = us->getEnd().getDay();

        QDate end = QDate(year, month, day);

        QString end_date = end.toString("dd/MM/yyyy");
        view_elements->selected_time.second = end_date;

        ui->selected_time_display->setPlainText(selected + start_date + " - " + end_date);

        selected_preset_time = Time::Custom;

        switch(us->getMeasuringStation())
        {
        case MeasuringStation::Varrio:
            ui->stationCombo->setCurrentText("Värriö");
            break;
        case MeasuringStation::Kumpula:
            ui->stationCombo->setCurrentText("Kumpula");
            break;
        case MeasuringStation::Hyytiala:
            ui->stationCombo->setCurrentText("Hyytälä");
            break;
        default:
            break;
        }

        ui->aggregationCombo->setCurrentText(enum_to_string(us->getAggregateType()));
    }

    delete us;
    delete lh;

    //on_applyButton_clicked();
}
/**
 * @brief ChartWindow::on_actionSaveLoadout_triggered
 * Saves the current view settings to a .json file
 */
void ChartWindow::on_actionSaveLoadout_triggered()
{
    if(view_elements->selected_time.first == "")
    {
        ui->selected_time_display->setPlainText(select_time);
        return;
    }

    // fetch all relevant data from ViewObject
    UserSelections* us = new UserSelections(view_elements->current_database);

    if(view_elements->current_database == DataSource::SMEAR){
        us->setDataSet(view_elements->radioselection_smear);
        us->setMeasuringStation(view_elements->current_station);
        us->setAggregateType(view_elements->selected_aggregation);
        us->setStart(Date(view_elements->selected_time.first.toStdString()));
        us->setEnd(Date(view_elements->selected_time.second.toStdString()));
    }
    else if(view_elements->current_database == DataSource::STATFI){
        us->setDataSet(view_elements->radioselection_statfi);
        us->setMeasuringStation(MeasuringStation::None);
        us->setAggregateType(AggregateType::None);
        Date start_d(1, 1, view_elements->selected_time.first.toInt(), 0, 0);
        Date end_d(1, 1, view_elements->selected_time.second.toInt(), 0, 0);
        us->setStart(start_d);
        us->setEnd(end_d);
    }


    LoadoutHandler* lh = new LoadoutHandler();
    lh->save(us);
    delete us;
    delete lh;
}
