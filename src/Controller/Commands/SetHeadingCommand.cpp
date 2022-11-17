#include "SetHeadingCommand.h"
#include "Turtle.h"
#include "Math.h"

SetHeadingCommand::SetHeadingCommand(Turtle &turtle, double headingDeg)
    : _turtle(turtle), _heading(-headingDeg + 90)
{
}

bool SetHeadingCommand::Execute()
{
    if (IsValid())
    {
        _turtle.SetHeading(Math::DegToRad(_heading));
        return true;
    }
    return false;
}

bool SetHeadingCommand::IsValid()
{
    double currentHeading = Math::RadToDeg(_turtle.GetHeading());
    return !Math::IsEqual(_heading, currentHeading);
}