#ifndef DATE_TO_DATE_H
#define DATE_TO_DATE_H

#include <QWidget>
#include <QDialog>

namespace Ui {
class date_to_date;
}

class date_to_date : public QDialog
{
    Q_OBJECT

public:
    explicit date_to_date(QWidget *parent = nullptr);
    ~date_to_date();
    void change_data(QString database_used);

private slots:
    void on_cancel_date_button_clicked();

private:
    Ui::date_to_date *ui;
};

#endif // DATE_TO_DATE_H
