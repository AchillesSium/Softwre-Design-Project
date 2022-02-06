#ifndef HISTORYWINDOW_H
#define HISTORYWINDOW_H

#include "date_to_date.h"
#include "settingswindow.h"

#include <QMainWindow>

namespace Ui {
class historyWindow;
}

class historyWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit historyWindow(QWidget *parent = nullptr);
    ~historyWindow();
    void default_combo_boxes(int view_index);
    void default_check_boxes(int view_index);

private slots:
    void on_exit_comp_button_clicked();
    void on_date_to_comp_button_1_clicked();
    void on_date_to_comp_button_2_clicked();
    void on_settings_comp_button_clicked();
    void on_default_comp_button_1_clicked();
    void on_default_comp_button_2_clicked();
    void on_default_all_button_clicked();
    void on_data_comp_combo_1_currentTextChanged(const QString &arg1);
    void on_data_comp_combo_2_currentTextChanged(const QString &arg1);

private:
    Ui::historyWindow *ui;
    date_to_date *date;
    settingsWindow *settings;
};

#endif // HISTORYWINDOW_H
