#include "BackwardCommand.h"

#include "Turtle.h"

BackwardCommand::BackwardCommand(Turtle &turtle, double value) : _turtle(turtle), _value(value) {}

void BackwardCommand::Execute() { _turtle.Backward(_value); }