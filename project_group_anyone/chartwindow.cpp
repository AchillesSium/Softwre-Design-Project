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
    graph->legend()->setVisible(false);

    // Initialize the X-axis
    QtCharts::QValueAxis *axis_x = new QtCharts::QValueAxis();
    axis_x->setRange(0, 24);
    axis_x->setTickCount(24);
    axis_x->setGridLineVisible(true);
    axis_x->setLabelFormat("%.1i");
    axis_x->setTitleText("Time Axis");

    // Add axis to the graph
    graph->addAxis(axis_x, Qt::AlignBottom);

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


void ChartWindow::set_smear()
{
    // Set the viewObject
    view_elements->current_database = DataSource::SMEAR;
    view_elements->selected_aggregation = AggregateType::None;
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

        // Display x-axis for user
        quick_time_change(Day);
}

void ChartWindow::set_statfi()
{
    // Set the viewObject
    view_elements->current_database = DataSource::STATFI;
    view_elements->selected_aggregation = AggregateType::None;
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

        // Display x-axis for user
        quick_time_change(Year);
}


//----------------------------------------------------------------------------------------------
// Quality of life functions

unsigned int ChartWindow::round_to_nearest(double minmax)
{
    unsigned int rounder = 1;

    if (minmax < 100)
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

    return ceil(minmax/rounder)*rounder;
}


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

    if(max_divider == 1) // On alkuluku
    {
        max_divider = point_count;
    }

    return max_divider + 1;
}


QtCharts::QDateTimeAxis* ChartWindow::smear_axis(const std::vector<std::pair<double, QDateTime>> &dates)
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
                time_axis->setFormat("ddd hh:mm");
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
                    time_axis->setFormat("ddd hh:mm");
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


//----------------------------------------------------------------------------------------------
// Chart functions

void ChartWindow::quick_time_change(Time period)
{
    QDateTime begin;
    QDateTime end = begin.currentDateTime();

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

    // Remove axis and make new dummy-axis as a placeholder for actual axis
    ui->chartView->chart()->removeAxis(ui->chartView->chart()->axisX());
    axis_x = new QValueAxis();
    axis_x->setTitleText(title_text);
    axis_x->setGridLineVisible(true);
    axis_x->setLabelFormat("%.1i");
    ui->chartView->chart()->addAxis(axis_x, Qt::AlignBottom);
    selected_preset_time = period;
}

QList<QPointF> ChartWindow::make_statfi_series(const std::vector<std::pair<int, double>> &filtered, unsigned int to_start, unsigned int to_end)
{
    unsigned int counter = to_start;
    QList<QPointF> points;

    while(counter <= to_end)
    {
        qDebug() << filtered.at(counter).first << "is to be in series";
        points.append(QPointF(filtered.at(counter).first, filtered.at(counter).second));
        counter++;
    }

    qDebug() << "got out";
    return points;
}

QtCharts::QLineSeries* ChartWindow::make_smear_series(const std::vector<std::pair<double, QDateTime>> &pre_series, unsigned int start, unsigned int ending)
{
    qDebug() << "In make_smear_series";
    unsigned int counter = start;
    QLineSeries *series = new QLineSeries();

    while(counter <= ending)
    {
        qDebug() << "Looping in make_semar_series in loop nr: " << counter;
        series->append(pre_series.at(counter).second.toMSecsSinceEpoch(), pre_series.at(counter).first);
        counter++;
    }

    qDebug() << "Made it, returning...";
    return series;
}


void ChartWindow::display_statfi(const std::vector<std::pair<int, double>> &filtered)
{

    //remove_all_graph_series();
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
        if(current_value < min_value && current_value > 0)
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

    QValueAxis *y_axis = static_cast<QValueAxis*>(ui->chartView->chart()->axisY());
    y_axis->setRange(0, round_to_nearest(max_value + min_value));
    y_axis->setTitleText("Tonnes");
    y_axis->setTickCount(11);
    y_axis->setGridLineVisible(true);
    y_axis->setLabelFormat("%.1i");

    selected_preset_time = Time::Custom;
}


