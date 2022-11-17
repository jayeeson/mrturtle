#pragma once

#include "AbstractCommand.h"

class Turtle;

class ShowCommand : public AbstractCommand
{
   public:
    ShowCommand(Turtle &turtle);

    bool Execute() override;

   private:
    Turtle &_turtle;
};
