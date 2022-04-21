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

/**
 * @brief The StatfiParser class
 * Class for parsing the .json files received from the STATFI database.
 * It reads data from the file and stores everything necessary to a suitable container.
 */
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
