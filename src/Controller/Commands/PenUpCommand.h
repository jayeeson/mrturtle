#pragma once

#include "AbstractCommand.h"

class Turtle;

class PenUpCommand : public AbstractCommand
{
   public:
    PenUpCommand(Turtle &turtle);

    bool Execute() override;

   private:
    Turtle &_turtle;
};
