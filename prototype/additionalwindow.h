#ifndef ADDITIONALWINDOW_H
#define ADDITIONALWINDOW_H

#include<QWidget>

class AdditionalWindow : public QWidget
{
    Q_OBJECT

public:
    AdditionalWindow(QWidget *parent);
    ~AdditionalWindow();

private:
    QWidget *parentpointer;
};

#endif // ADDITIONALWINDOW_H
