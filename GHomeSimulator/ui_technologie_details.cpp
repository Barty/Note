#include "ui_technologie_details.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QInputDialog>
#include <QLabel>
#include <QScrollBar>

#include "JSonParser.h"
#include "EventHandlerAddDialog.h"
#include "ClientTechnologie.h"



ui_technologie_details::ui_technologie_details(QWidget *parent) :
    QWidget(parent)
{

}

ui_technologie_details::ui_technologie_details(QTcpSocket *s, GHomeDevicesList *list, EventHandler *evtHandler)
{
    socket = s;
    devices = list;
    handler = evtHandler;

    // Liste des devices detectes.
    detectedDevicesListModel = new QStandardItemModel(0,2,this);
    detectedDevicesList = new QTableView(this);

    QStringList detectedDevicesHeader;
    detectedDevicesHeader << "Device Address" << "Type";
    detectedDevicesListModel->setHorizontalHeaderLabels(detectedDevicesHeader);
    detectedDevicesList->setSelectionBehavior(QAbstractItemView::SelectRows);
    detectedDevicesList->setSelectionMode(QAbstractItemView::SingleSelection);
    detectedDevicesList->setModel(detectedDevicesListModel);
    connect(detectedDevicesList,SIGNAL(clicked(QModelIndex)),this,SLOT(deviceSelection(QModelIndex)));

    // Liste des devices enregistres.
    registeredDevicesListModel = new QStandardItemModel(0,3,this);
    registeredDevicesList = new QTableView(this);

    QStringList header;
    header << "GHome Id" << "Adresse" << "Type";
    registeredDevicesListModel->setHorizontalHeaderLabels(header);
    registeredDevicesList->setSelectionBehavior(QAbstractItemView::SelectRows);
    detectedDevicesList->setSelectionMode(QAbstractItemView::SingleSelection);
    registeredDevicesList->setModel(registeredDevicesListModel);
    connect(registeredDevicesList,SIGNAL(clicked(QModelIndex)),this,SLOT(deviceSelection(QModelIndex)));



    // Mise en forme des deux tables en un layout avec des labels de description.
    QLabel *detectedText = new QLabel("Auto-Detected devices",this);
    detectedText->setAlignment(Qt::AlignCenter);

    QLabel *registeredText = new QLabel("Registered devices",this);
    registeredText->setAlignment(Qt::AlignCenter);


    // Creation des boutons
    btGetDriverApiVersion = new QPushButton("Get Driver API Version",this);
    btAutoDetectDevices = new QPushButton("Auto Detect Devices",this);

    btGetDeviceAttribute = new QPushButton("Get Device Attribute",this);
    btSetDeviceAttribute = new QPushButton("Set Device Attibute",this);
    btCheckDeviceStatus = new QPushButton("Check Device Status", this);
    btAssignateHandler = new QPushButton("Assignate Handler",this);
    btAssignateHandler->setEnabled(false);
    btCheckDeviceStatus->setEnabled(false);
    btGetDeviceAttribute->setEnabled(false);
    btSetDeviceAttribute->setEnabled(false);

    btGetRegisteredDevices = new QPushButton("Get Registered Devices",this);
    btGetRegisteredDevices->setEnabled(false);
    btRegisterDevice = new QPushButton("Register Device",this);

    connect(btGetDriverApiVersion,SIGNAL(clicked()),this,SLOT(GetDriverApiVersion_clicked()));
    connect(btAutoDetectDevices,SIGNAL(clicked()),this,SLOT(AutoDetectDevices_clicked()));

    connect(btGetDeviceAttribute,SIGNAL(clicked()),this,SLOT(GetDeviceAttribute_clicked()));
    connect(btSetDeviceAttribute,SIGNAL(clicked()),this,SLOT(SetDeviceAttribute_clicked()));
    connect(btCheckDeviceStatus,SIGNAL(clicked()),this,SLOT(CheckDeviceStatus_clicked()));

    connect(btGetRegisteredDevices,SIGNAL(clicked()),this,SLOT(GetRegisteredDevices_clicked()));
    connect(btRegisterDevice,SIGNAL(clicked()),this,SLOT(RegisterDevices_clicked()));

    connect(btAssignateHandler,SIGNAL(clicked()),this,SLOT(AssignateHandler_clicked()));

    // Mise en page des boutons
    QVBoxLayout *layoutBoutons = new QVBoxLayout(0);
    layoutBoutons->addWidget(btGetDriverApiVersion);
    layoutBoutons->addWidget(btAutoDetectDevices);

    layoutBoutons->addSpacerItem(new QSpacerItem(50,20));

    layoutBoutons->addWidget(btRegisterDevice);
    layoutBoutons->addWidget(btGetRegisteredDevices);

    layoutBoutons->addSpacerItem(new QSpacerItem(50,20));

    layoutBoutons->addWidget(btGetDeviceAttribute);
    layoutBoutons->addWidget(btSetDeviceAttribute);
    layoutBoutons->addWidget(btCheckDeviceStatus);
    layoutBoutons->addWidget(btAssignateHandler);

    // Le Log
    listeMessages = new QTextEdit("*** Evenements recus ***",this);

    // Integration de tous les layouts au layout principal
    QGridLayout *layoutPrincipal = new QGridLayout(this);


    layoutPrincipal->addWidget(detectedText,0,0);
    layoutPrincipal->addWidget(registeredText,0,1);
    layoutPrincipal->addWidget(detectedDevicesList,1,0);
    layoutPrincipal->addWidget(registeredDevicesList,1,1);

    layoutPrincipal->addLayout(layoutBoutons,1,2);


    layoutPrincipal->addWidget(listeMessages,2,0,1,-1);

    this->setLayout(layoutPrincipal);
}

