#include "datastorage.h"

/**
 * @brief DataStorage::get
 * Returns the singleton or initializes it if it
 * doesn't exist yet.
 * @return the singleton data storage.
 */
DataStorage& DataStorage::get()
{
    static DataStorage* instance = new DataStorage();
    return *instance;
}

/**
 * Setters and getters for the data storage.
 */

void DataStorage::setStatfiDB(StatfiDB db)
{
    statfiDB_ = db;
}

StatfiDB& DataStorage::getStatfiDB()
{
    return statfiDB_;
}

void DataStorage::setStatfiDBmin(int min)
{
    statfiDBmin_ = min;
}

void DataStorage::setStatfiDBmax(int max)
{
    statfiDBmax_ = max;
}

int DataStorage::getStatfiDBmin()
{
    return statfiDBmin_;
}

int DataStorage::getStatfiDBmax()
{
    return statfiDBmax_;
}
