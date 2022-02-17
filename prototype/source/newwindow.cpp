#include "newwindow.h"
#include "ui_NewWindow.h"

NewWindow::NewWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewWindow)
{
    ui->setupUi(this);
}

NewWindow::~NewWindow()
{

}

void NewWindow::on_pushButton_2_clicked()
{
    this->close();
}
