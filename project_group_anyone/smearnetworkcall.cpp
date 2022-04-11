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

smearnetworkcall::smearnetworkcall()
{

}

smearnetworkcall::~smearnetworkcall()
{

}

void smearnetworkcall::querySmearStations()
{
    QNetworkAccessManager *mgr = new QNetworkAccessManager(this);
    const QUrl url(QStringLiteral("https://smear-backend.rahtiapp.fi/station"));
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = mgr->get(request);

    QObject::connect(reply, &QNetworkReply::finished, [=](){
        if(reply->error() == QNetworkReply::NoError){

            //QString contents = QString::fromUtf8(reply->readAll());
            //qDebug() << contents;
            //QJsonObject obj = QJsonDocument::fromJson(reply->readAll()).object();
            //qDebug() << obj;

            QString contents = QString::fromUtf8(reply->readAll());
            qDebug() << contents;
            // needs to be commented out since apparently the data form from the reply can be read only once
            stationObj_ = QJsonDocument::fromJson(reply->readAll()).object();
            qDebug() << "Smear station" << stationObj_;
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

void smearnetworkcall::querySmearTimeSeries(QString aggregation, int interval, QString startDate, QString endDate, QString tableVariable)
{
    QString intervalStr = QString::number(interval);

    QString from = startDate + "T00:00:00.000";
    QString to = endDate + "T23:59:59.000";

    QNetworkAccessManager *mgr = new QNetworkAccessManager(this);
    QUrl url(QStringLiteral("https://smear-backend.rahtiapp.fi/search/timeseries"));
    QUrlQuery query;
    query.addQueryItem("aggregation", aggregation);
    query.addQueryItem("interval", intervalStr);
    query.addQueryItem("from", from);
    query.addQueryItem("to", to);
    query.addQueryItem("tablevariable", tableVariable);
    url.setQuery(query.query());

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = mgr->get(request);

    QObject::connect(reply, &QNetworkReply::finished, [=](){
        if(reply->error() == QNetworkReply::NoError){

            //QString contents = QString::fromUtf8(reply->readAll());
            //qDebug() << contents;
            //QJsonObject obj = QJsonDocument::fromJson(reply->readAll()).object();
            //qDebug() << obj;

            QString contents = QString::fromUtf8(reply->readAll());
            qDebug() << contents;
            // needs to be commented out since apparently the data form from the reply can be read only once
            timeSeriesObj_ = QJsonDocument::fromJson(reply->readAll()).object();
            qDebug() << "Smear timeseries" << timeSeriesObj_;
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

QJsonObject smearnetworkcall::getStationObject()
{
    return stationObj_;
}

QJsonObject smearnetworkcall::getTimeSeriesObject()
{
    return timeSeriesObj_;
}
