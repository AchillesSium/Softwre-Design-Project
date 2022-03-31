#include "datastorage.h"

StatfiDB DataStorage::statfiDB_;
int statfiDBmin_;
int statfiDBmax_;

void DataStorage::setStatfiDB(StatfiDB db)
{
    statfiDB_ = db;
}

StatfiDB& DataStorage::getStatfiDB()
{
    return statfiDB_;
}

void setStatfiDBmin(int min)
{
    statfiDBmin_ = min;
}

void setStatfiDBmax(int max)
{
    statfiDBmax_ = max;
}

int getStatfiDBmin()
{
    return statfiDBmin_;
}

int getStatfiDBmax()
{
    return statfiDBmax_;
}
