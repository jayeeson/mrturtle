#pragma once

#include "AbstractCommand.h"

class Turtle;

class PositionCommand : public AbstractCommand
{
   public:
    PositionCommand(Turtle &turtle);

    bool Execute() override;

   private:
    Turtle &_turtle;
};
