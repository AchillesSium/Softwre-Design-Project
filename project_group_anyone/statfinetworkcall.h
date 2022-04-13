#ifndef STATFINETWORKCALL_H
#define STATFINETWORKCALL_H

#include "networkcalls.h"

class statfinetworkcall: public networkcalls
{
public:
    statfinetworkcall();
    ~statfinetworkcall();
    void getDataFromApi();
    void postDataToApi();
    QJsonObject getObject(bool getData);

private:
    QJsonObject statfObj_;
    QString statfiUrl = QStringLiteral("https://pxnet2.stat.fi:443/PXWeb/api/v1/en/ymp/taulukot/Kokodata.px");
};

#endif // STATFINETWORKCALL_H
