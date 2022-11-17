#pragma once

#include "AbstractCommand.h"

class Turtle;

class LeftCommand : public AbstractCommand
{
   public:
    LeftCommand(Turtle &turtle, double deg);

    bool Execute() override;
    virtual bool InstaExecution() override;

    bool IsValid();

   private:
    double _deg;
    Turtle &_turtle;
};
