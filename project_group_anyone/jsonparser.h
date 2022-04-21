#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QJsonObject>

/**
 * @brief The Jsonparser class
 * An abstract class for other parser used in the program.
 * This classes responsibility is to read data from the
 * .json files received and storing the data to a suitable container.
 */
class Jsonparser
{
public:
    Jsonparser();
    virtual ~Jsonparser();
    virtual void parse(QJsonObject obj);
};

#endif // JSONPARSER_H
