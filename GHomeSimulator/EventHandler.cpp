#include "EventHandler.h"
#include "JSonParser.h"


EventHandler::EventHandler()
{
}

void EventHandler::addEvent(HandlerData hd)
{
    /*HandlerData newHandler;
    newHandler.receiverId = receiverId;
    newHandler.eventType = eventType;
    newHandler.value = value;
    newHandler.trigger = trigger;
    newHandler.sendId = sendId;
    newHandler.sendAttribute = sendAttribute;
    newHandler.sendValue = sendValue;
    newHandler.sendSocket = socket;*/

    qDebug()<< "receiverId    : " << hd.receiverId << "<br>"
            << "eventType     : " << hd.eventType << "<br>"
            << "value         : " << hd.value << "<br>"
            << "trigger       : " << hd.trigger << "<br>"
            << "sendId        : " << hd.sendId << "<br>"
            << "sendAttribute : " << hd.sendAttribute << "<br>"
            << "sendValue     : " << hd.sendValue << "<br>";

    handlers << hd;//newHandler;
}


void EventHandler::checkEvents(QString id, QString eventType, QString value)
{
    JSonParser parser;
    for (int i=0; i<handlers.size(); i++)
    {
        if (handlers[i].receiverId == id && handlers[i].eventType == eventType)
        {
            parser.put("request","SetDeviceAttribute");
            parser.put("deviceId",handlers[i].sendId);
            parser.put("attName",handlers[i].sendAttribute);
            parser.put("value",handlers[i].sendValue);

            if (handlers[i].trigger == "above" && handlers[i].value.toInt() < value.toInt())
            {
                parser.envoyerPaquet(handlers[i].sendSocket);
            } else
            if (handlers[i].trigger == "below" && handlers[i].value.toInt() > value.toInt())
            {
                parser.envoyerPaquet(handlers[i].sendSocket);
            } else
            if (handlers[i].trigger == "equal" && handlers[i].value == value)
            {
                parser.envoyerPaquet(handlers[i].sendSocket);
            }
        }
    }

}
