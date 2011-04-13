#ifndef JSONPARSER_H
#define JSONPARSER_H

#include<QString>
#include<QScriptEngine>
#include<QTcpSocket>

class JSonParser
{
public:
    JSonParser();
    JSonParser(QString json);
    QString getStringValue(QString attribut);
    qreal getNumericValue(QString attribut);
    QList<int> getTabValues(QString attribut);

    void put(QString att, QString value);
    void put(QString att, int value);
    void put(QString att, QList<int> value);
    void clear();
    QString toString();

    void envoyerPaquet(QTcpSocket *socket);

private:
    QScriptValue script;
    QScriptEngine engine;

    QString paquetJSon;
};

#endif // JSONPARSER_H
