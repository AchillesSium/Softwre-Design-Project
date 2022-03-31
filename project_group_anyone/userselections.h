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
    Kumpula
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

class UserSelections
{
public:
    UserSelections(DataSource dataSource);
    DataSource getSource();
    Date& getStart();
    Date& getEnd();
    bool setStart(Date t);
    bool setEnd(Date t);
    void setDataSet(DataSet dataSet);
    DataSet getDataSet();
    void setMeasuringStation(MeasuringStation station);
    MeasuringStation getMeasuringStation();
    void setAggregateType(AggregateType type);
    AggregateType getAggregateType();
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
