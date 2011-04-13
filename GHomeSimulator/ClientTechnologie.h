#ifndef CLIENTTECHNOLOGIE_H
#define CLIENTTECHNOLOGIE_H

#include <QObject>
#include <QTcpSocket>
#include "ui_technologie_details.h"
#include "ui_Technologie_Liste.h"
#include "EventHandler.h"

class ClientTechnologie : public QObject
{
    Q_OBJECT

public:
    ClientTechnologie(QTcpSocket *socket, GHomeDevicesList *list, EventHandler *evtHandler, QObject *parent = 0);
    explicit ClientTechnologie(QObject *parent = 0);
    ~ClientTechnologie();
    QTcpSocket *Socket();
    QString Nom();
    ui_Technologie_Liste *technologie();


signals:
    void infoDeconnexion(QString);
private slots:
    void donneesRecues();
    void deconnexion();

private:
    // UI Associées
    ui_technologie_details *details;
    ui_Technologie_Liste *liste;
    // Communication
    QTcpSocket *socket;
    GHomeDevicesList *devices;
    EventHandler *handler;
    quint16 tailleMessage;

    //infos sur la technologie :
    QString nom;
    int driverVersion;

};

#endif // CLIENTTECHNOLOGIE_H
