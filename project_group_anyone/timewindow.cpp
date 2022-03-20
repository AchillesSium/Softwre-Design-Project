#include "timewindow.h"
#include "ui_timewindow.h"

TimeWindow::TimeWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimeWindow)
{
    ui->setupUi(this);

    QRegExp date("(0[1-9]|[12][1-9]|3[01])/(0[1-9]|1[0-2])/(19[0-9][0-9]|20[0-2][0-2]|200[0-9])");
    date_validator = new QRegExpValidator(date, this);
    ui->beginEdit->setValidator(date_validator);
    ui->endEdit->setValidator(date_validator);

    QRegExp year("(19[0-9][0-9]|200[0-9]|201[0-9]|202[0-2])");
    year_validator = new QRegExpValidator(year, this);
}

TimeWindow::~TimeWindow()
{
    delete date_validator;
    delete year_validator;
    delete ui;
}

void TimeWindow::change_data(QString database_used)
{
    QString begin_label;
    QString end_label;
    QString instructions_text;
    QRegExpValidator *validator;

    if(database_used == "STATFI")
    {
        begin_label = begin_year_label;
        end_label = end_year_label;
        instructions_text = year_info;
        validator = year_validator;
        current_format = year_format;
    }

    else // if "SMEAR"
    {
        begin_label = begin_date_label;
        end_label = end_date_label;
        instructions_text = date_info;
        validator = date_validator;
        current_format = date_format;
    }

    // Update current database
    current_database = database_used;

    // Line edit boxes
    ui->beginEdit->setValidator(validator);
    ui->endEdit->setValidator(validator);

    // Labels
    ui->beginLabel->setText(begin_label);
    ui->endLabel->setText(end_label);

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
        QDate begin_date = string_to_date(begin);
        QDate end_date = string_to_date(end);

        if(!begin_date.isValid() || !end_date.isValid())
        {
            give_error(month_error);
            return;
        }
        else if(begin_date > end_date)
        {
            give_error(chronology_date_error);
            return;
        }
        else if(begin_date == end_date)
        {
           give_error(same_date_error);
           return;
        }
    }

    std::pair<QString, QString> time_zone = std::make_pair(begin, end);
    emit send_pair(time_zone);
    on_cancelButton_clicked();
}

void TimeWindow::on_cancelButton_clicked()
{
    this->close();
}

