#include "LeftCommand.h"

#include "Turtle.h"
#include "Math.h"

LeftCommand::LeftCommand(Turtle &turtle, double deg) : _turtle(turtle), _deg(deg) {}

bool LeftCommand::Execute()
{
    if (IsValid())
    {
        _turtle.RotateDeg(_deg);
        return true;
    }
    return false;
}

bool LeftCommand::InstaExecution() { return false; }

bool LeftCommand::IsValid() { return !Math::IsEqual(_deg, 0.0); }
