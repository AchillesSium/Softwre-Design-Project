#ifndef STATFIPARSER_H
#define STATFIPARSER_H

#include <QJsonObject>
#include <QJsonArray>
#include <QVector>
#include <string>
#include <map>
#include "jsonparser.h"


const double NO_VALUE = 0.0;

struct StatfiData{
    double tonnes;
    double intensity;
    double tonnes_indexed;
    double intensity_indexed;
};

using StatfiDB = std::map<int, StatfiData>;


class StatfiParser: public Jsonparser
{
public:
    StatfiParser();
    ~StatfiParser();
    void parse(QJsonObject obj);
    StatfiDB get_db();
private:
    StatfiDB statfi_db_;
};

#endif // STATFIPARSER_H
