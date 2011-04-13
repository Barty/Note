#ifndef UI_TECHNOLOGIE_LISTE_H
#define UI_TECHNOLOGIE_LISTE_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

class ui_Technologie_Liste : public QWidget
{
    Q_OBJECT
public:
    explicit ui_Technologie_Liste(QWidget *parent = 0);
    void setInformations(QString nom, QString driverInformation = "version du driver inconnue");
    QPushButton *afficherDetails();
signals:

public slots:

private:
    QPushButton *btAfficherDetails;
    QLabel *lbInformations;

};

#endif // UI_TECHNOLOGIE_LISTE_H
