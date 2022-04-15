#ifndef STATFIPARSER_H
#define STATFIPARSER_H

#include <QJsonObject>
#include <QJsonArray>
#include <QVector>
#include <string>
#include <map>
#include <vector>
#include "jsonparser.h"
#include "datastorage.h"


class StatfiParser: public Jsonparser
{
public:
    StatfiParser();
    ~StatfiParser();
    void parse(QJsonObject obj);
private:
    StatfiDB statfi_db_;
};

#endif // STATFIPARSER_H
