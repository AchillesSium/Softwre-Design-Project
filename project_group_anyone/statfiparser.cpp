#include "statfiparser.h"

StatfiParser::StatfiParser()
{

}

StatfiParser::~StatfiParser()
{

}

void StatfiParser::parse(QJsonObject obj)
{
    // get all years from the QJsonObject to an vector
    QVector<QString> years = obj[QString("dimension")]
            .toObject()[QString("Vuosi")]
            .toObject()[QString("category")]
            .toObject()[QString("index")]
            .toObject().keys().toVector();

    // get all values to an array
    QJsonArray values = obj[QString("value")].toArray();

    // all values from each year can be found from the following indexes
    int tonnes_index = 0;
    int tonnes_indexed_index = tonnes_index + years.size();
    int intensity_index = tonnes_indexed_index + years.size();
    int intensity_indexed_index = intensity_index + years.size();

    //add data from json to data structure
    for(int i = 0; i < years.size(); ++i){

        StatfiData sd;
        int null_counter = 0;

        if(values[tonnes_index] == QJsonValue::Null){
            sd.tonnes = NO_VALUE;
            ++null_counter;
        }
        else{
            sd.tonnes = values[tonnes_index].toDouble(); // Greenhouse gas emissions 2), CO2 equivalent 1000 t
        }

        if(values[tonnes_indexed_index] == QJsonValue::Null){
            sd.tonnes_indexed = NO_VALUE;
            ++null_counter;
        }
        else{
            sd.tonnes_indexed = values[tonnes_indexed_index].toDouble(); // Greenhouse gas emissions, indexed, year 1990 = 100
        }

        if(values[intensity_index] == QJsonValue::Null){
            sd.intensity = NO_VALUE;
            ++null_counter;
        }
        else{
            sd.intensity = values[intensity_index].toDouble(); // Intensity of greenhouse gas emissions
        }

        if(values[intensity_indexed_index] == QJsonValue::Null){
            sd.intensity_indexed = NO_VALUE;
            ++null_counter;
        }
        else{
            sd.intensity_indexed = values[intensity_indexed_index].toDouble(); // Intensity of greenhouse gases, indexed, year 1990 = 100
        }

        if(null_counter < 4){
           statfi_db_[years[i].toInt()] = sd;
        }

        ++tonnes_index;
        ++tonnes_indexed_index;
        ++intensity_index;
        ++intensity_indexed_index;
    }
}

StatfiDB StatfiParser::get_db()
{
    return statfi_db_;
}
