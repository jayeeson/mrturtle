#pragma once

#include "AbstractCommand.h"
#include <QObject>
#include <QString>
#include <string>
#include <memory>

class Turtle;

class CommandInterpreter : public QObject
{
    Q_OBJECT

   public:
    CommandInterpreter() = delete;
    CommandInterpreter(Turtle &turtle);

    Q_INVOKABLE void Parse(QString command);
    Q_INVOKABLE bool Execute();

   signals:
    void AddLineToCommandLog(QString str);

   private:
    std::unique_ptr<AbstractCommand> _cmd;
    Turtle &_turtle;
    QObject *_mainQml;
};