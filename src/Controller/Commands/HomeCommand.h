#pragma once

#include "AbstractCommand.h"

class Turtle;

class HomeCommand : public AbstractCommand
{
   public:
    HomeCommand(Turtle &turtle);

    void Execute() override;
    virtual bool InstaExecution() override;

   private:
    Turtle &_turtle;
};
