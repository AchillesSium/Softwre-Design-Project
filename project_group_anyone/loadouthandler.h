#ifndef LOADOUTHANDLER_H
#define LOADOUTHANDLER_H


#include "userselections.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

class LoadoutHandler
{
public:
    LoadoutHandler();
    ~LoadoutHandler();
    void save(UserSelections* us);
    UserSelections* load();
};

#endif // LOADOUTHANDLER_H
