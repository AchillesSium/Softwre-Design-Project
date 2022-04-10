#ifndef TIMEWINDOW_H
#define TIMEWINDOW_H

#include <QDialog>
#include <QRegExpValidator>
#include <QDate>

QT_BEGIN_NAMESPACE
namespace Ui { class TimeWindow; }
QT_END_NAMESPACE

class TimeWindow : public QDialog
{
    Q_OBJECT

public:
    TimeWindow(QWidget *parent = nullptr);
    ~TimeWindow();
    void change_data(QString database_used);
    QDate string_to_date(QString string_date);
    void give_error(QString error);

signals:
    void send_pair(std::pair<QString, QString> time_pair);

private slots:
    void on_cancelButton_clicked();
    void on_showButton_clicked();

private:
    Ui::TimeWindow *ui;

    QRegExpValidator *date_validator;
    QRegExpValidator *year_validator;

    QString current_database;
    QString current_format;

    const QString date_info = "Enter begining and ending dates to determine the desired time period";
    const QString begin_year_label = "Begin year (yyyy)";
    const QString end_year_label = "End year (yyyy)";
    const QString year_info = "Enter begining and ending years to determine the desired time period";

    const QString input_error = "Error: Incorrect input! \nPlease write the input in given format: ";
    const QString date_format = "dd/mm/yyyy";
    const QString year_format = "yyyy";
    const QString month_error = "Error: One or both of the given dates are not possible! \nMake sure given month doesn't have too many days.";
    const QString chronology_date_error = "Error: Begin date comes after end date! \nMake sure begin date takes place before the end date.";
    const QString chronology_year_error = "Error: Begin year comes after end year! \nMake sure begin year takes place before the end year.";
    const QString same_date_error = "Error: Begin date and end date cannot be the same date";
    const QString same_year_error = "Error: Begin year and end year cannot be the same date";

};

#endif // TIMEWINDOW_H
