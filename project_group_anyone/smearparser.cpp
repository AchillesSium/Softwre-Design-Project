#include "smearparser.h"

#include <QDate>

/**
 * @brief SmearParser::SmearParser
 * Constructor if the class.
 * Inserts placeholder data to the smear datastructure.
 */
SmearParser::SmearParser()
{
    SmearData sd;
    smear_db_[SMEAR_stations::Varrio] = sd;
    smear_db_[SMEAR_stations::Hyytiala] = sd;
    smear_db_[SMEAR_stations::Kumpula] = sd;
}

/**
 * @brief SmearParser::~SmearParser
 * Destructor of the class
 */
SmearParser::~SmearParser()
{

}

/**
 * @brief SmearParser::parse
 * Function for parsing the QjsonObject given.
 * Reads data from object and adds data to the smear_db_ datastructure
 * @param obj
 * QJson object received from the SMEAR database holding all the data based on the query made.
 */
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

/**
 * @brief SmearParser::get_db
 * Returns the smear datastructure
 * @return
 * Datastructure holding the smear data from the reply
 */
SmearDB SmearParser::get_db()
{
    return smear_db_;
}

/**
 * @brief SmearParser::get_table_data
 * Function that reads data from given array and goes through
 * data based on the table name given
 * @param table_name
 * Name of the variable table that needs to be processed
 * @param data_arr
 * Array which holds all the data read from the QJsonObject received
 * @return
 * Vector which has all datapoints (Measured value and sampletime) with the given table name
 */
std::vector<DataPoint> SmearParser::get_table_data(QString table_name, QJsonArray data_arr)
{
    std::vector<DataPoint> vec;
    for(int i = 0; i < data_arr.size(); ++i){

        DataPoint dp;
        QJsonObject test = data_arr[i].toObject();

        // null values are skipped
        if(test[table_name] == QJsonValue::Null){
            continue;
        }

        long double value = test[table_name].toDouble(); // measured value
        QString stime = test[QString("samptime")].toString(); // sampletime

        QDateTime samptime = QDateTime::fromString(stime, Qt::ISODateWithMs);

        dp.first = value;
        dp.second = samptime;

        vec.push_back(dp);
    }
    return vec;
}
