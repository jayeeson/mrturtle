#include "PenUpCommand.h"
#include "Turtle.h"

PenUpCommand::PenUpCommand(Turtle &turtle) : _turtle(turtle) {}

void PenUpCommand::Execute() { _turtle.PenDown(false); }