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

networkcalls::networkcalls()
{

}


void networkcalls::queryStatFi(QString str)
{
    //the network manager will post and recieve our HTTP requests
        QNetworkAccessManager *manager = new QNetworkAccessManager(this);

        //the host of the webservice
        QUrl url("https://pxnet2.stat.fi:443/PXWeb/api/v1/en/ymp/taulukot/Kokodata.px");

        //set up the request to post
        QNetworkRequest request(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

        //the additional query data to enter
         QUrlQuery query(url);
//         QMapIterator<string, string *> i(map);
//         while (i.hasNext()) {
//             i.next();

//         }
         query.addQueryItem("query",str);
         QString val = "{'format': 'json-stat2'}}";
         query.addQueryItem("response",val);
         url.setQuery(query);

         //update the request with the new query information.
             request.setUrl(url);

             //post the request
             manager->post(request, url.toEncoded());

             //connect the "finished" signal from the manager to our response handling method
             QObject::connect(manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinished(QNetworkReply *)));

}

void networkcalls::replyFinished(QNetworkReply *reply)
{
    if ( reply->error() != QNetworkReply::NoError ){
            // A communication error has occurred
            return;
        }

        //We read the JSON response into a QJsonObject
        QJsonObject obj = QJsonDocument::fromJson(reply->readAll()).object();

        QString strFromObj = QJsonDocument(obj).toJson(QJsonDocument::Compact).toStdString().c_str();

        //qDebug("asv" + strFromObj);
        qDebug().nospace() << "abc" << qPrintable(strFromObj) << "def";
}

