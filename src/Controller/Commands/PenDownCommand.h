#pragma once

#include "AbstractCommand.h"

class Turtle;

class PenDownCommand : public AbstractCommand
{
   public:
    PenDownCommand(Turtle &turtle);

    bool Execute() override;

   private:
    Turtle &_turtle;
};
