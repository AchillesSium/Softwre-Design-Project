#ifndef SMEARNETWORKCALL_H
#define SMEARNETWORKCALL_H

#include "networkcalls.h"
#include <QString>

class smearnetworkcall : public networkcalls
{
public:
    smearnetworkcall();
    ~smearnetworkcall();
    void querySmearStations();
    void querySmearTimeSeries(QString aggregation, int interval, QString startDate, QString endDate, QString tableVariable);
    void getDataFromApi();
    void postDataToApi();
    QJsonObject getObject(bool getData);

private:
    QJsonObject stationObj_;
    QJsonObject timeSeriesObj_;
    QString stationUrl = QStringLiteral("https://smear-backend.rahtiapp.fi/station");
};

#endif // SMEARNETWORKCALL_H
