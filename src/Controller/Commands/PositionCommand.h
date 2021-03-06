#pragma once

#include "AbstractCommand.h"
#include <QPointF>

class Turtle;

class PositionCommand : public AbstractCommand
{
   public:
    PositionCommand(Turtle &turtle);

    void Execute() override;

   private:
    Turtle &_turtle;
};
