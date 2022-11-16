#include "LeftCommand.h"

#include "Turtle.h"

LeftCommand::LeftCommand(Turtle &turtle, double deg) : _turtle(turtle), _deg(deg) {}

void LeftCommand::Execute() { _turtle.RotateDeg(_deg); }

bool LeftCommand::InstaExecution() { return false; }
