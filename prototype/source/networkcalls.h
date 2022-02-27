#ifndef NETWORKCALLS_H
#define NETWORKCALLS_H

#include <QtNetwork/QNetworkReply>
#include <QObject>
#include <QStringList>

using std::string;

class networkCalls: public QObject
{
    Q_OBJECT
public:
    explicit networkCalls();
    void queryStatFi(QMap<string, string *>);
private slots:
    void replyFinished(QNetworkReply *reply);
};

#endif // NETWORKCALLS_H
