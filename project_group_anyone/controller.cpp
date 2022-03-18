#include "controller.h"
#include <QDebug>
#include <vector>

std::vector<std::pair<int, double>> Controller::getSTATFIData(UserSelections* selections)
{
    // Get data from model

    // Filter data to match with the selections

    // Send filtered data to view, return value of the function can be changed
    // OR a separate function can be created in the view and called here
    // with the filtered data as a parameter
    std::vector<DataSet> ds = selections->getDataSets();

    for(int i = 0; i < ds.size(); ++i){
        qDebug() << "vector" << ds[i];
    }

    int startDate = selections->getStart().getYear();
    int endDate = selections->getEnd().getYear();

    qDebug() << "Dates" <<  startDate << endDate;

    qDebug() << "statfi" << selections->getDataSets();

    std::vector<std::pair<int, double>> filteredVector;

    double random = 100.01;

    for(int i = startDate; i <= endDate; i++){
        random = random + 7.065;
        std::pair<int, double> sampleValuePair = std::make_pair(i, random);
        filteredVector.push_back(sampleValuePair);
    }

    qDebug() << "Filtered Vector" << filteredVector;
    return filteredVector;
}
