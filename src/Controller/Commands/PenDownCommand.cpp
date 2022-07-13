#include "PenDownCommand.h"
#include "Turtle.h"

PenDownCommand::PenDownCommand(Turtle &turtle) : _turtle(turtle) {}

void PenDownCommand::Execute() { _turtle.PenDown(true); }