ui_technologie_details::~ui_technologie_details()
{

    for (int i=0; i<registeredDevicesListModel->rowCount();i++)
    {
        devices->removeDevice(registeredDevicesListModel->item(i,0)->text().toInt());
    }

    delete detectedDevicesList;
    delete detectedDevicesListModel;

    delete registeredDevicesList;
    delete registeredDevicesListModel;
}



void ui_technologie_details::addEvent(QString message)
{
    bool scroll=false;
    if (listeMessages->verticalScrollBar()->value() == listeMessages->verticalScrollBar()->maximum())
        scroll = true;
    listeMessages->append(message);
    if (scroll)
        listeMessages->verticalScrollBar()->setValue(listeMessages->verticalScrollBar()->maximum());
}

void ui_technologie_details::addAutoDectedDevice(QString device,QString type)
{
    QList<QStandardItem *> list;

    list << new QStandardItem(device);
    list << new QStandardItem(type);

    detectedDevicesListModel->appendRow(list);
    detectedDevicesList->update();
}

void ui_technologie_details::deviceSelection(QModelIndex idx)
{
    if (sender()==detectedDevicesList)
    {
        btRegisterDevice->setEnabled(true);
        selectedDetectedDeviceRow = idx.row();
    } else
    if (sender()==registeredDevicesList)
    {
        btCheckDeviceStatus->setEnabled(true);
        btGetDeviceAttribute->setEnabled(true);
        btSetDeviceAttribute->setEnabled(true);
        btAssignateHandler->setEnabled(true);
        selectedRegisteredDeviceRow = idx.row();
    }
}

void ui_technologie_details::GetDriverApiVersion_clicked()
{
    JSonParser parser;
    parser.put("request","GetDriverApiVersion");
    parser.envoyerPaquet(socket);
}

void ui_technologie_details::GetDeviceAttribute_clicked()
{
    JSonParser parser;
    parser.put("request","GetDeviceAttribute");
    bool ok;
    QString att = QInputDialog::getText(this,"Get Device Attribute","entrez l'attribut : ",QLineEdit::Normal,QString(),&ok);

    if (ok)
    {
        QString selectedDevice = registeredDevicesListModel->item(selectedRegisteredDeviceRow,0)->text();
        parser.put("deviceId",selectedDevice);
        parser.put("attName",att);

        parser.envoyerPaquet(socket);
    }
}

void ui_technologie_details::SetDeviceAttribute_clicked()
{
    JSonParser parser;
    parser.put("request","SetDeviceAttribute");



    int selectedDevice = registeredDevicesListModel->item(selectedRegisteredDeviceRow,0)->text().toInt();
    parser.put("deviceId",selectedDevice);

    bool ok;

    QString att = QInputDialog::getText(this,"Set Device Attribute","entrez l'attribut : ",QLineEdit::Normal,QString(),&ok);
    parser.put("attName",att);

    if (ok)
    {
        QString value = QInputDialog::getText(this,"Set Device Attribute","entrez la valeur : ",QLineEdit::Normal,QString(),&ok);
        parser.put("value",value);
    }

    if (ok)
        parser.envoyerPaquet(socket);
}

void ui_technologie_details::CheckDeviceStatus_clicked()
{
    JSonParser parser;
    parser.put("request","CheckDeviceStatus");

    int selectedDevice = registeredDevicesListModel->item(selectedRegisteredDeviceRow,0)->text().toInt();
    parser.put("deviceId",selectedDevice);

    parser.envoyerPaquet(socket);
}


