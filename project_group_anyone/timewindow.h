#ifndef TIMEWINDOW_H
#define TIMEWINDOW_H

#include <QDialog>
#include <QRegExpValidator>

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
    void add_text(QString text);

signals:
    void send_pair(std::pair<QString, QString> time_pair);

private slots:
    void on_cancelButton_clicked();
    void on_showButton_clicked();

private:
    Ui::TimeWindow *ui;

    QRegExpValidator *date_validator;
    QRegExpValidator *year_validator;

};

#endif // TIMEWINDOW_H
