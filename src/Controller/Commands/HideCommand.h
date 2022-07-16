#pragma once

#include "AbstractCommand.h"

class Turtle;

class HideCommand : public AbstractCommand
{
   public:
    HideCommand(Turtle &turtle);

    void Execute() override;

   private:
    Turtle &_turtle;
};
