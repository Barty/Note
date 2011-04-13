#include "ClientTechnologie.h"
#include "MainWindow.h"
#include <QMessageBox>
#include <QList>
#include "JSonParser.h"

ClientTechnologie::ClientTechnologie(QObject *parent) :
    QObject(parent)
{

}

ClientTechnologie::ClientTechnologie(QTcpSocket *s, GHomeDevicesList *list, EventHandler *evtHandler, QObject *parent) :
    QObject(parent)
{
    tailleMessage = 0;

    devices = list;
    handler = evtHandler;
    socket = s;
    nom = "inconnu";
    connect(socket,SIGNAL(readyRead()),this,SLOT(donneesRecues()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(deconnexion()));

    JSonParser parser;

    parser.put("request","GetTechName");
    parser.envoyerPaquet(socket);

    parser.clear();
    parser.put("request","GetDriverApiVersion");

    parser.envoyerPaquet(socket);

    liste = new ui_Technologie_Liste();
    details = new ui_technologie_details(socket,devices,handler);
    connect(liste->afficherDetails(),SIGNAL(clicked()),details,SLOT(show()));

    // On verifie qu'on a pas reçu de paquets avant la connexion au slot
    donneesRecues();

}

ClientTechnologie::~ClientTechnologie()
{
    delete liste;
    delete details;
}

QTcpSocket *ClientTechnologie::Socket()
{
    return socket;
}

QString ClientTechnologie::Nom()
{
    return nom;
}

void ClientTechnologie::donneesRecues()
{
    while (socket->canReadLine())
    {

        // Si tout va bien, on continue : on recupère le message
        QDataStream in(socket);

        QString text = QString::fromAscii(socket->readLine());
        qDebug()<<"paquet recu : " +text;

        JSonParser parser(text);    //creation d'un objet parser

        QString requete = parser.getStringValue("request"); //on recupère le nom de la requète reçue

        if (requete=="GetTechName")
        {
            nom = parser.getStringValue("name");
            details->setWindowTitle(nom);
            liste->setInformations(nom);
        } else
        if (requete=="GetDriverApiVersion")
        {
            driverVersion = parser.getNumericValue("driverApiVersion");
            QString driverVersionStr = QString::number(driverVersion);
            this->liste->setInformations(nom,driverVersionStr);
        } else
        if (requete == "GetDeviceAttribute")
        {
            QString attribute = parser.getStringValue("attName");
            QString value = parser.getStringValue("value");
            QString message = "<strong>Device Attribute : </strong> "+ attribute + " value : " + value;
            details->addEvent(message);
            //QMessageBox::information(0,"Device Attribute","<strong>"+nom+" : </strong>"+attribute+" = "+value,QMessageBox::Ok);
        } else
        if (requete == "SetDeviceAttribute")
        {
            QString attribute = parser.getStringValue("attName");
            QString valueSet = QString::number(parser.getNumericValue("valueSet"));
            QString message = "<strong>Set device Attribute return : </strong> "+ attribute + " valueSet : " + valueSet;
            details->addEvent(message);
            //QMessageBox::information(0,"Device Attribute","<strong>"+nom+" : </strong>"+attribute+"Set = "+valueSet,QMessageBox::Ok);
        } else
        if (requete == "AutoDetectDevices")
        {
            QString device = parser.getStringValue("device");
            QString type  = parser.getStringValue("type");
            details->addAutoDectedDevice(device,type);
        } else
        if (requete == "RegisterDevices")
        {
            QString state = QString::number(parser.getNumericValue("state"));

            QString message = "<strong>Register Device returned : </strong> "+ nom + " state : " + state;
            details->addEvent(message);
        } else
        if (requete == "GetRegisteredDevices")  //la liste des devices connectes
        {
            QList<int> devices = parser.getTabValues("devices");    //on recupère le tableau sous forme de liste
            QString devicesStr = "[ ";
            for (int i = 0; i < devices.size()-1; ++i) {
                devicesStr.append(QString::number(devices[i])+", ");
             }
            devicesStr.append(QString::number(devices.at(devices.size()-1))+"]");

            QString message = "<strong>Registered Devices : </strong> "+ devicesStr;
            details->addEvent(message);

            //QMessageBox::information(0,"donnees reçues",QString("RegisteredDevices :"+devicesStr),QMessageBox::Ok);
        } else
        if (requete == "CheckDeviceStatus")
        {
            QString status = QString::number(parser.getNumericValue("status"));

            QString message = "<strong>Check Device Status returned : </strong> status : "+ status;
            details->addEvent(message);

            //QMessageBox::information(0,"Device Attribute","<strong>"+nom+" : </strong> status = "+status,QMessageBox::Ok);

        }else
        if (requete == "ThrowEvent")
        {
            QString device = QString::number(parser.getNumericValue("deviceId"));
            QString type = parser.getStringValue("eventType");
            QString value = parser.getStringValue("value");
            /*QMessageBox::information(0,"throwEvent","<strong>"+nom+" : </strong> device <strong>"+
                                                              device+"</strong> sent event : <strong>"+
                                                              adr+"</strong> with value : <strong>"+
                                                              value+"</strong>",QMessageBox::Ok);
            */
            QString message = "<strong>"+device + "</strong> : " + type + ", value = "+value;
            details->addEvent(message);
            handler->checkEvents(device,type, value);
        }

    }

}

void ClientTechnologie::deconnexion()
{
    emit infoDeconnexion(nom);
}

ui_Technologie_Liste *ClientTechnologie::technologie()
{
    return liste;
}
