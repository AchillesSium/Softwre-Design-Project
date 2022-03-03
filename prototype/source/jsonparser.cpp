#include "jsonparser.h"

Jsonparser::Jsonparser()
{

}

Jsonparser::~Jsonparser()
{

}

void Jsonparser::parse(QJsonObject obj, std::string db)
{
    if(db == "STATFI"){

        QJsonObject test1 = obj["dimension"].toObject()["Tiedot"].toObject()["category"].toObject()["label"].toObject();
        QJsonArray datapoints;

        for(QJsonValue val : test1){
            datapoints.append(val);
        }

        QJsonObject test2 = obj["dimension"].toObject()["Vuosi"].toObject()["category"].toObject()["label"].toObject();
        QJsonArray years;

        for(QJsonValue val : test2){
            years.append(val);
        }

        QJsonArray values = obj["value"].toArray();

        //add data to data structure
        StatfiDB db;
        for(int j = 0; j < years.size(); ++j){
            StatfiData sd;
            for(int i = 0; i < datapoints.size(); ++i){

                if(datapoints[i] == "Greenhouse gas emissions 2), CO2 equivalent 1000 t"){
                    sd.tonnes = values.at(0).toDouble();
                    values.pop_front();
                    //continue;
                }
                if(datapoints[i] == "Greenhouse gas emissions, indexed, year 1990 = 100"){
                    sd.indexed = values.at(0).toDouble();
                    values.pop_front();
                    //continue;
                }
                if(datapoints[i] == "Intensity of greenhouse gas emissions"){
                    sd.intensity = values.at(0).toDouble();
                    values.pop_front();
                    //continue;
                }
                if(datapoints[i] == "Intensity of greenhouse gases, indexed, year 1990 = 100"){
                    sd.intensity_indexed = values.at(0).toDouble();
                    values.pop_front();
                    //continue;
                }

            }

            db[years[j].toString().toInt()] = sd;
        }

    }
}
