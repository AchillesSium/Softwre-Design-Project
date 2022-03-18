#include "mainwindow.h"
#include "networkcalls.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    networkcalls nc;
    QString str;
    nc.queryStatFi(str);
    QApplication a(argc, argv);
    MainWindow window;
    window.show();
    return a.exec();
}
