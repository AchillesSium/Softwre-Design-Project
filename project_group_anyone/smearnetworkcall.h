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
    QJsonObject getStationObject();
     QJsonObject getTimeSeriesObject();

private:
    QJsonObject stationObj_;
    QJsonObject timeSeriesObj_;
};

#endif // SMEARNETWORKCALL_H
