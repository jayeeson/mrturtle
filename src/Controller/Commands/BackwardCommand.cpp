#include "BackwardCommand.h"
#include "Turtle.h"
#include "Math.h"

BackwardCommand::BackwardCommand(Turtle &turtle, double value) : _turtle(turtle), _value(value) {}

bool BackwardCommand::Execute()
{
    if (IsValid())
    {
        if (_turtle.GetCanvas().IsPenDown())
        {
            const auto pos = _turtle.GetPosition();
            const auto heading = _turtle.GetHeading();
            const auto pathList = _turtle.GetCanvas().GetTurtlePath(
                pos, _turtle.ClampAngleToUnitCircle(heading + M_PI), _value);

            _turtle.GetCanvas().DoDrawPaths(pathList);
        }
        _turtle.Backward(_value);
        return true;
    }
    return false;
}

bool BackwardCommand::InstaExecution() { return false; }

bool BackwardCommand::IsValid() { return !Math::IsEqual(_value, 0.0); }