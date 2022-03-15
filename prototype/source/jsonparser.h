#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QJsonObject>
#include <QJsonArray>
#include <string>
#include <map>

const double TEMP = -1;

struct StatfiData{
    double tonnes = TEMP;
    double intensity = TEMP;
    double tonnes_indexed = TEMP;
    double intensity_indexed = TEMP;
};

using StatfiDB = std::map<int, StatfiData>;

class Jsonparser
{
public:
    Jsonparser();
    ~Jsonparser();
    StatfiDB* parse_statfi(QJsonObject obj);
    void parse_smear(QJsonObject obj); // returns a pointer to the smear datastructure when implemented
private:
    StatfiDB statfi_db_;
};

#endif // JSONPARSER_H
