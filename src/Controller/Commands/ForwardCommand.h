#pragma once

#include "AbstractCommand.h"

class Turtle;

class ForwardCommand : public AbstractCommand
{
   public:
    ForwardCommand(Turtle &turtle, double value);

    void Execute() override;

   private:
    double _value;
    Turtle &_turtle;
};
