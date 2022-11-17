#pragma once

#include "AbstractCommand.h"

class Turtle;

class SetHeadingCommand : public AbstractCommand
{
   public:
    SetHeadingCommand(Turtle &turtle, double headingDeg);

    bool Execute() override;
    inline bool InstaExecution() { return false; }

    bool IsValid();

   private:
    Turtle &_turtle;
    double _heading;  // deg
};
