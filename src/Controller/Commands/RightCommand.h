#pragma once

#include "AbstractCommand.h"

class Turtle;

class RightCommand : public AbstractCommand
{
   public:
    RightCommand(Turtle &turtle, double deg);

    bool Execute() override;
    virtual bool InstaExecution() override;

    bool IsValid();

   private:
    double _deg;
    Turtle &_turtle;
};
