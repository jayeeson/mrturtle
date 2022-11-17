#include "PenDownCommand.h"
#include "Turtle.h"

PenDownCommand::PenDownCommand(Turtle &turtle) : _turtle(turtle) {}

bool PenDownCommand::Execute()
{
    _turtle.GetCanvas().SetPenDown(true);
    return true;
}