#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QJsonObject>

class Jsonparser
{
public:
    Jsonparser();
    virtual ~Jsonparser();
    virtual void parse(QJsonObject obj);
};

#endif // JSONPARSER_H
