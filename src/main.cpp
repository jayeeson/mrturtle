#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuick>
#include "CommandInterpreter.h"
#include "Turtle.h"

int main(int argc, char *argv[])
{
  QGuiApplication app(argc, argv);

  Size<int> s(300, 300);
  Turtle t(s);
  t.SetPosition(QPointF(50, 50));

  QQmlApplicationEngine engine;
  engine.rootContext()->setContextProperty("cppTurtle", &t);
  engine.load("qrc:/main.qml");

  return app.exec();
}