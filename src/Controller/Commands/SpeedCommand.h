#pragma once

#include "AbstractCommand.h"
#include <QPointF>

class Turtle;

class SpeedCommand : public AbstractCommand
{
   public:
    SpeedCommand(Turtle &turtle, double speed);
    SpeedCommand(Turtle &turtle);

    bool Execute() override;
    bool Validate();

   private:
    Turtle &_turtle;
    double _speed;
    bool _gettingSpeed;
};
