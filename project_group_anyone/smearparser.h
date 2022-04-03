#ifndef SMEARPARSER_H
#define SMEARPARSER_H

#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QVector>
#include <string>
#include <map>
#include <utility>
#include "jsonparser.h"

enum SMEAR_stations {Varrio = 1, Hyytiala = 2, Kumpula = 3}; // same as the station id:s

using DataPoint = std::pair<long double, QDate>;

struct SmearData{
    std::vector<DataPoint> CO2;
    std::vector<DataPoint> SO2;
    std::vector<DataPoint> NOX;
};

using SmearDB = std::map<int, SmearData>;


class SmearParser: public Jsonparser
{
public:
    SmearParser();
    ~SmearParser();
    void parse(QJsonObject obj);
    SmearDB get_db();
private:
    SmearDB smear_db_;
    std::vector<DataPoint> get_table_data(QString table_name, QJsonArray data_arr);
};

#endif // SMEARPARSER_H
