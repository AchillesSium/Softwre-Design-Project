#include "statfinetworkcall.h"
#include "userselections.h"
#include <iostream>

#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include <QUrl>
#include <QUrlQuery>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QDebug>
#include <string>
#include <QStringList>
#include <QVector>
#include <QJsonArray>
#include <QDate>

/**
 * @brief tatfinetworkcall::statfinetworkcall
 * Constructor of the class
 */
statfinetworkcall::statfinetworkcall()
{

}

/**
 * @brief tatfinetworkcall::~statfinetworkcall
 * Destructor of the class
 */
statfinetworkcall::~statfinetworkcall()
{

}

/**
    * @brief statfinetworkcall::query
    * API call for STATFI data
    * Set the statfObj_ once the api call is successfull
*/
void statfinetworkcall::query()
{
    QNetworkAccessManager *mgr = new QNetworkAccessManager(this);
    const QUrl url(statfiUrl);
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonArray gas_array;
    gas_array.push_back(QString("Khk_yht"));
    gas_array.push_back(QString("Khk_yht_index"));
    gas_array.push_back(QString("Khk_yht_las"));
    gas_array.push_back(QString("Khk_yht_las_index"));

    QJsonObject selectionTiedot;
    selectionTiedot["values"] = gas_array;
    selectionTiedot["filter"] = "item";
    QJsonObject codeTiedot;
    codeTiedot["code"] = "Tiedot";
    codeTiedot["selection"] = selectionTiedot;

    QJsonArray query_array;
    query_array.push_back(codeTiedot);

    QJsonObject query;
    query["query"] = query_array;

    QJsonObject format;
    format["format"] =  "json-stat2";
    query["response"] =  format;

    QJsonDocument doc(query);
    QByteArray data = doc.toJson();
    qDebug() << "query" << query ;

    QNetworkReply *reply = mgr->post(request, data);

    QObject::connect(reply, &QNetworkReply::finished, [=](){
        if(reply->error() == QNetworkReply::NoError){
            // needs to be commented out since apparently the data form from the reply can be read only once
            statfObj_ = QJsonDocument::fromJson(reply->readAll()).object();
            emit done();
        }else{
            QString err = reply->errorString();
            QVariant statusCode = reply->attribute( QNetworkRequest::HttpStatusCodeAttribute );
            qDebug() << statusCode.toInt();
            qDebug() << err;
            emit done();
        }
        reply->deleteLater();
    });
}

/**
    * @brief statfinetworkcall::getObject
    * returns object of statfi obtained from API call
    * @return object of statfi
*/
QJsonObject statfinetworkcall::getObject()
{
    return statfObj_;
}

