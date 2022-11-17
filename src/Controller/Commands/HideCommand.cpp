#include "HideCommand.h"
#include "Turtle.h"

HideCommand::HideCommand(Turtle &turtle) : _turtle(turtle) {}

bool HideCommand::Execute()
{
    _turtle.SetVisible(false);
    return true;
}