#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuick>
#include "CommandInterpreter.h"
#include "Turtle.h"
#include <iostream>

int main(int argc, char *argv[])
{
  QGuiApplication app(argc, argv);

  Turtle turtle;

  QQmlApplicationEngine engine;
  engine.rootContext()->setContextProperty("cppTurtle", &turtle);
  engine.load("qrc:/main.qml");
  return app.exec();
}