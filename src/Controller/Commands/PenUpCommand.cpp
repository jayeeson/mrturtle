#include "PenUpCommand.h"
#include "Turtle.h"

PenUpCommand::PenUpCommand(Turtle &turtle) : _turtle(turtle) {}

bool PenUpCommand::Execute()
{
    _turtle.GetCanvas().SetPenDown(false);
    return true;
}