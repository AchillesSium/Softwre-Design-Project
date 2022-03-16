#ifndef USERSELECTIONS_H
#define USERSELECTIONS_H

#include <string>
#include <vector>
#include "date.h"

enum class DataSource
{
    None,
    STATFI,
    SMEAR
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
    NOx
};

class UserSelections
{
public:
    virtual ~UserSelections() {};
    DataSource getSource();
    Date getStart();
    Date getEnd();
    bool setStart(Date t);
    bool setEnd(Date t);
    virtual void addDataSet(DataSet dataSet) {};
    virtual std::vector<DataSet> getDataSets() {};

protected:
    UserSelections(DataSource dataSource);

private:
    DataSource dataSource_;
    Date start_;
    Date end_;
};

#endif // USERSELECTIONS_H
