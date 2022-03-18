#include "controller.h"
#include <QDebug>
#include <vector>
#include "networkcalls.h"
#include <QJsonObject>
#include <QEventLoop>
#include <string>
#include "userselections.h"

std::vector<std::pair<int, double>> Controller::getSTATFIData(UserSelections* selections)
{
    // Get data from model

    // Filter data to match with the selections

    // Send filtered data to view, return value of the function can be changed
    // OR a separate function can be created in the view and called here
    // with the filtered data as a parameter
    std::vector<DataSet> ds = selections->getDataSets();

    DataSet selected_gas;
    for(int i = 0; i < ds.size(); ++i){
        qDebug() << "vector" << ds[i];
        selected_gas = ds[i];
    }

    int startDate = selections->getStart().getYear();
    int endDate = selections->getEnd().getYear();

    std::vector<std::pair<int, double>> filteredVector;


    StatfiDB statfi_db_ = getStatFiDataFromApi();

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

StatfiDB Controller::getStatFiDataFromApi()
{
    StatfiDB statfi_db;
    networkcalls *network = new networkcalls();

    network->queryStatFi();

    // wait for the request to process completely
    QEventLoop loop;
    QObject::connect(network, SIGNAL(done()), &loop, SLOT(quit()));
    loop.exec();

    QJsonObject obj = network->getObject();

    if(obj["class"] == QJsonValue::Undefined ){
        qDebug() << "error happened";
    }
    else{
        Jsonparser *parser = new Jsonparser();
        statfi_db = parser->parse_statfi(obj);
        delete parser;
    }

    return statfi_db;
}


