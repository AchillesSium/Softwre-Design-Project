#ifndef NETWORKCALLS_H
#define NETWORKCALLS_H

#include <QtNetwork/QNetworkReply>
#include <QObject>
#include <QStringList>
#include <QJsonObject>
#include "unordered_map"

using std::string;

class networkcalls: public QObject
{
    Q_OBJECT
public:
    networkcalls();
    virtual ~networkcalls();
    virtual void getDataFromApi();
    virtual void postDataToApi();
    virtual QJsonObject getObject(bool getData);
signals:
    void done();
private:
    QJsonObject obj_;
};

#endif // NETWORKCALLS_H
