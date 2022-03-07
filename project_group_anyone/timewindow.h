#ifndef TIMEWINDOW_H
#define TIMEWINDOW_H

#include <QDialog>

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

private slots:
    void on_cancel_date_button_clicked();

private:
    Ui::TimeWindow *ui;
};

#endif // TIMEWINDOW_H
