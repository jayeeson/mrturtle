#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQuick>
#include "CommandInterpreter.h"
#include "Turtle.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  QQuickView view;
  view.setSource(QUrl(QStringLiteral("qrc:/main.qml")));
  view.show();
  return app.exec();
}