#include <QStringList>
#include "GHomeDevicesList.h"

GHomeDevicesList::GHomeDevicesList()
{
    devices.clear();
}


bool GHomeDevicesList::addDevice(int deviceId, QString address, QString type,QTcpSocket *socket)
{
    if (devices.find(deviceId) != devices.end())
    {
        return false;
    }
    Device newDevice;
    newDevice.address = address;
    newDevice.type = type;
    newDevice.socket = socket;

    devices.insert(deviceId,newDevice);
    return true;
}

void GHomeDevicesList::removeDevice(int deviceId)
{
    devices.remove(deviceId);

}

QStringList GHomeDevicesList::getAllGHomeId()
{
    QMapIterator<int, Device> iterator(devices);

    QStringList devicesList;
    while (iterator.hasNext())
    {
        iterator.next();
        devicesList << QString::number(iterator.key());
    }
}

QTcpSocket *GHomeDevicesList::Socket(int deviceId)
{
    return devices[deviceId].socket;
}
