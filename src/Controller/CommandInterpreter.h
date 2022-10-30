#pragma once

#include "AbstractCommand.h"
#include <QString>
#include <string>
#include <memory>

class Turtle;

class CommandInterpreter
{
   public:
    CommandInterpreter() = delete;
    CommandInterpreter(const CommandInterpreter &) = delete;
    CommandInterpreter &operator=(CommandInterpreter &) = delete;
    virtual ~CommandInterpreter() = default;
    CommandInterpreter(Turtle &turtle);

    // returns true if it takes time to draw
    bool Parse(std::string command);
    bool Execute();

   private:
    std::unique_ptr<AbstractCommand> _cmd;
    Turtle &_turtle;
};