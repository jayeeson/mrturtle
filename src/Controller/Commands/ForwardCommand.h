#pragma once

#include "AbstractCommand.h"

class Turtle;

class ForwardCommand : public AbstractCommand
{
   public:
    ForwardCommand(Turtle &turtle, double value);

    bool Execute() override;
    virtual bool InstaExecution() override;

    bool IsValid();

   private:
    double _value;
    Turtle &_turtle;
};
