#include "timewindow.h"
#include "ui_timewindow.h"

TimeWindow::TimeWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimeWindow)
{
    ui->setupUi(this);

    ui->calendar->setGridVisible(true);
    ui->calendar->setMaximumDate(ui->calendar->selectedDate());

    earliest = QDate(1900, 1, 1);
    ui->calendar->setMinimumDate(earliest);

    highlight = QTextCharFormat();
    highlight.setFontWeight(QFont::Black);
    highlight.setBackground(QColor(0, 190, 0));
    highlight.setForeground(QColor(255, 255, 255));

    plain = ui->calendar->dateTextFormat(earliest.currentDate());

    QRegExp year("(19[0-9][0-9]|200[0-9]|201[0-9]|202[0-2])");
    year_validator = new QRegExpValidator(year, this);
    ui->beginEdit->setValidator(year_validator);
    ui->endEdit->setValidator(year_validator);

    ui->infoEdit->setReadOnly(true);
}

TimeWindow::~TimeWindow()
{
    delete year_validator;
    delete ui;
}

void TimeWindow::change_data(QString database_used)
{
    QString instructions_text;

    if(database_used == "STATFI")
    {
        instructions_text = year_info;
        current_format = year_format;
        ui->stackedSelection->setCurrentWidget(ui->statfi_query);
    }

    else // if "SMEAR"
    {
        instructions_text = date_info;
        ui->stackedSelection->setCurrentWidget(ui->smear_query);
    }

    // Update current database
    current_database = database_used;

    // Browser
    ui->infoEdit->setTextColor(Qt::black);
    ui->infoEdit->append(instructions_text + "\n");
}


QDate TimeWindow::string_to_date(QString string_date)
{
    QDate date = QDate::fromString(string_date, "dd/MM/yyyy");
    return date;
}

void TimeWindow::give_error(QString error)
{
    ui->infoEdit->setTextColor(Qt::red);
    ui->infoEdit->append(error + "\n");
}

// SLOTS
//------------------------------------------------------------------------------------------------------

void TimeWindow::on_showButton_clicked()
{
    if(!ui->beginEdit->hasAcceptableInput() || !ui->endEdit->hasAcceptableInput())
    {
        give_error(input_error + current_format);
        return;
    }

    QString begin = ui->beginEdit->text();
    QString end = ui->endEdit->text();

    if(current_database == "STATFI")
    {
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
    else
    {
        begin = begin_date.toString("dd/MM/yyyy");
        end = end_date.toString("dd/MM/yyyy");
    }

    std::pair<QString, QString> time_zone = std::make_pair(begin, end);
    emit send_pair(time_zone);
    on_cancelButton_clicked();
}

void TimeWindow::on_cancelButton_clicked()
{
    this->close();
}


void TimeWindow::on_beginButton_clicked()
{
    begin_date = ui->calendar->selectedDate();
    ui->calendar->setDateTextFormat(begin_date, highlight);

    if(end_date.isNull())
    {

        QDate max_date = begin_date.addYears(10);

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
        QDate min_date = end_date.addYears(-10);

        if(min_date < earliest)
        {
            min_date = earliest;
        }

        ui->calendar->setMinimumDate(min_date);
    }

    ui->calendar->setMaximumDate(end_date);
    ui->endDate->setText(end_date.toString("dd/MM/yyyy"));
}

void TimeWindow::on_resetBeginButton_clicked()
{
    if(begin_date != end_date)
    {
        ui->calendar->setDateTextFormat(begin_date, plain);
    }

    begin_date = QDate();
    ui->calendar->setMinimumDate(earliest);
    ui->beginDate->setText(empty_date);
}

void TimeWindow::on_resetEndButton_clicked()
{
    if(begin_date != end_date)
    {
        ui->calendar->setDateTextFormat(end_date, plain);
    }

    end_date = QDate();
    ui->calendar->setMaximumDate(end_date.currentDate());
    ui->endDate->setText(empty_date);
}

