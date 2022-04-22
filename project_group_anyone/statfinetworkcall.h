#ifndef STATFINETWORKCALL_H
#define STATFINETWORKCALL_H

#include "networkcalls.h"

/**
 * @brief The statfinetworkcall class
 * Class for making API queries to STATFI database.
 */
class statfinetworkcall: public networkcalls
{
public:
    statfinetworkcall();
    ~statfinetworkcall();
    void query();
    QJsonObject getObject();

private:
    QJsonObject statfObj_;
    QString statfiUrl = QStringLiteral("https://pxnet2.stat.fi:443/PXWeb/api/v1/en/ymp/taulukot/Kokodata.px");
};

#endif // STATFINETWORKCALL_H
