#include "date_to_date.h"
#include "ui_date_to_date.h"

date_to_date::date_to_date(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::date_to_date)
{
    ui->setupUi(this);
    ui->instructions_edit->setReadOnly(true);
}

date_to_date::~date_to_date()
{
    delete ui;
}

void date_to_date::change_data(QString database_used)
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
    ui->begin_label->setText(begin_label);
    ui->end_label->setText(end_label);
    ui->instructions_edit->document()->setPlainText(instructions_text);
}

void date_to_date::on_cancel_date_button_clicked()
{
    this->close();
}


