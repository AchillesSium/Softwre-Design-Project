#ifndef DATASTORAGE_H
#define DATASTORAGE_H

#include <map>
#include "statfiparser.h"

/*
 * Implemented as a singleton
 * Use example:
 * DataStorage& storage = DataStorage::get();
 * storage.setStatfiDBmin(firstAvailableYear);
 * storage.setStatfiDBmax(lastAvailableYear);
 */
class DataStorage
{
public:
    static DataStorage& get();

    void setStatfiDB(StatfiDB db);
    StatfiDB& getStatfiDB();

    void setStatfiDBmin(int min);
    void setStatfiDBmax(int max);

    int getStatfiDBmin();
    int getStatfiDBmax();

private:
    DataStorage() = default;

    // Do not allow creation of more instances
    DataStorage(const DataStorage&) = delete;
    DataStorage& operator=(const DataStorage&) = delete;
    DataStorage(DataStorage&&) = delete;
    DataStorage& operator=(DataStorage&&) = delete;

    StatfiDB statfiDB_;
    int statfiDBmin_;
    int statfiDBmax_;
};

#endif // DATASTORAGE_H
