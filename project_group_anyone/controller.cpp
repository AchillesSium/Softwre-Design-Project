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

std::vector<std::pair<int, double>> Controller::getSTATFIData(UserSelections* selections)
{
    // Get data from model

    // Filter data to match with the selections

    // Send filtered data to view, return value of the function can be changed
    // OR a separate function can be created in the view and called here
    // with the filtered data as a parameter
    DataSet selected_gas = selections->getDataSet();

    int startDate = selections->getStart().getYear();
    int endDate = selections->getEnd().getYear();

    std::vector<std::pair<int, double>> filteredVector;

    DataStorage& storage = DataStorage::get();
    StatfiDB& statfi_db_ = storage.getStatfiDB();

//    for (const auto &[k, v] : statfi_db_)
//        qDebug() << "m[" << k << "] = (" << v.intensity << ", " << v.intensity_indexed << ") ";

    auto v  = statfi_db_.find(startDate);
    qDebug() << "map at" << v->first << v->second.intensity;

    for(int i = startDate; i <= endDate; i++){
        std::pair<int, double> sampleValuePair;
        auto single_data  = statfi_db_.find(i);
        if(single_data != statfi_db_.end()){
            switch(selected_gas) {
              case 1:
                sampleValuePair = std::make_pair(i, single_data->second.tonnes);
                break;
              case 2:
                sampleValuePair = std::make_pair(i, single_data->second.intensity);
                break;
              case 3:
                sampleValuePair = std::make_pair(i, single_data->second.tonnes_indexed);
                break;
              case 4:
                sampleValuePair = std::make_pair(i, single_data->second.intensity_indexed);
                break;
              default:
                sampleValuePair = std::make_pair(i, 0.0);
                break;
            }
        }else{
            sampleValuePair = std::make_pair(i, 0.0);
        }
       filteredVector.push_back(sampleValuePair);
    }
    return filteredVector;
}

std::vector<DataPoint> Controller::getSMEARData(UserSelections* selections)
{
    // Call SMEAR data fetcher, below is an example of what it might look
    /*
    networkcallsSMEAR* network = new networkcallsSMEAR(selections);

    network->query();

    // Wait for the request, do stuff with the data, etc.

    delete network;
    */
    smearnetworkcall *smearNetwork = new smearnetworkcall(selections);
    smearNetwork->query();

    QEventLoop loop;
    QObject::connect(smearNetwork, SIGNAL(done()), &loop, SLOT(quit()));
    loop.exec();

    QJsonObject obj = smearNetwork->getObject();
    //QJsonObject obj1 = smearnetwork->getObject();
     std::vector<DataPoint> gasDp;

    if(obj["class"] == QJsonValue::Undefined ){
        qDebug() << "error happened";
    }
    else{
        SmearParser *smearparser = new SmearParser();
        smearparser->parse(obj);
      /*
         * for (const auto &[k, v] : statfi_db)
            qDebug() << "m[" << k << "] = (" << v.intensity << ", " << v.intensity_indexed << ") ";*/
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

