#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_exit_main_button_clicked()
{
    this->close();
}

void MainWindow::on_settings_main_button_clicked()
{
    settingsWindow *settings = new settingsWindow();
    settings->setModal(true);
    settings->show();
}

void MainWindow::on_compare_button_clicked()
{
    historyWindow *history = new historyWindow();
    history->show();
}

void MainWindow::on_date_to_main_button_clicked()
{
    date_to_date *date = new date_to_date();
    date->setModal(true);
    date->change_data(ui->data_main_combo->currentText());
    date->show();
}

void MainWindow::default_combo_boxes()
{
    // Sets the comboboxes to the first index
    ui->data_main_combo->setCurrentIndex(0);
    ui->station_main_combo->setCurrentIndex(0);
}

void MainWindow::default_check_boxes()
{
    // Gasses unchecked
    ui->co2_main_check->setChecked(false);
    ui->so2_main_check->setChecked(false);
    ui->nox_main_check->setChecked(false);
    ui->other_main_check->setChecked(false);

    // Min, max, average unchecked
    ui->max_main_check->setChecked(false);
    ui->min_main_check->setChecked(false);
    ui->avg_main_check->setChecked(false);
}

void MainWindow::on_default_main_button_clicked()
{
    default_combo_boxes();
    default_check_boxes();
}


void MainWindow::on_data_main_combo_currentTextChanged(const QString &arg1)
{
    default_check_boxes();

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
    ui->max_main_check->setEnabled(min_max);
    ui->min_main_check->setEnabled(min_max);
    ui->avg_main_check->setEnabled(min_max);

    //Quick time selection buttons
    ui->year_main_button->setEnabled(quick_times);
    ui->month_main_button->setEnabled(quick_times);
    ui->week_main_button->setEnabled(quick_times);
    ui->day_main_button->setEnabled(quick_times);

    //Specific time period button changed
    ui->date_to_main_button->setText(button_text);
}
