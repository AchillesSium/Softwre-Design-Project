#include "timewindow.h"
#include "ui_timewindow.h"

TimeWindow::TimeWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimeWindow)
{
    ui->setupUi(this);

    QRegExp date("(0[1-9]|[12][1-9]|3[01])/(0[1-9]|1[0-2])/(19[0-9][0-9]|20[0-2][0-2])");
    date_validator = new QRegExpValidator(date, this);
    ui->beginEdit->setValidator(date_validator);
    ui->endEdit->setValidator(date_validator);

    QRegExp year("(19[0-9][0-9]|20[0-2][0-2])");
    year_validator = new QRegExpValidator(year, this);
}

TimeWindow::~TimeWindow()
{
    delete date_validator;
    delete year_validator;
    delete ui;
}

void TimeWindow::add_text(QString text)
{
    QTextCursor cursor = ui->infoBrowser->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->infoBrowser->setTextCursor(cursor);
    ui->infoBrowser->setPlainText(text);
}

void TimeWindow::change_data(QString database_used)
{
    QString begin_label;
    QString end_label;
    QString instructions_text;
    QRegExpValidator *validator;

    if(database_used == "STATFI")
    {
        begin_label = "Begin year (yyyy)";
        end_label = "End year (yyyy)";
        instructions_text = "Enter begining and ending years to determine the desired time period";
        validator = year_validator;
    }

    else // if "SMEAR"
    {
        begin_label = "Begin date (dd/mm/yyyy)";
        end_label = "End year (dd/mm/yyyy)";
        instructions_text = "Enter begining and ending dates to determine the desired time period";
        validator = date_validator;
    }

    // Line edit boxes
    ui->beginEdit->setValidator(validator);
    ui->endEdit->setValidator(validator);

    // Labels
    ui->beginLabel->setText(begin_label);
    ui->endLabel->setText(end_label);

    // Browser
    ui->infoBrowser->setTextColor(Qt::black);
    add_text(instructions_text + "\n");
}

void TimeWindow::on_showButton_clicked()
{
    // Doesn't yet check if values are cronological
    if(ui->beginEdit->hasAcceptableInput() == true || ui->endEdit->hasAcceptableInput() == true)
    {
        QString begin = ui->beginEdit->text();
        QString end = ui->endEdit->text();
        std::pair<QString, QString> time_zone = std::make_pair(begin, end);
        emit send_pair(time_zone);
        this->close();
    }
    else
    {
        ui->infoBrowser->setTextColor(Qt::red);
        add_text("Error: Incorrect input! \nPlease write the input in given format: dd/mm/yyyy");
    }
}

void TimeWindow::on_cancelButton_clicked()
{
    this->close();
}

