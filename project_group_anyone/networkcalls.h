#ifndef NETWORKCALLS_H
#define NETWORKCALLS_H

#include <QtNetwork/QNetworkReply>
#include <QObject>
#include <QStringList>
#include <QJsonObject>
#include "unordered_map"

using std::string;

/**
 * @brief The networkcalls class
 * Parent class for classes that make network API queries.
 */
class networkcalls: public QObject
{
    Q_OBJECT
public:
    networkcalls();
    virtual ~networkcalls();
    virtual void query();
    virtual QJsonObject getObject();
signals:
    void done();
private:
    QJsonObject obj_;
};

#endif // NETWORKCALLS_H
