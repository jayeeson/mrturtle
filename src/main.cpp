#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuick>
#include "CommandInterpreter.h"
#include "Turtle.h"

int main(int argc, char *argv[])
{
  QGuiApplication app(argc, argv);
  QQmlApplicationEngine engine("qrc:/main.qml");
  return app.exec();
}