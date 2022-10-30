#include "ForwardCommand.h"

#include "Turtle.h"

ForwardCommand::ForwardCommand(Turtle &turtle, double value) : _turtle(turtle), _value(value) {}

void ForwardCommand::Execute()
{
    if (_turtle.GetCanvas().IsPenDown())
    {
        const auto pos = _turtle.GetPosition();
        const auto heading = _turtle.GetHeading();
        const auto pathList = _turtle.GetCanvas().GetTurtlePath(pos, heading, _value);

        _turtle.GetCanvas().DoDrawPaths(pathList);
    }

    _turtle.Forward(_value);
}

bool ForwardCommand::InstaExecution() { return false; }