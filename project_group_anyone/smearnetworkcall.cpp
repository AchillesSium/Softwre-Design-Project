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

smearnetworkcall::smearnetworkcall()
{

}

smearnetworkcall::smearnetworkcall(UserSelections* selections)
{
    userSelections = selections;
}

smearnetworkcall::~smearnetworkcall()
{

}

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

            //QString contents = QString::fromUtf8(reply->readAll());
            //qDebug() << contents;
            //QJsonObject obj = QJsonDocument::fromJson(reply->readAll()).object();
            //qDebug() << obj;


//            QString contents = QString::fromUtf8(reply->readAll());
//            qDebug() << contents;

            // needs to be commented out since apparently the data form from the reply can be read only once
            timeSeriesObj_ = QJsonDocument::fromJson(reply->readAll()).object();
            //qDebug() << "Smear timeseries" << timeSeriesObj_;
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

QJsonObject smearnetworkcall::getObject()
{
    return timeSeriesObj_;
}
