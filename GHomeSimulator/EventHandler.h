#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QString>
#include <QList>
#include <QTcpSocket>

typedef struct
{
    QString receiverId;
    QString eventType;
    QString value;
    QString trigger;

    QString sendId;
    QString sendAttribute;
    QString sendValue;
    QTcpSocket *sendSocket;
} HandlerData;


class EventHandler
{
public:
    EventHandler();
    void addEvent(HandlerData hd);
    void checkEvents(QString id, QString eventType, QString value);

private:
    QList<HandlerData> handlers;
};

#endif // EVENTHANDLER_H
