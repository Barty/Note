#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>

#include "ui_Technologie_Liste.h"
#include "ClientTechnologie.h"
#include "GHomeDevicesList.h"
#include "EventHandler.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void deconnexionClient();


private:
    Ui::MainWindow *ui;
    QList<ClientTechnologie *> clients;
    GHomeDevicesList *devices;
    EventHandler *handler;
    QLabel *attenteClientsMsg;
    QTcpServer *serveurTcp;

private slots:
        void nouvelleConnexion();
        void deconnexionTechnologie(QString);
};

#endif // MAINWINDOW_H
