#pragma once

#include "AbstractCommand.h"

class Turtle;

class PenUpCommand : public AbstractCommand
{
   public:
    PenUpCommand(Turtle &turtle);

    void Execute() override;

   private:
    Turtle &_turtle;
};
