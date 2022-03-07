#include "timewindow.h"
#include "ui_timewindow.h"

TimeWindow::TimeWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimeWindow)
{
    ui->setupUi(this);
}

TimeWindow::~TimeWindow()
{
    delete ui;
}

void TimeWindow::change_data(QString database_used)
{
    QString begin_label;
    QString end_label;
    QString instructions_text;

    if(database_used == "STATFI")
    {
        begin_label = "Begin year (yyyy)";
        end_label = "End year (yyyy)";
        instructions_text = "Enter begining and ending years to determine the desired time period";
    }

    else // if "SMEAR"
    {
        begin_label = "Begin date (dd/mm/yyyy)";
        end_label = "End year (dd/mm/yyyy)";
        instructions_text = "Enter begining and ending dates to determine the desired time period";
    }

    //Labels
    ui->beginLabel->setText(begin_label);
    ui->endLabel->setText(end_label);
    ui->infoBrowser->document()->setPlainText(instructions_text);
}

void TimeWindow::on_cancel_date_button_clicked()
{
    this->close();
}