void ui_technologie_details::AutoDetectDevices_clicked()
{
    JSonParser parser;
    parser.put("request","AutoDetectDevices");

    bool ok;

    int timeout = QInputDialog::getInt(this,"Auto Detect Devices","entrez le timeout : ",0,0,2147483647,1,&ok);
    parser.put("timeout",timeout);

    if(ok)
    {
        int flags = QInputDialog::getInt(this,"Auto Detect Devices","entrez les flags : ",0,0,2147483647,1,&ok);
        parser.put("flags",flags);
    }

    if (ok)
    {
        parser.envoyerPaquet(socket);

        // On vide la liste des devices
        detectedDevicesListModel->clear();
        QStringList header;
        header << "Device Address" << "Type";
        detectedDevicesListModel->setHorizontalHeaderLabels(header);
        detectedDevicesList->setSelectionBehavior(QAbstractItemView::SelectRows);
    }

}


void ui_technologie_details::GetRegisteredDevices_clicked()
{
    JSonParser parser;
    parser.put("request","GetRegisteredDevices");

    parser.envoyerPaquet(socket);
}


void ui_technologie_details::RegisterDevices_clicked()
{
    JSonParser parser;
    parser.put("request","RegisterDevices");

    QString deviceAddressDefault;
    QString deviceTypeDefault;

    QStandardItem *selectedItemAddress = detectedDevicesListModel->item(selectedDetectedDeviceRow,0);
    QStandardItem *selectedItemType = detectedDevicesListModel->item(selectedDetectedDeviceRow,1);
    if ( selectedItemAddress != 0 )
    {
       deviceAddressDefault = selectedItemAddress->text();
       deviceTypeDefault = selectedItemType->text();
   }

    bool ok;

    QString deviceAddress = QInputDialog::getText(this,"Register Devices","entrez l'adresse : ",QLineEdit::Normal,deviceAddressDefault,&ok);
    parser.put("deviceAddress",deviceAddress);

    QString deviceType;
    if(ok)
    {
        deviceType = QInputDialog::getText(this,"Register Devices","entrez le type : ",QLineEdit::Normal,deviceTypeDefault,&ok);
        parser.put("deviceType",deviceType);
    }


    int deviceId = QInputDialog::getInt(this,"Register Devices","entrez l'Id GHome du device selectionne : <br><em>"+deviceAddress+"<br>"+deviceType+"</em>",
                                            registeredDevicesListModel->rowCount(),0,2147483647,1,&ok);

    while (!devices->addDevice(deviceId,deviceAddress,deviceType,socket) && ok)
    {
        deviceId = QInputDialog::getInt(this,"Register Devices","Erreur : l'id est dejà utilise <br> Entrez l'Id GHome du device selectionne : <br><em>"+deviceAddress+"<br>"+deviceType+"</em>",
                                                registeredDevicesListModel->rowCount(),0,2147483647,1,&ok);

    }

    if (ok)
    {
        parser.put("deviceId",deviceId);
        parser.envoyerPaquet(socket);

        // On ajoute le device dans la liste des registered
        QList<QStandardItem *> list;

        list << new QStandardItem(QString::number(deviceId));
        list << new QStandardItem(deviceAddress);
        list << new QStandardItem(deviceType);

        registeredDevicesListModel->appendRow(list);
        btGetRegisteredDevices->setEnabled(true);

    }

}

void ui_technologie_details::AssignateHandler_clicked()
{
    QString receiverId = registeredDevicesListModel->item(selectedRegisteredDeviceRow,0)->text();
    bool ok;


    HandlerData newHandler;
    EventHandlerAddDialog dataDialog(this);
    dataDialog.exec();
    if (dataDialog.result() == dataDialog.Accepted)
    {
        qDebug()<<"if????";
        newHandler = dataDialog.handlerData();
        qDebug()<<"handlerdata???";
        newHandler.receiverId = receiverId;
        newHandler.sendSocket = devices->Socket(newHandler.sendId.toInt());
        qDebug()<<"socket??";
        handler->addEvent(newHandler);
    } else
        return;


    /*newHandler.eventType= QInputDialog::getText(this,"Assignate Handler","entrez le type d'evenement' : ",QLineEdit::Normal,QString(),&ok);
    newHandler.value = QInputDialog::getText(this,"Assignate Handler","entrez la valeur' : ",QLineEdit::Normal,QString(),&ok);
    newHandler.trigger = QInputDialog::getText(this,"Assignate Handler","entrez le trigger' : ",QLineEdit::Normal,QString(),&ok);
    newHandler.sendId = QInputDialog::getText(this,"Assignate Handler","entrez l'id receveur : ",QLineEdit::Normal,QString(),&ok);
    newHandler.sendAttribute = QInputDialog::getText(this,"Assignate Handler","entrez l'attribut receveur : ",QLineEdit::Normal,QString(),&ok);
    newHandler.sendValue = QInputDialog::getText(this,"Assignate Handler","entrez la valeur receveur' : ",QLineEdit::Normal,QString(),&ok);
*/


}
