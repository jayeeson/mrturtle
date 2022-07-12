#pragma once

#include "AbstractCommand.h"

class Turtle;

class RightCommand : public AbstractCommand
{
   public:
    RightCommand(Turtle &turtle, double deg);

    void Execute() override;

   private:
    double _deg;
    Turtle &_turtle;
};
