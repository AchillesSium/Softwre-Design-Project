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

int main(int argc, char *argv[])
{
    /* Testing Data object comparisons
    Date* d1 = new Date(1,1,1,0,0);
    Date* d2 = new Date(1,1,1,0,0);
    Date* d3 = new Date(5,10,2000,15,30);
    Date* d4 = new Date(5,10,2000,14,0);
    Date* d5 = new Date(6,10,1999,14,0);

    std::cout << std::to_string(d1->getDay()) + "." + std::to_string(d1->getMonth()) + "." + std::to_string(d1->getYear())
                 + " " + std::to_string(d1->getHour()) + ":" + std::to_string(d1->getMinute()) << std::endl;

    std::cout << std::to_string(d2->getDay()) + "." + std::to_string(d2->getMonth()) + "." + std::to_string(d2->getYear())
                 + " " + std::to_string(d2->getHour()) + ":" + std::to_string(d2->getMinute()) << std::endl;

    std::cout << std::to_string(d3->getDay()) + "." + std::to_string(d3->getMonth()) + "." + std::to_string(d3->getYear())
                 + " " + std::to_string(d3->getHour()) + ":" + std::to_string(d3->getMinute()) << std::endl;

    std::cout << std::to_string(d4->getDay()) + "." + std::to_string(d4->getMonth()) + "." + std::to_string(d4->getYear())
                 + " " + std::to_string(d4->getHour()) + ":" + std::to_string(d4->getMinute()) << std::endl;

    std::cout << (*d1 == *d2) << std::endl;     // 1
    std::cout << (*d1 == *d3) << std::endl;     // 0
    std::cout << (*d3 > *d2) << std::endl;      // 1
    std::cout << (*d4 < *d2) << std::endl;      // 0
    std::cout << (*d3 != *d4) << std::endl;     // 1
    std::cout << (*d4 <= *d3) << std::endl;     // 1
    std::cout << (*d5 >= *d4) << std::endl;     // 0

    delete d1;
    delete d2;
    delete d3;
    delete d4;
    delete d5;
    */

    QApplication a(argc, argv);
    ChartWindow w;
    w.show();

    statfinetworkcall *statfinetwork = new statfinetworkcall();
    smearnetworkcall *smearnetwork = new smearnetworkcall();

    statfinetwork->queryStatFi();

    // wait for the request to process completely
    QEventLoop statfi_loop;
    QObject::connect(statfinetwork, SIGNAL(done()), &statfi_loop, SLOT(quit()));
    statfi_loop.exec();


    //smearnetwork->querySmearStations();
    /**
    smearnetwork->querySmearTimeSeries("MAX", 60, "2013-01-01", "2022-01-01", "KUM_EDDY.av_c_ep");

    QEventLoop smear_loop;
    QObject::connect(smearnetwork, SIGNAL(done()), &smear_loop, SLOT(quit()));
    smear_loop.exec();
    **/

    QJsonObject obj = statfinetwork->getObject();

    if(obj["class"] == QJsonValue::Undefined ){
        qDebug() << "error happened";
    }
    else{

        StatfiParser *parser = new StatfiParser();
        parser->parse(obj);
      /*
         * for (const auto &[k, v] : statfi_db)
            qDebug() << "m[" << k << "] = (" << v.intensity << ", " << v.intensity_indexed << ") ";*/
        DataStorage& storage = DataStorage::get();

        storage.setStatfiDB(parser->get_db());
        storage.setStatfiDBmin(parser->get_db().begin()->first);
        storage.setStatfiDBmax(parser->get_db().rbegin()->first);


        delete parser;
    }

    delete statfinetwork;

    return a.exec();
}