void ChartWindow::display_smear(const std::vector<std::pair<double, QDateTime>> &filtered)
{
    qDebug() << "Starting";
    unsigned int start = 0;
    double max_value = 0;
    double min_value = std::numeric_limits<unsigned int>::max();
    double previous_value = -1;
    double current_value;
    std::vector<QLineSeries*> all_series;

    qDebug() << "Variables initialized";

    for(unsigned int data_point = 0 ; data_point < filtered.size() ; data_point++)
    {
        qDebug() << "Looping loop nr: " << data_point ;
        current_value = filtered.at(data_point).first;

        if(current_value == 0 && (previous_value > 0 || previous_value == -1))
        {
            qDebug() << "Beginning zero at " << filtered.at(data_point).second.toString("dd/MMMM/yyyy hh:ss");

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
            qDebug() << "Middle zero at " << filtered.at(data_point).second.toString("dd/MMMM/yyyy hh:ss");
            all_series.push_back(make_smear_series(filtered, start, data_point-1));
            start = data_point;
        }
        else if(data_point == filtered.size() - 1)
        {
            qDebug() << "Ending at " << filtered.at(data_point).second.toString("dd/MMMM/yyyy hh:ss");
            all_series.push_back(make_smear_series(filtered, start, data_point));
        }

        previous_value = current_value;

        //Max value checker
        if(current_value > max_value)
        {
            max_value = current_value;
        }

        //Min value checker
        if(current_value < min_value && current_value > 0)
        {
            min_value = current_value;
        }
    }

    // Create both axis

    QDateTimeAxis *time_axis = smear_axis(filtered);

    qDebug() << "X-axis created";

    QValueAxis *value_axis = new QValueAxis;
    value_axis->setRange(0, round_to_nearest(max_value + min_value));
    value_axis->setTitleText("Tonnes");
    value_axis->setTickCount(11);
    value_axis->setGridLineVisible(true);
    value_axis->setLabelFormat("%.1i");

    qDebug() << "Y-axis created";

    // Remove old axises from the chart
    ui->chartView->chart()->removeAxis(ui->chartView->chart()->axisX());

    if(ui->chartView->chart()->axisY())
    {
        ui->chartView->chart()->removeAxis(ui->chartView->chart()->axisY());
    }

    // Add new axises to the chart
    ui->chartView->chart()->addAxis(time_axis, Qt::AlignBottom);
    ui->chartView->chart()->addAxis(value_axis, Qt::AlignLeft);

    qDebug() << "Axises are in the chart";

    for(QLineSeries* point_series : all_series)
    {
        qDebug() << "Looping through series loop";

        ui->chartView->chart()->addSeries(point_series);
        point_series->attachAxis(time_axis);
        point_series->attachAxis(value_axis);

        if(point_series->at(0).y() == 0)
        {
            point_series->setVisible(false);
        }
        else
        {
            qDebug() << point_series->pen();
            point_series->setPen(chart_pen);
        }
    }

    selected_preset_time = Time::Custom;

    qDebug() << "Finished!";


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
    on_applyButton_clicked();
}



//----------------------------------------------------------------------------------------------
// Button slots

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
}

void ChartWindow::on_dayButton_clicked()
{
    quick_time_change(Day);
}

void ChartWindow::on_weekButton_clicked()
{
    quick_time_change(Week);

//    QPixmap p = ui->chartView->grab();// chartView->grab();
//    QOpenGLWidget *glWidget  = graph->findChildren<QOpenGLWidget>();
//    if(glWidget){
//        QPainter painter(&p);
//        QPoint d = glWidget->mapToGlobal(QPoint())-ui->chartView->mapToGlobal(QPoint());
//        painter.setCompositionMode(QPainter::CompositionMode_SourceAtop);
//        painter.drawImage(d, glWidget->grabFramebuffer());
//        painter.end();
//    }
//    p.save("test", "PNG");

//    QString filename = QFileDialog::getSaveFileName(this, tr("Save QChart"), "", tr("Images (*.png)"));
//    QPixmap p = ui->chartView->grab();
//    p.save(filename, "PNG");
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
    date->change_data(view_elements->current_database, view_elements->current_station, view_elements->radioselection_smear);
    date->adjustSize();
    date->show();
}

