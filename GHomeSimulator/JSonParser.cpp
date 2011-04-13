#include "JSonParser.h"

JSonParser::JSonParser()
{
    paquetJSon = "";
}

JSonParser::JSonParser(QString json)
{
    script = engine.evaluate("("+json+")");
}

QString JSonParser::getStringValue(QString attribut)
{
    return script.property(attribut).toString();
}

qreal JSonParser::getNumericValue(QString attribut)
{
    return script.property(attribut).toNumber();
}

QList<int> JSonParser::getTabValues(QString attribut)
{

    QList<int> items;
    qScriptValueToSequence(script.property(attribut), items);

    return items;
}


void JSonParser::put(QString att, QString value)
{
    if (paquetJSon.isEmpty())
    {
        paquetJSon.append("{");
    }
    else
    {
        paquetJSon.append(",");
    }

    paquetJSon.append("\"");
    paquetJSon.append(att);
    paquetJSon.append("\"");

    paquetJSon.append(":\"");
    paquetJSon.append(value);
    paquetJSon.append("\"");
}

void JSonParser::put(QString att, int value)
{
    if (paquetJSon.isEmpty())
    {
        paquetJSon.append("{");
    }
    else
    {
        paquetJSon.append(",");
    }

    paquetJSon.append("\"");
    paquetJSon.append(att);
    paquetJSon.append("\"");

    paquetJSon.append(":");
    paquetJSon.append(QString::number(value));
    paquetJSon.append("");
}

void JSonParser::put(QString att, QList<int> value)
{
    QString valueStr = "[";
    for (int i = 0; i < value.size()-1; ++i)
    {
        valueStr.append(QString::number(value[i])+",");
    }

    valueStr.append(QString::number(value[value.size()-1])+"]");


    if (paquetJSon.isEmpty())
    {
        paquetJSon.append("{");
    }
    else
    {
        paquetJSon.append(",");
    }
    paquetJSon.append("\"");
    paquetJSon.append(att);
    paquetJSon.append("\"");

    paquetJSon.append(":");
    paquetJSon.append(valueStr);
    paquetJSon.append("");

}

void JSonParser::clear()
{
    paquetJSon="";
}


QString JSonParser::toString()
{
    return paquetJSon.append("}");
}

void JSonParser::envoyerPaquet(QTcpSocket *socket)
{
    if (!paquetJSon.isEmpty())
    {
        paquetJSon.append("}");
        paquetJSon.append('\n');

        QByteArray paquet;
        //QDataStream out (&paquet,QIODevice::WriteOnly);

        //socket->write(paquetJSon.toUtf8());
        //preparation du paquet
        //out << (quint16) 0;
        //out << paquetJSon.toAscii();
        //out.device()->seek(0);
        //out << (quint16) (paquet.size() - sizeof(quint16));

        qDebug() << "taille du paquet envoye : "+ QString::number(paquet.size());

        qDebug() << "paquet Envoye : " + paquetJSon.toUtf8()+"*";

        socket->write(paquetJSon.toAscii()
                      );
    }

}
