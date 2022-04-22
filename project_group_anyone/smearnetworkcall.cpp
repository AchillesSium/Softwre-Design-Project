#include "smearnetworkcall.h"
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
#include "userselections.h"

using namespace std;

/**
 * @brief smearnetworkcall::smearnetworkcal
 * Constructor of the class
 */
smearnetworkcall::smearnetworkcall()
{

}

/**
 * @brief smearnetworkcall::smearnetworkcal
 * Constructor of the class
 * @param selections
 */
smearnetworkcall::smearnetworkcall(UserSelections* selections)
{
    userSelections = selections;
}


/**
 * @brief smearnetworkcall::~smearnetworkcal
 * Destructor of the class
 */
smearnetworkcall::~smearnetworkcall()
{

}

/**
    * @brief smearnetworkcall::query
    * API call for SMEAR data according to user selection
    * Set the timeSeriesObj_ once the api call is successfull
*/
void smearnetworkcall::query()
{
    QString str = QString::fromUtf8(userSelections->toQuery().c_str());
    qDebug() << "Query" << str;

    QNetworkAccessManager *mgr = new QNetworkAccessManager(this);
    QUrl url(str);

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = mgr->get(request);

    QObject::connect(reply, &QNetworkReply::finished, [=](){
        if(reply->error() == QNetworkReply::NoError){
            // needs to be commented out since apparently the data form from the reply can be read only once
            timeSeriesObj_ = QJsonDocument::fromJson(reply->readAll()).object();
            emit done();
        }
        else{
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
    * @brief smearnetworkcall::getObject
    * returns object of time series obtained from API call
    * @return object of time series
*/
QJsonObject smearnetworkcall::getObject()
{
    return timeSeriesObj_;
}

