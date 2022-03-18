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

Date UserSelections::getStart()
{
    return start_;
}

Date UserSelections::getEnd()
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
