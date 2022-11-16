#pragma once

#include "AbstractCommand.h"

class Turtle;

class LeftCommand : public AbstractCommand
{
   public:
    LeftCommand(Turtle &turtle, double deg);

    void Execute() override;
    virtual bool InstaExecution() override;

   private:
    double _deg;
    Turtle &_turtle;
};
