#ifndef STATFINETWORKCALL_H
#define STATFINETWORKCALL_H

#include "networkcalls.h"

class statfinetworkcall: public networkcalls
{
public:
    statfinetworkcall();
    ~statfinetworkcall();
    void queryStatFi();
    QJsonObject getObject();

private:
    QJsonObject statfObj_;
};

#endif // STATFINETWORKCALL_H
