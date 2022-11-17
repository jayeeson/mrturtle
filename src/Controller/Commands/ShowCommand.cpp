#include "ShowCommand.h"
#include "Turtle.h"

ShowCommand::ShowCommand(Turtle &turtle) : _turtle(turtle) {}

bool ShowCommand::Execute()
{
    _turtle.SetVisible(true);
    return true;
}