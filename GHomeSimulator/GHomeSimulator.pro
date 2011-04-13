#-------------------------------------------------
#
# Project created by QtCreator 2011-02-15T11:26:29
#
#-------------------------------------------------

QT       += core gui network script

TARGET = GHomeSimulator
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    ClientTechnologie.cpp \
    ui_Technologie_Liste.cpp \
    ui_technologie_details.cpp \
    JSonParser.cpp \
    GHomeDevicesList.cpp \
    EventHandler.cpp \
    EventHandlerAddDialog.cpp

HEADERS  += MainWindow.h \
    ClientTechnologie.h \
    ui_Technologie_Liste.h \
    ui_technologie_details.h \
    JSonParser.h \
    GHomeDevicesList.h \
    EventHandler.h \
    EventHandlerAddDialog.h

FORMS    += MainWindow.ui \
    EventHandlerAddDialog.ui
