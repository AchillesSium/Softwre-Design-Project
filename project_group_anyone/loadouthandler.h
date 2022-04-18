#ifndef LOADOUTHANDLER_H
#define LOADOUTHANDLER_H


#include "userselections.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

class LoadoutHandler
{
public:
    LoadoutHandler();
    ~LoadoutHandler();
    void save(DataSource db, MeasuringStation mstat, DataSet ds_statfi, DataSet ds_smear, std::string date_start, std::string date_end, AggregateType aggtype);
    void load();
};

#endif // LOADOUTHANDLER_H
