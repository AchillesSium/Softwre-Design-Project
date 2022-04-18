#ifndef TIMEWINDOW_H
#define TIMEWINDOW_H

#include "userselections.h"

#include <QDialog>
#include <QRegExpValidator>
#include <QDate>
#include <QTextCharFormat>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class TimeWindow; }
QT_END_NAMESPACE

class TimeWindow : public QDialog
{
    Q_OBJECT

public:
    TimeWindow(QWidget *parent = nullptr);
    ~TimeWindow();
    QDate determine_min_max(MeasuringStation station, DataSet gas);
    void change_data(DataSource database_used, MeasuringStation station_used, DataSet gas_used);
    QDate string_to_date(QString string_date);
    void give_error(QString error);

signals:
    void send_pair(std::pair<QString, QString> time_pair);

private slots:
    void on_cancelButton_clicked();
    void on_showButton_clicked();
    void on_beginButton_clicked();
    void on_endButton_clicked();
    void on_resetBeginButton_clicked();
    void on_resetEndButton_clicked();

private:
    Ui::TimeWindow *ui;

    QRegExpValidator *year_validator;

    DataSource current_database;
    QString current_format;

    QDate begin_date;
    QDate end_date;
    QDate earliest;

    QTextCharFormat highlight;
    QTextCharFormat plain;

    // For Labels
    const QString empty_date = "Not Selected";

    // For instructing
    const QString date_info = "Enter beginning and ending dates by selecting them from the calendar and then determening if it is the beginning date or the ending date.";
    const QString year_info = "Enter beginning and ending years to determine the desired time period";

    // Errors

        // STATFI
        const QString input_error = "Error: Incorrect input! \nPlease write the input in the given format: ";
        const QString year_format = "yyyy";
        const QString chronology_year_error = "Error: Begin year comes after end year! \nMake sure begin year takes place before the end year.";
        const QString same_year_error = "Error: Begin year and end year cannot be the same date";

        // SMEAR
        const QString calendar_error = "Error: Insufficient selections! \nPlease select both beginning and ending date before submitting the values";

};

#endif // TIMEWINDOW_H
