#ifndef UI_TECHNOLOGIE_DETAILS_H
#define UI_TECHNOLOGIE_DETAILS_H

#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QTableView>
#include <QStandardItemModel>
#include <QTcpSocket>

#include "GHomeDevicesList.h"
#include "EventHandler.h"


class ui_technologie_details : public QWidget
{
    Q_OBJECT

public:
    explicit ui_technologie_details(QWidget *parent = 0);
    explicit ui_technologie_details(QTcpSocket *s, GHomeDevicesList *list, EventHandler *evtHandler);
    ~ui_technologie_details();

    void addEvent(QString message);
    void addAutoDectedDevice(QString device,QString type);
private slots:
    void deviceSelection(QModelIndex);
    void GetDriverApiVersion_clicked();
    void GetDeviceAttribute_clicked();
    void SetDeviceAttribute_clicked();
    void CheckDeviceStatus_clicked();
    void AutoDetectDevices_clicked();
    void GetRegisteredDevices_clicked();
    void RegisterDevices_clicked();
    void AssignateHandler_clicked();

private:
    QTcpSocket *socket;

    QTableView *detectedDevicesList;
    QStandardItemModel *detectedDevicesListModel;

    QTableView *registeredDevicesList;
    QStandardItemModel *registeredDevicesListModel;

    int selectedDetectedDeviceRow;
    int selectedRegisteredDeviceRow;

    QPushButton *btGetDriverApiVersion;

    QPushButton *btGetDeviceAttribute;
    QPushButton *btSetDeviceAttribute;
    QPushButton *btCheckDeviceStatus;

    QPushButton *btAutoDetectDevices;

    QPushButton *btGetRegisteredDevices;
    QPushButton *btRegisterDevice;

    QPushButton *btAssignateHandler;
    QTextEdit *listeMessages;

    GHomeDevicesList *devices;
    EventHandler *handler;

};

#endif // UI_TECHNOLOGIE_DETAILS_H
