#include "smearparser.h"

SmearParser::SmearParser()
{
    SmearData sd;
    smear_db_[SMEAR_stations::Varrio] = sd;
    smear_db_[SMEAR_stations::Hyytiala] = sd;
    smear_db_[SMEAR_stations::Kumpula] = sd;
}

SmearParser::~SmearParser()
{

}

void SmearParser::parse(QJsonObject obj)
{
    // get all tables form the response to an array
    QJsonArray table_arr = obj[QString("columns")].toArray();

    // get all data samples to an array
    QJsonArray data_arr = obj[QString("data")].toArray();

    // add all data corresponding to each table to the datastructure
    for(int i = 0; i < table_arr.size(); ++i){

        QString table_name = table_arr[i].toString();

        if(table_name == QString("VAR_EDDY.av_c")){ // Värriö, CO2
            smear_db_[SMEAR_stations::Varrio].CO2 = get_table_data(table_name, data_arr);
            continue;
        }

        if(table_name == QString("VAR_META.SO2_1")){ // Värriö, SO2
            smear_db_[SMEAR_stations::Varrio].SO2 = get_table_data(table_name, data_arr);
            continue;
        }

        if(table_name == QString("VAR_META.NO_1")){ // Värriö, NOX
            smear_db_[SMEAR_stations::Varrio].NOX = get_table_data(table_name, data_arr);
            continue;
        }

        if(table_name == QString("HYY_META.CO2icos168")){ // Hyytiälä, CO2
            smear_db_[SMEAR_stations::Hyytiala].CO2 = get_table_data(table_name, data_arr);
            continue;
        }

        if(table_name == QString("HYY_META.SO2168")){ // Hyytiälä, SO2
            smear_db_[SMEAR_stations::Hyytiala].SO2 = get_table_data(table_name, data_arr);
            continue;
        }

        if(table_name == QString("HYY_META.NO168")){ // Hyytiälä, NOX
            smear_db_[SMEAR_stations::Hyytiala].NOX = get_table_data(table_name, data_arr);
            continue;
        }

        if(table_name == QString("KUM_EDDY.av_c_ep")){ // Kumpula, CO2
            smear_db_[SMEAR_stations::Kumpula].CO2 = get_table_data(table_name, data_arr);
            continue;
        }

        if(table_name == QString("KUM_META.SO_2")){ // Kumpula, SO2
            smear_db_[SMEAR_stations::Kumpula].SO2 = get_table_data(table_name, data_arr);
            continue;
        }

        if(table_name == QString("KUM_META.NO")){ // Kumpula, NOX
            smear_db_[SMEAR_stations::Kumpula].NOX = get_table_data(table_name, data_arr);
            continue;
        }
    }
}

SmearDB SmearParser::get_db()
{
    return smear_db_;
}

std::vector<DataPoint> SmearParser::get_table_data(QString table_name, QJsonArray data_arr)
{

}
