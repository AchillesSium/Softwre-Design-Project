#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "userselections.h"
#include "date.h"
#include "statfiparser.h"
#include "smearparser.h"

/**
 * @brief The Controller class
 * Set of static functions for the view to use to access
 * data in the model. No instances of this can be created.
 */
class Controller
{
public:
    Controller() = delete;
    Controller(const Controller&) = delete;
    void operator=(Controller const&) = delete;

    static std::vector<std::pair<int, double>> getSTATFIData(UserSelections* selections);
    static std::vector<DataPoint> getSMEARData(UserSelections* selections);

private:

};

#endif // CONTROLLER_H
