#include "historywindow.h"
#include "ui_historywindow.h"

historyWindow::historyWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::historyWindow)
{
    ui->setupUi(this);
}

historyWindow::~historyWindow()
{
    delete ui;
}

void historyWindow::on_exit_comp_button_clicked()
{
    this->close();
}



// Time period selection

void historyWindow::on_date_to_comp_button_1_clicked()
{
    date_to_date *date = new date_to_date();
    date->setModal(true);
    date->change_data(ui->data_comp_combo_1->currentText());
    date->show();
}

void historyWindow::on_date_to_comp_button_2_clicked()
{
    date_to_date *date = new date_to_date();
    date->setModal(true);
    date->change_data(ui->data_comp_combo_2->currentText());
    date->show();
}



// Settings

void historyWindow::on_settings_comp_button_clicked()
{
    settingsWindow *settings = new settingsWindow();
    settings->setModal(true);
    settings->show();
}




// Defaulting functions

void historyWindow::default_combo_boxes(int view_index)
{
    if(view_index == 0)
    {
        // Sets the comboboxes to the first index
        ui->data_comp_combo_1->setCurrentIndex(0);
        ui->station_comp_combo_1->setCurrentIndex(0);
    }

    if(view_index == 1)
    {
        // Sets the comboboxes to the first index
        ui->data_comp_combo_2->setCurrentIndex(0);
        ui->station_comp_combo_2->setCurrentIndex(0);
    }
}

void historyWindow::default_check_boxes(int view_index)
{
    if(view_index == 0)
    {
        // Gasses unchecked
        ui->co2_comp_check_1->setChecked(false);
        ui->so2_comp_check_1->setChecked(false);
        ui->nox_comp_check_1->setChecked(false);
        ui->other_comp_check_1->setChecked(false);

        // Min, max, average unchecked
        ui->max_comp_check_1->setChecked(false);
        ui->min_comp_check_1->setChecked(false);
        ui->avg_comp_check_1->setChecked(false);
    }

    if(view_index == 1)
    {
        // Gasses unchecked
        ui->co2_comp_check_2->setChecked(false);
        ui->so2_comp_check_2->setChecked(false);
        ui->nox_comp_check_2->setChecked(false);
        ui->other_comp_check_2->setChecked(false);

        // Min, max, average unchecked
        ui->max_comp_check_2->setChecked(false);
        ui->min_comp_check_2->setChecked(false);
        ui->avg_comp_check_2->setChecked(false);
    }
}

// Default loadout buttons

void historyWindow::on_default_comp_button_1_clicked()
{
    default_combo_boxes(0);
    default_check_boxes(0);
}

void historyWindow::on_default_comp_button_2_clicked()
{
    default_combo_boxes(1);
    default_check_boxes(1);
}

void historyWindow::on_default_all_button_clicked()
{
    on_default_comp_button_1_clicked();
    on_default_comp_button_2_clicked();
}




// Combo boxes

void historyWindow::on_data_comp_combo_1_currentTextChanged(const QString &arg1)
{
    default_check_boxes(0);

    bool min_max;
    bool quick_times;
    QString button_text;

    if(arg1 == "SMEAR")
    {
        min_max = true;
        quick_times = true;
        button_text = "Date-to-Date";
    }

    else // if "STATFI"
    {
        min_max = false;
        quick_times = false;
        button_text = "Year-to_Year";
    }

    //Max, min and average
    ui->max_comp_check_1->setEnabled(min_max);
    ui->min_comp_check_1->setEnabled(min_max);
    ui->avg_comp_check_1->setEnabled(min_max);

    //Quick time selection buttons
    ui->year_comp_button_1->setEnabled(quick_times);
    ui->month_comp_button_1->setEnabled(quick_times);
    ui->week_comp_button_1->setEnabled(quick_times);
    ui->day_comp_button_1->setEnabled(quick_times);

    //Specific time period button changed
    ui->date_to_comp_button_1->setText(button_text);
}

void historyWindow::on_data_comp_combo_2_currentTextChanged(const QString &arg1)
{
    default_check_boxes(1);

    bool min_max;
    bool quick_times;
    QString button_text;

    if(arg1 == "SMEAR")
    {
        min_max = true;
        quick_times = true;
        button_text = "Date-to-Date";
    }

    else // if "STATFI"
    {
        min_max = false;
        quick_times = false;
        button_text = "Year-to_Year";
    }

    //Max, min and average
    ui->max_comp_check_2->setEnabled(min_max);
    ui->min_comp_check_2->setEnabled(min_max);
    ui->avg_comp_check_2->setEnabled(min_max);

    //Quick time selection buttons
    ui->year_comp_button_2->setEnabled(quick_times);
    ui->month_comp_button_2->setEnabled(quick_times);
    ui->week_comp_button_2->setEnabled(quick_times);
    ui->day_comp_button_2->setEnabled(quick_times);

    //Specific time period button changed
    ui->date_to_comp_button_2->setText(button_text);
}
