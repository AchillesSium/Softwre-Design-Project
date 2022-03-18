#ifndef NETWORKCALLS_H
#define NETWORKCALLS_H

#include <QtNetwork/QNetworkReply>
#include <QObject>
#include <QStringList>
#include <QJsonObject>

using std::string;

class networkcalls: public QObject
{
    Q_OBJECT
public:
    explicit networkcalls();
    void queryStatFi();
    QJsonObject getObject();
signals:
    void done();
private:
    QJsonObject obj_;
};

#endif // NETWORKCALLS_H
