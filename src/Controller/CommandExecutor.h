#pragma once

#include "Turtle.h"
#include "CommandInterpreter.h"
#include <QObject>
#include <QString>
#include <string>
#include <deque>
#include <mutex>

class CommandExecutor : public QObject
{
    Q_OBJECT

   public:
    CommandExecutor() = delete;
    CommandExecutor(Turtle &turtle);
    CommandExecutor(CommandExecutor &) = delete;
    CommandExecutor operator=(CommandExecutor &) = delete;
    virtual ~CommandExecutor() = default;

    Q_INVOKABLE void Enqueue(QString command);

   public slots:
    void onNotifyRunStopped();

   signals:
    void NotifyRunStopped();

   private:
    CommandInterpreter _man;
    std::deque<std::string> _queue;
    bool _running;
    std::mutex _logicMutex;
};
