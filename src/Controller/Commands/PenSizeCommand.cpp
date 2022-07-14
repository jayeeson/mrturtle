#include "PenSizeCommand.h"
#include "Turtle.h"

PenSizeCommand::PenSizeCommand(Turtle &turtle, double size) : _turtle(turtle), _size(size) {}

void PenSizeCommand::Execute() { _turtle.GetCanvas().SetPenSize(_size); }