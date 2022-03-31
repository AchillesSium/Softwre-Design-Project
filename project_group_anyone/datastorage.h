#ifndef DATASTORAGE_H
#define DATASTORAGE_H

#include <map>

const double NO_VALUE = 0.0;

struct StatfiData
{
    double tonnes;
    double intensity;
    double tonnes_indexed;
    double intensity_indexed;
};

using StatfiDB = std::map<int, StatfiData>;

class DataStorage
{
public:
    DataStorage();
    DataStorage(const DataStorage&) = delete;
    void operator=(DataStorage const&) = delete;

    static void setStatfiDB(StatfiDB db);
    static StatfiDB& getStatfiDB();

    static void setStatfiDBmin(int min);
    static void setStatfiDBmax(int max);

    static int getStatfiDBmin();
    static int getStatfiDBmax();

private:
    static StatfiDB statfiDB_;
    static int statfiDBmin_;
    static int statfiDBmax_;
};

#endif // DATASTORAGE_H
