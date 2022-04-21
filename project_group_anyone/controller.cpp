#include <QDebug>
#include <QJsonObject>
#include <QEventLoop>

#include <vector>
#include <string>
#include <iostream>

#include "networkcalls.h"
#include "userselections.h"
#include "jsonparser.h"
#include "datastorage.h"
#include "controller.h"
#include "smearnetworkcall.h"
#include "smearparser.h"

/**
 * @brief Controller::getSTATFIData
 * Filters STATFI data based on user selections.
 * @param selections user selections to base the data filtering on.
 * @return container of the filtered data.
 * First item in the pair is year, second is data value.
 */
std::vector<std::pair<int, double>> Controller::getSTATFIData(UserSelections* selections)
{
    DataSet selected_gas = selections->getDataSet();

    int startDate = selections->getStart().getYear();
    int endDate = selections->getEnd().getYear();

    std::vector<std::pair<int, double>> filteredVector;

    DataStorage& storage = DataStorage::get();
    StatfiDB& statfi_db_ = storage.getStatfiDB();

    auto v  = statfi_db_.find(startDate);
    qDebug() << "map at" << v->first << v->second.intensity;

    for(int i = startDate; i <= endDate; i++){
        std::pair<int, double> sampleValuePair;
        auto single_data  = statfi_db_.find(i);
        if(single_data != statfi_db_.end()){
            switch(selected_gas) {
              case DataSet::CO2tonnes:
                sampleValuePair = std::make_pair(i, single_data->second.tonnes);
                break;
              case DataSet::CO2intensity:
                sampleValuePair = std::make_pair(i, single_data->second.intensity);
                break;
              case DataSet::CO2indexed:
                sampleValuePair = std::make_pair(i, single_data->second.tonnes_indexed);
                break;
              case DataSet::CO2intensityIndexed:
                sampleValuePair = std::make_pair(i, single_data->second.intensity_indexed);
                break;
              default:
                sampleValuePair = std::make_pair(i, 0.0);
                break;
            }
        }
        else{
            sampleValuePair = std::make_pair(i, 0.0);
        }
       filteredVector.push_back(sampleValuePair);
    }
    return filteredVector;
}

/**
 * @brief Controller::getSMEARData
 * Initiates an API query to SMEAR API and parses the resulting data.
 * @param selections user selections to base the API query on.
 * @return container of the parsed data.
 */
std::vector<DataPoint> Controller::getSMEARData(UserSelections* selections)
{
    smearnetworkcall *smearNetwork = new smearnetworkcall(selections);
    smearNetwork->query();

    QEventLoop loop;
    QObject::connect(smearNetwork, SIGNAL(done()), &loop, SLOT(quit()));
    loop.exec();

    QJsonObject obj = smearNetwork->getObject();
    std::vector<DataPoint> gasDp;

    if(obj["class"] == QJsonValue::Undefined ){
        qDebug() << "error happened";
    }
    else{
        SmearParser *smearparser = new SmearParser();
        smearparser->parse(obj);
        SmearDB db = smearparser->get_db();

        for(auto it = db.cbegin(); it != db.cend(); ++it)
        {
            if(it->second.CO2.empty() == false){
                gasDp = it->second.CO2;
            }else if(it->second.NOX.empty() == false){
                gasDp = it->second.NOX;
            }else if(it->second.SO2.empty() == false){
                gasDp = it->second.SO2;
            }
        }
        delete smearparser;
    }

    delete smearNetwork;

    return gasDp;
}

