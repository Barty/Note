#include "EventHandlerAddDialog.h"
#include "ui_EventHandlerAddDialog.h"

EventHandlerAddDialog::EventHandlerAddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EventHandlerAddDialog)
{
    ui->setupUi(this);
}

EventHandlerAddDialog::~EventHandlerAddDialog()
{
    delete ui;
}


HandlerData EventHandlerAddDialog::handlerData()
{
    HandlerData data;
    data.eventType = ui->eEventType->text();
    data.value = ui->eValue->text();
    data.trigger = ui->comboBox->currentText();

    data.sendId = ui->eSendId->text();
    data.sendAttribute = ui->eSendAttribute->text();
    data.sendValue = ui->eSendValue->text();

    return data;

}
