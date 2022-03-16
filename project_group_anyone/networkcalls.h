#ifndef NETWORKCALLS_H
#define NETWORKCALLS_H

#include <QtNetwork/QNetworkReply>
#include <QObject>
#include <QStringList>

using std::string;

class networkcalls: public QObject
{
    Q_OBJECT
public:
    explicit networkcalls();
    void queryStatFi();
};

#endif // NETWORKCALLS_H
