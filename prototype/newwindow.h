#ifndef NEWWINDOW_H
#define NEWWINDOW_H

#include<QWidget>

namespace Ui {
class NewWindow;
}

class NewWindow : public QWidget
{
    Q_OBJECT

public:
    explicit NewWindow(QWidget *parent = nullptr);
    ~NewWindow();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::NewWindow *ui;
};

#endif // NEWWINDOW_H
