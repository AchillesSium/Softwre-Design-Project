#ifndef SMEARNETWORKCALL_H
#define SMEARNETWORKCALL_H

#include "networkcalls.h"
#include <QString>

class smearnetworkcall : public networkcalls
{
public:
    smearnetworkcall();
    ~smearnetworkcall();
    void query();
    void querySmearTimeSeries(QString aggregation, int interval, QString startDate, QString endDate, QString tableVariable);
    QJsonObject getObject();

private:
    QJsonObject timeSeriesObj_;
    QString stationUrl = QStringLiteral("https://smear-backend.rahtiapp.fi/station");
};

#endif // SMEARNETWORKCALL_H
