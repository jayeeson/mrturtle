#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuick>
#include "CommandExecutor.h"
#include "Turtle.h"
#include "CanvasData.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    CanvasData canvas;
    Turtle turtle(canvas);
    CommandExecutor commandExecutor(turtle);

    engine.rootContext()->setContextProperty("cppCanvas", &canvas);
    engine.rootContext()->setContextProperty("cppTurtle", &turtle);
    engine.rootContext()->setContextProperty("cppCommand", &commandExecutor);

    engine.load("qrc:/main.qml");

    int ret = app.exec();
    return ret;
}