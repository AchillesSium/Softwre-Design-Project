#include "networkcalls.h"
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

networkcalls::networkcalls()
{

}


void networkcalls::queryStatFi()
{

    QNetworkAccessManager *mgr = new QNetworkAccessManager(this);
    const QUrl url(QStringLiteral("https://pxnet2.stat.fi:443/PXWeb/api/v1/en/ymp/taulukot/Kokodata.px"));
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

    /*QJsonArray year_array;
    year_array.push_back(QString("2015"));
    QJsonObject selectionVuosi;
    selectionVuosi["values"] = year_array;
    selectionVuosi["filter"] = "item";
    QJsonObject codeVuosi;
    codeVuosi["code"] = "Vuosi";
    codeVuosi["selection"] = selectionVuosi;*/

    QJsonArray query_array;
    query_array.push_back(codeTiedot);
    //query_array.push_back(codeVuosi);

    QJsonObject query;
    query["query"] = query_array;
   // QJsonArray query_array1;
   // query["query"] = query_array1;

    QJsonObject format;
    format["format"] =  "json-stat2";
    query["response"] =  format;

    QJsonDocument doc(query);
    QByteArray data = doc.toJson();
    qDebug() << "query" << query ;

    QNetworkReply *reply = mgr->post(request, data);

    QObject::connect(reply, &QNetworkReply::finished, [=](){
        if(reply->error() == QNetworkReply::NoError){
            //QString contents = QString::fromUtf8(reply->readAll());
            //qDebug() << contents;
            // needs to be commented out since apparently the data form from the reply can be read only once
            obj_ = QJsonDocument::fromJson(reply->readAll()).object();
            qDebug() << obj_;
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

QJsonObject networkcalls::getObject()
{
    return obj_;
}

