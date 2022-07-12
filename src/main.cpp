#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuick>
#include <iostream>

#include "CanvasData.h"
#include "CommandInterpreter.h"
#include "Turtle.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    CanvasData canvas;
    Turtle turtle(canvas);
    CommandInterpreter ci(turtle, canvas);

    engine.rootContext()->setContextProperty("cppCanvas", &canvas);
    engine.rootContext()->setContextProperty("cppTurtle", &turtle);
    engine.rootContext()->setContextProperty("cppCommand", &ci);

    engine.load("qrc:/main.qml");

    int ret = app.exec();
    return ret;
}