#include "userselections.h"

/**
 * @brief UserSelections::UserSelections
 * Constructs an UserSelections object with the given data source.
 * @param dataSource the API the user wishes to access data from.
 */
UserSelections::UserSelections(DataSource dataSource)
{
    dataSource_ = dataSource;
}

/**
 * @brief UserSelections::setStart
 * Sets the start date for the API query.
 * @param t start date to set.
 * @return true if input date is valid, false if not.
 */
bool UserSelections::setStart(Date t)
{
    start_ = t;
    return t.validate();
}

/**
 * @brief UserSelections::setEnd
 * Sets the end date for the API query.
 * @param t end date to set.
 * @return true if input date isvalid, false if not.
 */
bool UserSelections::setEnd(Date t)
{
    end_ = t;
    return t.validate();
}

/**
 * @brief UserSelections::setDataSet
 * Sets the data set the for the API query.
 * @param dataSet data set to set.
 */
void UserSelections::setDataSet(DataSet dataSet)
{
    dataSet_ = dataSet;
}

/**
 * @brief UserSelections::setMeasuringStation
 * Sets the measuring station for the API query.
 * @param station measuring station to set.
 */
void UserSelections::setMeasuringStation(MeasuringStation station)
{
    station_ = station;
}

/**
 * @brief UserSelections::setAggregateType
 * Sets the aggregate type for the API query.
 * @param type aggregate type to set.
 */
void UserSelections::setAggregateType(AggregateType type)
{
    aggregate_ = type;
}

/**
 * @brief UserSelections::toQuery
 * Forms a SMEAR API query based on the state of the object.
 * @return the query as a string.
 */
std::string UserSelections::toQuery()
{
    std::string query = SMEAR_BASE_QUERY;

    query += "aggregation=" + getAggregateTypeAsString();

    query += "&interval=60";

    // Do not allow the exact same time as start and end
    if (start_ == end_)
        end_.advance();

    query += "&from=" + start_.toString() + "&to=" + end_.toString();

    query += "&tablevariable=" + getTableVariableAsString();

    return query;
}

/**
 * @brief UserSelections::getAggregateTypeAsString
 * Returns the aggregate enum as a string.
 * @return the aggregate enum as a string.
 */
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

/**
 * @brief UserSelections::getTableVariableAsString
 * Picks the table variable string based on the chosen
 * measuring station and data set.
 * @return the table variable as a string.
 */
std::string UserSelections::getTableVariableAsString()
{
    std::string tableVar = "";

    switch (station_)
    {
    case (MeasuringStation::Varrio):
        switch (dataSet_)
        {
        case (CO2): tableVar = "VAR_EDDY.av_c"; break;
        case (SO2): tableVar = "VAR_META.SO2_1"; break;
        case (NO): tableVar = "VAR_META.NO_1"; break;
        default: break;
        }
        break;

    case (MeasuringStation::Hyytiala):
        switch (dataSet_)
        {
        case (CO2): tableVar = "HYY_META.CO2icos168"; break;
        case (SO2): tableVar = "HYY_META.SO2168"; break;
        case (NO): tableVar = "HYY_META.NO168"; break;
        default: break;
        }
        break;

    case (MeasuringStation::Kumpula):
        switch (dataSet_)
        {
        case (CO2): tableVar = "KUM_EDDY.av_c_ep"; break;
        case (SO2): tableVar = "KUM_META.SO_2"; break;
        case (NO): tableVar = "KUM_META.NO"; break;
        default:break;
        }
        break;
    default:
        break;
    }

    return tableVar;
}
