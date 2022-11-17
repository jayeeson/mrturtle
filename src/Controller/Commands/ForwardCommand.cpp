#include "ForwardCommand.h"
#include "Turtle.h"
#include "Math.h"

ForwardCommand::ForwardCommand(Turtle &turtle, double value) : _turtle(turtle), _value(value) {}

bool ForwardCommand::Execute()
{
    if (IsValid())
    {
        if (_turtle.GetCanvas().IsPenDown())
        {
            const auto pos = _turtle.GetPosition();
            const auto heading = _turtle.GetHeading();
            const auto pathList = _turtle.GetCanvas().GetTurtlePath(pos, heading, _value);

            _turtle.GetCanvas().DoDrawPaths(pathList);
        }

        _turtle.Forward(_value);
        return true;
    }
    return false;
}

bool ForwardCommand::InstaExecution() { return false; }

bool ForwardCommand::IsValid() { return !Math::IsEqual(_value, 0.0); }