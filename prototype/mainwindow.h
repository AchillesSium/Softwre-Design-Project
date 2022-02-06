#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"settingswindow.h"
#include"historywindow.h"

#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void default_combo_boxes();
    void default_check_boxes();

private slots:
    void on_exit_main_button_clicked();
    void on_settings_main_button_clicked();
    void on_compare_button_clicked();
    void on_date_to_main_button_clicked();
    void on_default_main_button_clicked();
    void on_data_main_combo_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    settingsWindow *settings;
    historyWindow *history;
    date_to_date *date;

};
#endif // MAINWINDOW_H
