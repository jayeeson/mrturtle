#pragma once

#include "AbstractCommand.h"

class Turtle;

class PenSizeCommand : public AbstractCommand
{
   public:
    PenSizeCommand(Turtle &turtle, double size);

    void Execute() override;

   private:
    Turtle &_turtle;
    double _size;
};
