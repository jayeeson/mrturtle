#include "RightCommand.h"
#include "Turtle.h"
#include "Math.h"

RightCommand::RightCommand(Turtle &turtle, double deg) : _turtle(turtle), _deg(deg) {}

bool RightCommand::Execute()
{
    if (IsValid())
    {
        _turtle.RotateDeg(_deg);
        return true;
    }
    return false;
}

bool RightCommand::InstaExecution() { return false; }

bool RightCommand::IsValid() { return !Math::IsEqual(_deg, 0.0); }