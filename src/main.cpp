#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuick>
#include "CommandInterpreter.h"
#include "Turtle.h"
#include "CanvasData.h"
#include <iostream>

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
  // QQmlComponent component(&engine, "qrc:/main.qml");
  // if (component.status() != QQmlComponent::Status::Ready)
  // {
  //   for (auto e : component.errors())
  //   {
  //     std::cout << e.toString().toStdString() << std::endl;
  //   }
  // }

  int ret = app.exec();
  return ret;
}