#pragma once

#include "AbstractCommand.h"

class Turtle;

class HomeCommand : public AbstractCommand
{
   public:
    HomeCommand(Turtle &turtle);

    bool Execute() override;
    virtual bool InstaExecution() override;

    bool IsValid();

   private:
    Turtle &_turtle;
};
