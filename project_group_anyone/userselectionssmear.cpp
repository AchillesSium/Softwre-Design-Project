#include "userselectionssmear.h"

#include <algorithm>

UserSelectionsSMEAR::UserSelectionsSMEAR()
    : UserSelections(DataSource::STATFI)
{
}

std::vector<DataSet> UserSelectionsSMEAR::getDataSets()
{
    return dataSets_;
}

std::vector<std::string> UserSelectionsSMEAR::getMeasuringStationss()
{
    return stations_;
}

void UserSelectionsSMEAR::addDataSet(DataSet dataSet)
{
    if (std::find(dataSets_.begin(), dataSets_.end(), dataSet) == dataSets_.end())
        dataSets_.push_back(dataSet);
}

void UserSelectionsSMEAR::deleteDataSet(DataSet dataSet)
{
    dataSets_.erase(std::remove(dataSets_.begin(), dataSets_.end(), dataSet), dataSets_.end());
}

void UserSelectionsSMEAR::addMeasuringStation(std::string station)
{
    if (std::find(stations_.begin(), stations_.end(), station) == stations_.end())
        stations_.push_back(station);
}

void UserSelectionsSMEAR::deleteMeasuringStation(std::string station)
{
    stations_.erase(std::remove(stations_.begin(), stations_.end(), station), stations_.end());
}

/*
 * Uses information in the object to form a URL path that
 * is used for fetching the associated data from the SMEAR API.
 *
 * Examples:
 *
 * https://smear-backend.rahtiapp.fi/search/timeseries?aggregation=MAX&interval=60
 * &from=2022-01-19T14:00:00.000&to=2022-01-19T17:00:00.000&tablevariable=KUM_EDDY.av_c_ep
 *
 * https://smear-backend.rahtiapp.fi/search/timeseries?aggregation=ARITHMETIC&interval=30
 * &from=2022-01-20T01:00:00.000&to=2022-01-20T02:00:00.000&tablevariable=VAR_META.SO2_1
 * &tablevariable=HYY_META.SO2168&tablevariable=KUM_META.SO_2
*/
std::string UserSelectionsSMEAR::toQuery()
{
    std::string query = SMEAR_BASE_QUERY;

    // aggregation here

    // interval here (do we want user to be able to choose it?)

    // time span here

    // table variables here, they are a little confusing, might have to be hard-coded

    return query;
}
