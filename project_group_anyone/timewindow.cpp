#include "timewindow.h"
#include "ui_timewindow.h"

TimeWindow::TimeWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimeWindow)
{
    ui->setupUi(this);
    ui->beginButton->setAutoDefault(false);
    ui->endButton->setAutoDefault(false);
}

TimeWindow::~TimeWindow()
{
    delete year_validator;
    delete ui;
}

/**
 * @brief TimeWindow::change_data
 *        Method sets up the TimeWindow to represent the correct database for SMEAR and STATFI can't use
 *        the same selection for time span selection. STATFI only uses the @param database_used to determine
 *        current database truly is STATFI. However if the database is SMEAR method also needs @param station_used
 *        and @param gas_used to determine limits for the time span the user can make.
 */
void TimeWindow::change_data(DataSource database_used, MeasuringStation station_used, DataSet gas_used)
{
    QString instructions_text;
    QWidget* widget;

    if(database_used == DataSource::STATFI)
    {
        // Set validator
        QRegExp year("(199[0-9]|200[0-9])|201[0-6]");
        year_validator = new QRegExpValidator(year, this);
        ui->beginEdit->setValidator(year_validator);
        ui->endEdit->setValidator(year_validator);

        // Set variables
        ui->beginYear->setText("Begin year [format: yyyy] [minimum: 1990]");
        ui->endYear->setText("End year [format: yyyy] [maximum: 2016]");
        instructions_text = year_info;
        current_format = year_format;
        widget = ui->statfi_query;
    }

    else // if "SMEAR"
    {
        // Set calendar
        ui->calendar->setGridVisible(true);
        ui->calendar->setMaximumDate(ui->calendar->selectedDate());

        QDate min = determine_min_max(station_used, gas_used);
        earliest = min;
        ui->calendar->setMinimumDate(earliest);

        // Create highlight
        highlight = QTextCharFormat();
        highlight.setFontWeight(QFont::Black);
        highlight.setBackground(QColor(0, 190, 0));
        highlight.setForeground(QColor(255, 255, 255));

        // Set plain format
        plain = ui->calendar->dateTextFormat(earliest.currentDate());

        // Set variables
        instructions_text = date_info;
        widget = ui->smear_query;
    }

    // Update current database
    current_database = database_used;

    // Set widget
    ui->stackedSelection->setCurrentWidget(widget);

    // Browser
    ui->infoEdit->setTextColor(Qt::black);
    ui->infoEdit->setReadOnly(true);
    ui->infoEdit->append(instructions_text + "\n");
}

/**
 * @brief TimeWindow::string_to_date
 *        Simple method that changes QString @param string_date into a QDate.
 * @return
 *        Method returns the finished QDate.
 */
QDate TimeWindow::string_to_date(QString string_date)
{
    QDate date = QDate::fromString(string_date, "dd/MM/yyyy");
    return date;
}

/**
 * @brief TimeWindow::give_error
 *        Method displays the given error @param error in the TimeWindow in a different colour than
 *        the instructions are given.
 */
void TimeWindow::give_error(QString error)
{
    ui->infoEdit->setTextColor(Qt::red);
    ui->infoEdit->append(error + "\n");
}

/**
 * @brief TimeWindow::determine_min_max
 *        This method uses @param station and @param gas to determine which is the correct
 *        starting date for the calendar.
 * @return
 *        Returns the correct date in form of a QDate object.
 */
QDate TimeWindow::determine_min_max(MeasuringStation station, DataSet gas)
{
    QDate min;

    switch(station)
    {
    case(MeasuringStation::Varrio):
        switch(gas)
        {
        case(DataSet::CO2):
            min = QDate(2012, 4, 22);
            break;
        case(DataSet::SO2):
            min = QDate(1998, 1, 1);
            break;
        case(DataSet::NO):
            min = QDate(1998, 1, 1);
            break;
        default:
            break;
        }
        break;

    case(MeasuringStation::Hyytiala):
        switch(gas)
        {
        case(DataSet::CO2):
            min = QDate(2011, 11, 2);
            break;
        case(DataSet::SO2):
            min = QDate(1997, 1, 25);
            break;
        case(DataSet::NO):
            min = QDate(1997, 1, 1);
            break;
        default:
            break;
        }
        break;

    case(MeasuringStation::Kumpula):
        switch(gas)
        {
        case(DataSet::CO2):
            min = QDate(2013, 10, 1);
            break;
        case(DataSet::SO2):
            min = QDate(2006, 9, 22);
            break;
        case(DataSet::NO):
            min = QDate(2005, 11, 25);
            break;
        default:
            break;
        }
        break;

    default:
        min = QDate(1900, 1, 1);
        break;
    }

    return min;
}

