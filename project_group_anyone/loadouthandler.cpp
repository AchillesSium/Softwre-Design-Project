#include "loadouthandler.h"

LoadoutHandler::LoadoutHandler()
{

}

LoadoutHandler::~LoadoutHandler()
{

}

void LoadoutHandler::save(UserSelections* us)
{
    // load "loadout.json" file from root and make all necessary additions and changes
    QFile file;
    file.setFileName("loadout.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QJsonParseError JsonParseError;
    QJsonDocument JsonDocument = QJsonDocument::fromJson(file.readAll(), &JsonParseError);
    file.close();

    QJsonObject RootObject = JsonDocument.object();

    switch(us->getSource())
    {
        case DataSource::None:
            RootObject.insert("DataSource", "None");
            break;

        case DataSource::STATFI:
            RootObject.insert("DataSource", "STATFI");
            break;

        case DataSource::SMEAR:
            RootObject.insert("DataSource", "SMEAR");
            break;
    }

    switch(us->getDataSet())
    {
        case DataSet::CO2tonnes:
            RootObject.insert("DataSetSTATFI", "CO2tonnes");
            break;

        case DataSet::CO2indexed:
            RootObject.insert("DataSetSTATFI", "CO2indexed");
            break;

        case DataSet::CO2intensity:
            RootObject.insert("DataSetSTATFI", "CO2intensity");
            break;

        case DataSet::CO2intensityIndexed:
            RootObject.insert("DataSetSTATFI", "CO2intensityIndexed");
            break;

        default:
            RootObject.insert("DataSetSTATFI", "None");
            break;
    }

    switch(us->getDataSet())
    {
        case DataSet::CO2:
            RootObject.insert("DataSetSMEAR", "CO2");
            break;

        case DataSet::SO2:
            RootObject.insert("DataSetSMEAR", "SO2");
            break;

        case DataSet::NO:
            RootObject.insert("DataSetSMEAR", "NO");
            break;

        default:
            RootObject.insert("DataSetSMEAR", "None");
            break;
    }

    switch(us->getMeasuringStation())
    {
        case MeasuringStation::Varrio:
            RootObject.insert("MeasuringStation", "Varrio");
            break;

        case MeasuringStation::Hyytiala:
            RootObject.insert("MeasuringStation", "Hyytiala");
            break;

        case MeasuringStation::Kumpula:
            RootObject.insert("MeasuringStation", "Kumpula");
            break;

        case MeasuringStation::None:
            RootObject.insert("MeasuringStation", "None");
            break;
    }

    switch(us->getAggregateType())
    {
        case AggregateType::Arithmetic:
            RootObject.insert("AggregateType", "Arithmetic");
            break;

        case AggregateType::Availability:
            RootObject.insert("AggregateType", "Availability");
            break;

        case AggregateType::Circular:
            RootObject.insert("AggregateType", "Circular");
            break;

        case AggregateType::Geometric:
            RootObject.insert("AggregateType", "Geometric");
            break;

        case AggregateType::Max:
            RootObject.insert("AggregateType", "Max");
            break;

        case AggregateType::Median:
            RootObject.insert("AggregateType", "Median");
            break;

        case AggregateType::Min:
            RootObject.insert("AggregateType", "Min");
            break;

        case AggregateType::None:
            RootObject.insert("AggregateType", "None");
            break;

        case AggregateType::Sum:
            RootObject.insert("AggregateType", "Sum");
            break;
    }

    RootObject.insert("DateStart", QString::fromStdString(us->getStart().toString()));
    RootObject.insert("DateEnd", QString::fromStdString(us->getEnd().toString()));

    // write all changes back to the file
    JsonDocument.setObject(RootObject); // set to json document
    file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
    auto result = file.write(JsonDocument.toJson());
    file.close();

    if(result != -1){
        qDebug() << "data written succesfully";
    }
    else{
        qDebug() << "error occured when writing data";
    }
}

UserSelections* LoadoutHandler::load()
{
    // load the "loadout.json" file
    QFile file;
    file.setFileName("loadout.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QJsonParseError JsonParseError;
    QJsonDocument JsonDocument = QJsonDocument::fromJson(file.readAll(), &JsonParseError);
    file.close();

    QJsonObject RootObject = JsonDocument.object();

    // check if a loadout has been saved before
    if(RootObject.isEmpty()){
        return nullptr;
    }

    // read all relevant data from the json file
    QString db = RootObject["DataSource"].toString();
    QString ds_statfi = RootObject["DataSetSTATFI"].toString();
    QString ds_smear = RootObject["DataSetSMEAR"].toString();
    QString mstat = RootObject["MeasuringStation"].toString();
    QString aggtype = RootObject["AggregateType"].toString();
    QString date_start = RootObject["DateStart"].toString();
    QString date_end = RootObject["DateEnd"].toString();

}
