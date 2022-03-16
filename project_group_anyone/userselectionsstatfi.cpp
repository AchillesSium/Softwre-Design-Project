#include "userselectionsstatfi.h"

UserSelectionsSTATFI::UserSelectionsSTATFI()
    : UserSelections(DataSource::STATFI)
{
}

std::vector<DataSet> UserSelectionsSTATFI::getDataSets()
{
    std::vector<DataSet> v;
    v.push_back(dataSet_);
    return v;
}

void UserSelectionsSTATFI::addDataSet(DataSet dataSet)
{
    dataSet_ = dataSet;
}
