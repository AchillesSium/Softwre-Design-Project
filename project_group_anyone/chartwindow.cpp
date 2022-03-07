#include "chartwindow.h"
#include "ui_chartwindow.h"

ChartWindow::ChartWindow(QWidget *parent) :
      QMainWindow(parent),
      ui(new Ui::ChartWindow),
      checker(new Checker)
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
    current_time = Day;

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

    ui->co2Box->blockSignals(true);
    ui->so2Box->blockSignals(true);
    ui->noxBox->blockSignals(true);

    ui->co2Box->setChecked(true);
    ui->so2Box->setChecked(true);
    ui->noxBox->setChecked(true);

    ui->co2Box->blockSignals(false);
    ui->so2Box->blockSignals(false);
    ui->noxBox->blockSignals(false);

    checker->checkbox_1 = true;
    checker->checkbox_2 = true;
    checker->checkbox_3 = true;
    checker->checkbox_4 = false;


    // Set correct combo box and stacked widget
    ui->databaseCombo->blockSignals(true);
    ui->databaseCombo->setCurrentText("SMEAR");
    ui->stackedBoxes->setCurrentIndex(0);
    ui->databaseCombo->blockSignals(false);

}

ChartWindow::~ChartWindow()
{
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
    QString current_text = ui->databaseCombo->currentText();
    if(current_text == "SMEAR")
    {
        // Gasses checked
        ui->co2Box->setChecked(false);
        ui->so2Box->setChecked(false);
        ui->noxBox->setChecked(false);
        ui->otherBox->setChecked(false);
    }
    else if(current_text == "STATFI")
    {
        // Intensity and indexes checked
        ui->co2DataBox->setChecked(false);
        ui->intBox->setChecked(false);
        ui->indexBox->setChecked(false);
        ui->indexIntBox->setChecked(false);
    }

    // Min, max, average unchecked
    ui->maxBox->setChecked(false);
    ui->minBox->setChecked(false);
    ui->avgBox->setChecked(false);

    // Inform the struct
    checker->checkbox_1 = false;
    checker->checkbox_2 = false;
    checker->checkbox_3 = false;
    checker->checkbox_4 = false;
    checker->checkbox_max = false;
    checker->checkbox_min = false;
    checker->checkbox_avg = false;
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
    QtCharts::QAbstractSeries *current_pointer = pointers.at(current_time);
    QList<QAbstractSeries*> all_series = ui->chartView->chart()->series();
    QList<QAbstractSeries*>::iterator all;

    all = std::find(all_series.begin(), all_series.end(), current_pointer);

    if(state == true && all == all_series.end())
    {
       add_graph_series(pointers.at(current_time));
    }
    else if(state == false && all != all_series.end())
    {
        remove_graph_series(pointers.at(current_time));
    }
}

void ChartWindow::quick_time_change(Time period)
{

    if(current_time == period)
    {
        return;
    }

    if(ui->co2Box->isChecked())
    {
        remove_graph_series(co2_series.at(current_time));
    }

    if(ui->so2Box->isChecked())
    {
        remove_graph_series(so2_series.at(current_time));
    }

    if(ui->noxBox->isChecked())
    {
        remove_graph_series(nox_series.at(current_time));
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
    }

    axis_x->setMax(max_tick);
    axis_x->setTickCount(max_tick);
    axis_x->setTitleText(title_text);
    axis_x->setGridLineVisible(true);
    axis_x->setLabelFormat("%.1i");
    ui->chartView->chart()->addAxis(axis_x, Qt::AlignBottom);
    current_time = period;

    if(ui->co2Box->isChecked())
    {
        add_graph_series(co2_series.at(current_time));
    }

    if(ui->so2Box->isChecked())
    {
        add_graph_series(so2_series.at(current_time));
    }

    if(ui->noxBox->isChecked())
    {
        add_graph_series(nox_series.at(current_time));
    }
}


//==============================================================================================
//SLOTS

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
    date->setModal(true);
    date->change_data(ui->databaseCombo->currentText());
    date->show();
}

void ChartWindow::on_applyButton_clicked()
{
    for(unsigned int box_count = 0; box_count < 4; box_count++)
    {
        switch(box_count)
        {
        case FirstBox:
            // TODO Fetch the correct information and display it on the graph
            react_to_checkbox(checker->checkbox_1, co2_series);
            break;

        case SecondBox:
            // TODO -||-
            react_to_checkbox(checker->checkbox_2, so2_series);
            break;

        case ThirdBox:
            // TODO -||-
            react_to_checkbox(checker->checkbox_3, nox_series);
            break;

        case FourthBox:
            // TODO -||-
            break;
        }
    }
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
        break;

    case SMEAR:
        min_max = true;
        quick_times = true;
        button_text = "Date-to-Date";
        widget = ui->stackedBoxes->widget(0);
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


//----------------------------------------------------------------------------------------------
// Check Box slots

void ChartWindow::on_co2Box_clicked(bool state)
{
    checker->checkbox_1 = state;
}

void ChartWindow::on_so2Box_clicked(bool state)
{
    checker->checkbox_2 = state;
}

void ChartWindow::on_noxBox_clicked(bool state)
{
    checker->checkbox_3 = state;
}

void ChartWindow::on_otherBox_clicked(bool state)
{
    checker->checkbox_4 = state;
}

void ChartWindow::on_co2DataBox_clicked(bool state)
{
    checker->checkbox_1 = state;
}

void ChartWindow::on_intBox_clicked(bool state)
{
    checker->checkbox_2 = state;
}

void ChartWindow::on_indexBox_clicked(bool state)
{
    checker->checkbox_3 = state;
}

void ChartWindow::on_indexIntBox_clicked(bool state)
{
    checker->checkbox_4 = state;
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
