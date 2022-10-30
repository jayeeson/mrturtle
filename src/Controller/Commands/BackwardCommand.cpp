#include "BackwardCommand.h"

#include "Turtle.h"

BackwardCommand::BackwardCommand(Turtle &turtle, double value) : _turtle(turtle), _value(value) {}

void BackwardCommand::Execute()
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
}

bool BackwardCommand::InstaExecution() { return false; }