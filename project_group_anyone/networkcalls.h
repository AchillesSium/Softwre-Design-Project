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
    explicit networkcalls();
    void queryStatFi();
    QJsonObject getObject();
    void querySmearStation();
signals:
    void done();
private:
    QJsonObject obj_;
};

#endif // NETWORKCALLS_H
