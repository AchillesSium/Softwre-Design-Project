#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "userselections.h"
#include "date.h"

class Controller
{
public:
    // No instances can be created, this is purely used with static functions
    Controller() = delete;
    Controller(const Controller&) = delete;
    void operator=(Controller const&) = delete;

    // NOTE: CHANGE RETURN VALUE WHEN DATATYPE IS DECIDED
    // OR CALL A FUNCTION FROM VIEW WITH THE FILTERED DATA
    // AS A PARAMETER INSTEAD
    static std::vector<std::pair<int, double>> getSTATFIData(UserSelections* selections);
};

#endif // CONTROLLER_H
