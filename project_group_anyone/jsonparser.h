#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QVector>
#include <string>
#include <map>

const double NO_VALUE = 0.0;

struct StatfiData{
    double tonnes;
    double intensity;
    double tonnes_indexed;
    double intensity_indexed;
};

using StatfiDB = std::map<int, StatfiData>;

class Jsonparser
{
public:
    Jsonparser();
    ~Jsonparser();
    StatfiDB parse_statfi(QJsonObject obj);
    void parse_smear(QJsonObject obj); // returns a pointer to the smear datastructure when implemented
};

#endif // JSONPARSER_H
