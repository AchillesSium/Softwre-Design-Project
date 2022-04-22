#ifndef SMEARNETWORKCALL_H
#define SMEARNETWORKCALL_H

#include "networkcalls.h"
#include <QString>
#include "userselections.h"

/**
 * @brief The smearnetworkcall class
 * Class for making API queries to SMEAR database.
 */
class smearnetworkcall : public networkcalls
{
public:
    explicit smearnetworkcall();
    explicit smearnetworkcall(UserSelections* selections);
    ~smearnetworkcall();
    void query();
    QJsonObject getObject();

private:
    UserSelections* userSelections;
    QJsonObject timeSeriesObj_;
    QString stationUrl = QStringLiteral("https://smear-backend.rahtiapp.fi/station");
};

#endif // SMEARNETWORKCALL_H
