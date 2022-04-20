#include "chartwindow.h"

#include <QApplication>
#include <QJsonObject>
#include <QDebug>
#include <QEventLoop>

#include "date.h"
#include <iostream>
#include <string>
#include "statfinetworkcall.h"
#include "smearnetworkcall.h"
#include "jsonparser.h"
#include <QDebug>
#include "controller.h"
#include "datastorage.h"
#include "smearparser.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChartWindow w;
    w.show();

    statfinetworkcall *statfinetwork = new statfinetworkcall();

    statfinetwork->query();

    // wait for the request to process completely
    QEventLoop statfi_loop;
    QObject::connect(statfinetwork, SIGNAL(done()), &statfi_loop, SLOT(quit()));
    statfi_loop.exec();

    QJsonObject obj = statfinetwork->getObject();

    if(obj["class"] == QJsonValue::Undefined )
    {
        qDebug() << "error happened";
    }
    else
    {

        StatfiParser *parser = new StatfiParser();
        parser->parse(obj);
        delete parser;
    }

    delete statfinetwork;
    return a.exec();
}
