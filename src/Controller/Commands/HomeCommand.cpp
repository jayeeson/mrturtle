#include "HomeCommand.h"
#include "Turtle.h"
#include <cmath>

HomeCommand::HomeCommand(Turtle &turtle) : _turtle(turtle) {}

void HomeCommand::Execute()
{
    if (_turtle.GetCanvas().IsPenDown())
    {
        const auto pos = _turtle.GetPosition();
        const auto heading = _turtle.GetHeading();
        const auto pathList = _turtle.GetCanvas().GetTurtlePath(
            pos, atan2(pos.y(), pos.x()) + M_PI, sqrt(pos.x() * pos.x() + pos.y() * pos.y()));

        _turtle.GetCanvas().DoDrawPaths(pathList);
    }

    _turtle.SetPosition(QPoint(0, 0));
    _turtle.SetHeading(M_PI / 2);
}

bool HomeCommand::InstaExecution() { return false; }