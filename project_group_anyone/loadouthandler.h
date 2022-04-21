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

/**
 * @brief The LoadoutHandler class
 * Class for handling of loadouts.
 * Can save the given loadout to a .json file
 * and load a loadout from the same file.
 */
class LoadoutHandler
{
public:
    LoadoutHandler();
    ~LoadoutHandler();
    void save(UserSelections* us);
    UserSelections* load();
};

#endif // LOADOUTHANDLER_H
