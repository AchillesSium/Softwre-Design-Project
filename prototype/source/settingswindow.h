#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QWidget>
#include <QDialog>

namespace Ui {
class settingsWindow;
}

class settingsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit settingsWindow(QWidget *parent = nullptr);
    ~settingsWindow();

private slots:
    void on_exit_settings_button_clicked();

private:
    Ui::settingsWindow *ui;
};

#endif // SETTINGSWINDOW_H
