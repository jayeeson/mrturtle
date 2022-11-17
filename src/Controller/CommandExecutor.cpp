#include "CommandExecutor.h"

CommandExecutor::CommandExecutor(Turtle &turtle) : _man(turtle, *this)
{
    QObject::connect(this, &CommandExecutor::NotifyRunStopped,
                     &CommandExecutor::onNotifyRunStopped);
}

void CommandExecutor::Enqueue(QString command)
{
    _logicMutex.lock();
    if (!_running)
    {
        _running = true;
        _logicMutex.unlock();
        bool takesTime = _man.Parse(command.toStdString());
        _man.Execute();
        if (!takesTime)
        {
            emit NotifyRunStopped();
        }
    }
    else
    {
        _queue.push_back(command.toStdString());
        _logicMutex.unlock();
    }
}

void CommandExecutor::onNotifyRunStopped()
{
    _logicMutex.lock();
    if (_queue.empty())
    {
        _running = false;
        _logicMutex.unlock();
    }
    else
    {
        auto nextCommand = _queue.front();
        _queue.pop_front();
        _logicMutex.unlock();
        bool takesTime = _man.Parse(nextCommand);
        _man.Execute();
        if (!takesTime)
        {
            emit NotifyRunStopped();
        }
    }
}