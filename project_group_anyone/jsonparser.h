#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QVector>
#include <string>
#include <map>

class Jsonparser
{
public:
    Jsonparser();
    ~Jsonparser();
    void parse_statfi(QJsonObject obj);
    void parse_smear(QJsonObject obj);
};

#endif // JSONPARSER_H
