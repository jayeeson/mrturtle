#pragma once

#include "AbstractCommand.h"
#include <QString>
#include <string>
#include <memory>

class Turtle;
class CommandExecutor;

class CommandInterpreter
{
   public:
    CommandInterpreter(Turtle &turtle, CommandExecutor &executor);
    CommandInterpreter() = delete;
    CommandInterpreter(const CommandInterpreter &) = delete;
    CommandInterpreter &operator=(CommandInterpreter &) = delete;
    virtual ~CommandInterpreter() = default;

    // returns true if it takes time to draw
    bool Parse(std::string command);
    bool Execute();

    void HandleInvalidCommand();

   private:
    std::unique_ptr<AbstractCommand> _cmd;
    Turtle &_turtle;
    CommandExecutor &_executor;
};