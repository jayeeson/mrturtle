#include "RightCommand.h"
#include "Turtle.h"

RightCommand::RightCommand(Turtle &turtle, double deg)
    : _turtle(turtle),
      _deg(deg)
{
}

void RightCommand::Execute()
{
  _turtle.RotateDeg(-_deg);
}