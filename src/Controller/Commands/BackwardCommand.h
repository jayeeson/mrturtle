#pragma once

#include "AbstractCommand.h"

class Turtle;

class BackwardCommand : public AbstractCommand
{
   public:
    BackwardCommand(Turtle &turtle, double value);

    void Execute() override;
    virtual bool InstaExecution() override;

   private:
    double _value;
    Turtle &_turtle;
};
