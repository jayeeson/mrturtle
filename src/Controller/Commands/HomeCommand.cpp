#include "HomeCommand.h"
#include "Turtle.h"
#include "Math.h"
#include <cmath>

HomeCommand::HomeCommand(Turtle &turtle) : _turtle(turtle) {}

bool HomeCommand::Execute()
{
    if (IsValid())
    {
        if (_turtle.GetCanvas().IsPenDown())
        {
            const auto pos = _turtle.GetPosition();
            const auto heading = _turtle.GetHeading();
            const auto pathList = _turtle.GetCanvas().GetTurtlePath(
                pos, atan2(pos.y(), pos.x()) + M_PI, sqrt(pos.x() * pos.x() + pos.y() * pos.y()));

            _turtle.GetCanvas().DoDrawPaths(pathList);
        }
        // todo: 1) set heading to origin, 2) set positioin to origin, 3) set heading to default.
        // will look cooler in the animations...
        _turtle.SetPosition(QPoint(0, 0));
        _turtle.SetHeading(M_PI / 2);
        return true;
    }
    return false;
}

bool HomeCommand::InstaExecution() { return false; }

bool HomeCommand::IsValid()
{
    return !Math::IsEqual(Math::RadToDeg(_turtle.GetHeading()), M_PI / 2) &&
           !Math::IsEqual(_turtle.GetPosition().x(), 0.0) &&
           !Math::IsEqual(_turtle.GetPosition().y(), 0.0);
}