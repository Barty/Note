#include "ui_Technologie_Liste.h"
#include "QHBoxLayout"

ui_Technologie_Liste::ui_Technologie_Liste(QWidget *parent) :
    QWidget(parent)
{
    btAfficherDetails = new QPushButton("Technologie inconnue", this);
    lbInformations = new QLabel("version du driver inconnue",this);
    QHBoxLayout *layout = new QHBoxLayout(this);

    layout->addWidget(btAfficherDetails);
    layout->addWidget(lbInformations);
    this->setLayout(layout);

}


void ui_Technologie_Liste::setInformations(QString nom, QString driverVersion)
{
    btAfficherDetails->setText(nom);
    lbInformations->setText("Driver : <strong>"+driverVersion+".0</strong>");
}


QPushButton *ui_Technologie_Liste::afficherDetails()
{
    return btAfficherDetails;
}

