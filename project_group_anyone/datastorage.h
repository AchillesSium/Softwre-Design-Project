#ifndef DATASTORAGE_H
#define DATASTORAGE_H

#include <map>

const double NO_VALUE = 0.0;

struct StatfiData{
    double tonnes;
    double intensity;
    double tonnes_indexed;
    double intensity_indexed;
};

using StatfiDB = std::map<int, StatfiData>;

/**
 * @brief The DataStorage class
 * Singleton class for storing STATFI data throughout
 * the life of the application.
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
