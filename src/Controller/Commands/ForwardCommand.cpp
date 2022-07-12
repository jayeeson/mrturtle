#include "ForwardCommand.h"

#include "Turtle.h"

ForwardCommand::ForwardCommand(Turtle &turtle, double value) : _turtle(turtle), _value(value) {}

void ForwardCommand::Execute() { _turtle.Forward(_value); }