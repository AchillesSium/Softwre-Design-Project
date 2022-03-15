#ifndef USERSELECTIONSSTATFI_H
#define USERSELECTIONSSTATFI_H

#include "userselections.h"

class UserSelectionsSTATFI : public UserSelections
{
public:
    UserSelectionsSTATFI();
    ~UserSelectionsSTATFI() {};
    std::vector<DataSet> getDataSets();
    void addDataSet(DataSet dataSet);

private:
    DataSet dataSet_;
};

#endif // USERSELECTIONSSTATFI_H
