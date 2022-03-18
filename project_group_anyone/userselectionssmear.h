#ifndef USERSELECTIONSSMEAR_H
#define USERSELECTIONSSMEAR_H

#include "userselections.h"

#include <vector>

#define SMEAR_BASE_QUERY "https://smear-backend.rahtiapp.fi/search/timeseries?";


enum class AggregationType
{
    Arithmetic,
    Max,
    Min
};

class UserSelectionsSMEAR : UserSelections
{
public:
    UserSelectionsSMEAR();
    ~UserSelectionsSMEAR() {};
    std::vector<DataSet> getDataSets();
    std::vector<std::string> getMeasuringStationss();
    void addMeasuringStation(std::string station);
    void deleteMeasuringStation(std::string station);
    void addDataSet(DataSet dataSet);
    void deleteDataSet(DataSet dataSet);
    std::string toQuery();

private:
    std::vector<std::string> stations_;
    std::vector<DataSet> dataSets_;
};

#endif // USERSELECTIONSSMEAR_H
