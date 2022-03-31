#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QVector>
#include <string>
#include <map>
#include <utility>

class Jsonparser
{
public:
    Jsonparser();
    virtual ~Jsonparser();
    virtual void parse(QJsonObject obj);
};

#endif // JSONPARSER_H
