#include "chartwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChartWindow w;
    w.show();
    return a.exec();
}
