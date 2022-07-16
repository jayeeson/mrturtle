#pragma once

#include "AbstractCommand.h"

class Turtle;

class ShowCommand : public AbstractCommand
{
   public:
    ShowCommand(Turtle &turtle);

    void Execute() override;

   private:
    Turtle &_turtle;
};