// SLOTS
//------------------------------------------------------------------------------------------------------

/**
 * @brief TimeWindow::on_showButton_clicked
 *        Method checks if the data user has given is correct and gives errors accordingly. If all data
 *        is in place an in correct forms the method sends the data to ChartWindow and closes the TimeWindow.
 */
void TimeWindow::on_showButton_clicked()
{
    QString begin;
    QString end;

    if(current_database == DataSource::STATFI)
    {
        begin = ui->beginEdit->text();
        end = ui->endEdit->text();

        if(!ui->beginEdit->hasAcceptableInput() || !ui->endEdit->hasAcceptableInput())
        {
            give_error(input_error + current_format);
            return;
        }

        if(begin > end)
        {
            give_error(chronology_year_error);
            return;
        }
        else if(begin == end)
        {
            give_error(same_year_error);
            return;
        }
    }
    else // SMEAR
    {
        if(begin_date.isNull() || end_date.isNull())
        {
            give_error(calendar_error);
            return;
        }
       else
        {
            begin = begin_date.toString("dd/MM/yyyy");
            end = end_date.toString("dd/MM/yyyy");
        }
    }

    std::pair<QString, QString> time_zone = std::make_pair(begin, end);
    emit send_pair(time_zone);
    on_cancelButton_clicked();
}

/**
 * @brief TimeWindow::on_cancelButton_clicked
 *        Closes the TimeWindow. This returns the user to the ChartWindow view but no time span has
 *        been determined yet
 */
void TimeWindow::on_cancelButton_clicked()
{
    this->close();
}

/**
 * @brief TimeWindow::on_beginButton_clicked (and on_endButton_clicked())
 *        Slot saves the currently selected calendar date to memory and displays it to the user.
 *        The new limits caused by the selection are also set. The maximum timespan for SMEAR is one
 *        year.
 */
void TimeWindow::on_beginButton_clicked()
{
    begin_date = ui->calendar->selectedDate();
    ui->calendar->setDateTextFormat(begin_date, highlight);

    if(end_date.isNull())
    {

        QDate max_date = begin_date.addYears(1);

        if(begin_date.currentDate() < max_date)
        {
            max_date = begin_date.currentDate();
        }

        ui->calendar->setMaximumDate(max_date);
    }

    ui->calendar->setMinimumDate(begin_date);
    ui->beginDate->setText(begin_date.toString("dd/MM/yyyy"));
}

void TimeWindow::on_endButton_clicked()
{
    end_date = ui->calendar->selectedDate();
    ui->calendar->setDateTextFormat(end_date, highlight);

    if(begin_date.isNull())
    {
        QDate min_date = end_date.addYears(-1);

        if(min_date < earliest)
        {
            min_date = earliest;
        }

        ui->calendar->setMinimumDate(min_date);
    }

    ui->calendar->setMaximumDate(end_date);
    ui->endDate->setText(end_date.toString("dd/MM/yyyy"));
}

/**
 * @brief TimeWindow::on_resetBeginButton_clicked (and on_resetEndButton_clicked)
 *        Method resets the previously selected date to null date object. This also resets the limits for
 *        the calendar.
 */
void TimeWindow::on_resetBeginButton_clicked()
{
    if(begin_date != end_date)
    {
        ui->calendar->setDateTextFormat(begin_date, plain);
    }

    if(end_date.isNull())
    {
        ui->calendar->setMinimumDate(earliest);
    }
    else
    {
        ui->calendar->setMinimumDate(end_date.addYears(-1));
    }

    begin_date = QDate();
    ui->beginDate->setText(empty_date);
}

void TimeWindow::on_resetEndButton_clicked()
{
    if(begin_date != end_date)
    {
        ui->calendar->setDateTextFormat(end_date, plain);
    }

    if(begin_date.isNull())
    {
        ui->calendar->setMaximumDate(earliest.currentDate());
    }
    else
    {
        ui->calendar->setMaximumDate(begin_date.addYears(1));
    }

    end_date = QDate();
    ui->endDate->setText(empty_date);
}

