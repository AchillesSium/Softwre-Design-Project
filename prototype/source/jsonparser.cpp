#include "jsonparser.h"

Jsonparser::Jsonparser()
{

}

Jsonparser::~Jsonparser()
{

}

StatfiDB* Jsonparser::parse_statfi(QJsonObject obj)
{
    StatfiDB* statfi_ptr = &statfi_db_;

    QJsonArray values = obj["value"].toArray();

    //add data from json to data structure
    for(int year = 1990; year < 2017; ++year){

        StatfiData sd;

        for(int i = 0; i < 4; ++i){

            sd.tonnes = values.at(0).toDouble(); // Greenhouse gas emissions 2), CO2 equivalent 1000 t
            values.pop_front();

            sd.tonnes_indexed = values.at(0).toDouble(); // Greenhouse gas emissions, indexed, year 1990 = 100
            values.pop_front();

            sd.intensity = values.at(0).toDouble(); // Intensity of greenhouse gas emissions
            values.pop_front();

            sd.intensity_indexed = values.at(0).toDouble(); // Intensity of greenhouse gases, indexed, year 1990 = 100
            values.pop_front();

        }

        statfi_db_[year] = sd;
    }
    return statfi_ptr;
}
