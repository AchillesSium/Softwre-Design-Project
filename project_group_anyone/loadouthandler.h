#ifndef LOADOUTHANDLER_H
#define LOADOUTHANDLER_H


#include "userselections.h"
#include "date.h"

#include <QFile>
#include <QIODevice>
#include <QString>
#include <string>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
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
