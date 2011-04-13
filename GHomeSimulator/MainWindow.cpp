#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QMessageBox>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serveurTcp = new QTcpServer(this);
    connect(serveurTcp,SIGNAL(newConnection()),this,SLOT(nouvelleConnexion()));

    bool ok;
    int serverPort = QInputDialog::getInt(this,"Port du serveur","Veuillez selectionner le port d'ecoute du serveur",5001,0,65535,1,&ok);

    serveurTcp->listen(QHostAddress::Any,serverPort);
    if (!serveurTcp->isListening())
        QMessageBox::information(this,"Erreur Serveur","Erreur au demarrage du serveur le port est deja utilise",QMessageBox::Ok);

    attenteClientsMsg = new QLabel("Attente de connexion d'une technologie",this);
    attenteClientsMsg->setAlignment(Qt::AlignCenter | Qt::AlignHCenter);
    centralWidget()->layout()->addWidget(attenteClientsMsg);

    devices = new GHomeDevicesList();
    handler = new EventHandler();

}


MainWindow::~MainWindow()
{
    delete ui;
    delete devices;
    delete handler;
}


void MainWindow::nouvelleConnexion()
{
    QMessageBox::information(this, "nouvelle connexion", "Un nouveau client vient de se connecter");

    if (clients.isEmpty())
    {
        centralWidget()->layout()->removeWidget(attenteClientsMsg);
        attenteClientsMsg->deleteLater();
    }


    ClientTechnologie *nouveauClient=new ClientTechnologie(serveurTcp->nextPendingConnection(),devices,handler);
    clients << nouveauClient; //nouveau Client



    centralWidget()->layout()->addWidget(nouveauClient->technologie());

    connect(nouveauClient,SIGNAL(infoDeconnexion(QString)),this,SLOT(deconnexionTechnologie(QString)));
}


void MainWindow::deconnexionTechnologie(QString nom)
{
    QMessageBox::information(this,"deconnexion","La technologie <strong>"+nom+"</strong> s'est deconnectee");
    ClientTechnologie *clientDeco = ((ClientTechnologie *) sender());


    clients.removeOne(clientDeco);
    clientDeco->deleteLater();
    if (clients.isEmpty())
    {
        attenteClientsMsg = new QLabel("Attente de connexion d'une technologie",this);
        attenteClientsMsg->setAlignment(Qt::AlignCenter | Qt::AlignHCenter);
        centralWidget()->layout()->addWidget(attenteClientsMsg);
    }
}
