#ifndef GHOMEDEVICESLIST_H
#define GHOMEDEVICESLIST_H

#include <QMap>
#include <QString>
#include <QTcpSocket>

typedef struct {
    QString address;
    QString type;
    QTcpSocket *socket;
} Device;


class GHomeDevicesList
{
public:
    GHomeDevicesList();
    bool addDevice(int deviceId,QString address, QString type,QTcpSocket *s);
    void removeDevice(int deviceId);
    QTcpSocket *Socket(int deviceId);
    QStringList getAllGHomeId();
private:

    QMap<int, Device> devices;
};

#endif // GHOMEDEVICESLIST_H
