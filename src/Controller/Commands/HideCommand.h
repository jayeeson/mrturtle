#pragma once

#include "AbstractCommand.h"

class Turtle;

class HideCommand : public AbstractCommand
{
   public:
    HideCommand(Turtle &turtle);

    bool Execute() override;

   private:
    Turtle &_turtle;
};
