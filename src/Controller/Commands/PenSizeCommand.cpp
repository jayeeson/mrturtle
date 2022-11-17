#include "PenSizeCommand.h"
#include "Turtle.h"

PenSizeCommand::PenSizeCommand(Turtle &turtle, double size) : _turtle(turtle), _size(size) {}

bool PenSizeCommand::Execute()
{
    _turtle.GetCanvas().SetPenSize(_size);
    return true;
}