void ChartWindow::on_applyButton_clicked()
{
    // Send ViewObject pointer to controller
    UserSelections* selections = nullptr;
    DataSource current = view_elements->current_database;
    qDebug() << "Got in apply_button_clicked";

    if(current == DataSource::STATFI && view_elements->radioselection_statfi != DataSet::None)
    {
        selections = new UserSelections(DataSource::STATFI);
        selections->setDataSet(view_elements->radioselection_statfi);
        selections->setStart(Date(1,1,view_elements->selected_time.first.toInt(),0,0));
        selections->setEnd(Date(1,1,view_elements->selected_time.second.toInt(),0,0));

        qDebug().nospace() << "abc" << qPrintable(view_elements->radioselection_statfi) << "def";

        std::vector<std::pair<int, double>> filtered_statfi = Controller::getSTATFIData(selections);
        qDebug() << "Filtered Vecor in Chart Window" << filtered_statfi;

        // Test values
        filtered_statfi.clear();
        filtered_statfi.push_back(std::make_pair(1989, 0.0));
        filtered_statfi.push_back(std::make_pair(1990, 0.0));
        filtered_statfi.push_back(std::make_pair(1991, 300.0));
        filtered_statfi.push_back(std::make_pair(1992, 700.0));
        filtered_statfi.push_back(std::make_pair(1993, 1300.0));
        filtered_statfi.push_back(std::make_pair(1994, 400.0));
        filtered_statfi.push_back(std::make_pair(1995, 2000.0));
        filtered_statfi.push_back(std::make_pair(1996, 800.0));
        filtered_statfi.push_back(std::make_pair(1997, 1700.0));
        filtered_statfi.push_back(std::make_pair(1998, 1400.0));
        filtered_statfi.push_back(std::make_pair(1999, 1100.0));
        filtered_statfi.push_back(std::make_pair(2000, 900.0));
        filtered_statfi.push_back(std::make_pair(2001, 600.0));
        filtered_statfi.push_back(std::make_pair(2002, 500.0));
        filtered_statfi.push_back(std::make_pair(2003, 0.0));
        filtered_statfi.push_back(std::make_pair(2004, 0.0));
        filtered_statfi.push_back(std::make_pair(2005, 2100.0));
        filtered_statfi.push_back(std::make_pair(2006, 2050.0));
        filtered_statfi.push_back(std::make_pair(2007, 1800.0));
        filtered_statfi.push_back(std::make_pair(2008, 1000.0));
        filtered_statfi.push_back(std::make_pair(2009, 950.0));
        filtered_statfi.push_back(std::make_pair(2010, 0.0));
        filtered_statfi.push_back(std::make_pair(2011, 0.0));
        filtered_statfi.push_back(std::make_pair(2012, 0.0));

        display_statfi(filtered_statfi);
    }

    else if(current == DataSource::SMEAR && view_elements->radioselection_smear != DataSet::None && selected_preset_time != Time::No_time)
    {
        qDebug() << "Got in datasource and dataset";
        qDebug() << "Got in custom time";
        selections = new UserSelections(DataSource::SMEAR);
        selections->setMeasuringStation(view_elements->current_station);
        selections->setDataSet(view_elements->radioselection_smear);
        selections->setStart(Date(view_elements->selected_time.first.toStdString()));
        selections->setEnd(Date(view_elements->selected_time.second.toStdString()));
        selections->setAggregateType(view_elements->selected_aggregation);

        std::vector<std::pair<double, QDateTime>> filtered_smear; //= Controller::getSMEARData(selections);

        /*
        QDateTime moment = QDateTime(QDate(2005, 1, 5), QTime(0, 0), QTimeZone(3));
        QDateTime moment_2 = QDateTime(QDate(2005, 2, 5), QTime(6, 0), QTimeZone(3));
        QDateTime moment_3 = QDateTime(QDate(2005, 3, 5), QTime(18, 0), QTimeZone(3));
        QDateTime moment_4 = QDateTime(QDate(2005, 4, 6), QTime(0, 0), QTimeZone(3));
        QDateTime moment_5 = QDateTime(QDate(2005, 5, 6), QTime(6, 0), QTimeZone(3));
        QDateTime moment_6 = QDateTime(QDate(2005, 6, 6), QTime(18, 0), QTimeZone(3));
        QDateTime moment_7 = QDateTime(QDate(2005, 7, 7), QTime(0, 0), QTimeZone(3));
        QDateTime moment_8 = QDateTime(QDate(2005, 8, 7), QTime(6, 0), QTimeZone(3));
        QDateTime moment_9 = QDateTime(QDate(2005, 8, 7), QTime(18, 0), QTimeZone(3));
        QDateTime moment_10 = QDateTime(QDate(2005, 9, 8), QTime(0, 0), QTimeZone(3));
        QDateTime moment_11 = QDateTime(QDate(2005, 10, 8), QTime(6, 0), QTimeZone(3));
        QDateTime moment_12 = QDateTime(QDate(2005, 11, 8), QTime(18, 0), QTimeZone(3));
        QDateTime moment_13 = QDateTime(QDate(2005, 12, 9), QTime(0, 0), QTimeZone(3));
        QDateTime moment_14 = QDateTime(QDate(2005, 12, 9), QTime(6, 0), QTimeZone(3));
        QDateTime moment_15 = QDateTime(QDate(2005, 12, 9), QTime(18, 0), QTimeZone(3));
        QDateTime moment_16 = QDateTime(QDate(2006, 1, 10), QTime(0, 0), QTimeZone(3));

        filtered_smear.push_back(std::make_pair(0.0, moment));
        filtered_smear.push_back(std::make_pair(0.0, moment_2));
        filtered_smear.push_back(std::make_pair(5694.0, moment_3));
        filtered_smear.push_back(std::make_pair(2035.0, moment_4));
        filtered_smear.push_back(std::make_pair(4222.0, moment_5));
        filtered_smear.push_back(std::make_pair(4056.0, moment_6));
        filtered_smear.push_back(std::make_pair(2940.0, moment_7));
        filtered_smear.push_back(std::make_pair(0.0, moment_8));
        filtered_smear.push_back(std::make_pair(0.0, moment_9));
        filtered_smear.push_back(std::make_pair(3567.0, moment_10));
        filtered_smear.push_back(std::make_pair(2345.0, moment_11));
        filtered_smear.push_back(std::make_pair(4567.0, moment_12));
        filtered_smear.push_back(std::make_pair(4320.0, moment_13));
        filtered_smear.push_back(std::make_pair(3209.0, moment_14));
        filtered_smear.push_back(std::make_pair(0.0, moment_15));
        filtered_smear.push_back(std::make_pair(0.0, moment_16));*/

        display_smear(filtered_smear);

    }
    delete selections;
}


//----------------------------------------------------------------------------------------------
// Combo Box slots

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

void ChartWindow::on_actionNewWindow_triggered()
{
    ChartWindow *history = new ChartWindow();
    history->show();
}

void ChartWindow::on_actionCloseWindow_triggered()
{
    this->close();
}
