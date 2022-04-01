#include "userselections.h"

#include <algorithm>

UserSelections::UserSelections(DataSource dataSource)
{
    dataSource_ = dataSource;
}

DataSource UserSelections::getSource()
{
    return dataSource_;
}

Date& UserSelections::getStart()
{
    return start_;
}

Date& UserSelections::getEnd()
{
    return end_;
}

bool UserSelections::setStart(Date t)
{
    start_ = t;
    return t.validate();
}

bool UserSelections::setEnd(Date t)
{
    end_ = t;
    return t.validate();
}

void UserSelections::setDataSet(DataSet dataSet)
{
    dataSet_ = dataSet;
}

DataSet UserSelections::getDataSet()
{
    return dataSet_;
}

void UserSelections::setMeasuringStation(MeasuringStation station)
{
    station_ = station;
}

MeasuringStation UserSelections::getMeasuringStation()
{
    return station_;
}

void UserSelections::setAggregateType(AggregateType type)
{
    aggregate_ = type;
}

AggregateType UserSelections::getAggregateType()
{
    return aggregate_;
}

std::string UserSelections::toQuery()
{
    std::string query = SMEAR_BASE_QUERY;

    query += "aggregation=" + getAggregateTypeAsString();

    query += "&interval=60";

    query += "&from=" + start_.toString() + "&to=" + end_.toString();

    query += "&tablevariable=" + getTableVariableAsString();

    return query;
}

std::string UserSelections::getAggregateTypeAsString()
{
    std::string agg = "NONE";
    switch (aggregate_)
    {
        case (AggregateType::None): agg = "NONE"; break;
        case (AggregateType::Arithmetic): agg = "ARITHMETIC"; break;
        case (AggregateType::Geometric): agg = "GEOMETRIC"; break;
        case (AggregateType::Sum): agg = "SUM"; break;
        case (AggregateType::Median): agg = "MEDIAN"; break;
        case (AggregateType::Min): agg = "MIN"; break;
        case (AggregateType::Max): agg = "MAX"; break;
        case (AggregateType::Availability): agg = "AVAILABILITY"; break;
        case (AggregateType::Circular): agg = "CIRCULAR"; break;
    }
    return agg;
}

std::string UserSelections::getTableVariableAsString()
{
    std::string tableVar = "";

    switch (station_)
    {
    case MeasuringStation::Varrio:
        switch (dataSet_)
        {
        case (CO2): tableVar = "VAR_EDDY.av_c"; break;
        case (SO2): tableVar = "VAR_META.SO2_1"; break;
        case (NO): tableVar = "VAR_META.NO_1"; break;
        default: break;
        }
        break;

    case MeasuringStation::Hyytiala:
        switch (dataSet_)
        {
        case (CO2): tableVar = "HYY_META.CO2icos168"; break;
        case (SO2): tableVar = "HYY_META.SO2168"; break;
        case (NO): tableVar = "HYY_META.NO168"; break;
        default: break;
        }
        break;

    case MeasuringStation::Kumpula:
        switch (dataSet_)
        {
        case (CO2): tableVar = "KUM_EDDY.av_c_ep"; break;
        case (SO2): tableVar = "KUM_META.SO_2"; break;
        case (NO): tableVar = "KUM_META.NO"; break;
        default:break;
        }
        break;
    }

    return tableVar;
}
