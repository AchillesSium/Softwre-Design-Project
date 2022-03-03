#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QJsonObject>
#include <QJsonArray>
#include <string>
#include <map>

const double temp = -1;

struct StatfiData{
    double tonnes = temp;
    double intensity = temp;
    double indexed = temp;
    double intensity_indexed = temp;
};

using StatfiDB = std::map<int, StatfiData>;

class Jsonparser
{
public:
    Jsonparser();
    ~Jsonparser();
    void parse(QJsonObject obj, std::string db);
};

#endif // JSONPARSER_H
