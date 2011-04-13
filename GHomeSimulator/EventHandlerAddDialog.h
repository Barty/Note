#ifndef EVENTHANDLERADDDIALOG_H
#define EVENTHANDLERADDDIALOG_H

#include <QDialog>
#include "EventHandler.h"

namespace Ui {
    class EventHandlerAddDialog;
}

class EventHandlerAddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EventHandlerAddDialog(QWidget *parent = 0);
    ~EventHandlerAddDialog();
    HandlerData handlerData();

private:
    Ui::EventHandlerAddDialog *ui;

};

#endif // EVENTHANDLERADDDIALOG_H
