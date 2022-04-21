#ifndef USERSELECTIONS_H
#define USERSELECTIONS_H

#include <string>
#include <vector>
#include <unordered_map>
#include "date.h"

enum class DataSource
{
    None,
    STATFI,
    SMEAR
};

enum class MeasuringStation
{
    Varrio,
    Hyytiala,
    Kumpula,
    None
};

enum class AggregateType
{
    None,
    Arithmetic,
    Geometric,
    Sum,
    Median,
    Min,
    Max,
    Availability,
    Circular
};

enum DataSet
{
    None,

    // STATFI
    CO2tonnes,
    CO2intensity,
    CO2indexed,
    CO2intensityIndexed,

    // SMEAR
    CO2,
    SO2,
    NO
};

#define SMEAR_BASE_QUERY "https://smear-backend.rahtiapp.fi/search/timeseries?";

/**
 * @brief The UserSelections class
 * Class for storing and managing information about what kind
 * of selections the user has made in the GUI. Used for forming
 * API queries.
 */
class UserSelections
{
public:
    UserSelections(DataSource dataSource);
    DataSource getSource()                              { return dataSource_; }
    Date& getStart()                                    { return start_; }
    Date& getEnd()                                      { return end_; }
    DataSet getDataSet()                                { return dataSet_; }
    MeasuringStation getMeasuringStation()              { return station_; }
    AggregateType getAggregateType()                    { return aggregate_; }
    bool setStart(Date t);
    bool setEnd(Date t);
    void setDataSet(DataSet dataSet);
    void setMeasuringStation(MeasuringStation station);
    void setAggregateType(AggregateType type);
    std::string toQuery();

private:
    std::string getAggregateTypeAsString();
    std::string getTableVariableAsString();

    DataSource dataSource_;
    Date start_;
    Date end_;
    MeasuringStation station_;
    DataSet dataSet_;
    AggregateType aggregate_;
};

#endif // USERSELECTIONS_H
