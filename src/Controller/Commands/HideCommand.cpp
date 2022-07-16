#include "HideCommand.h"
#include "Turtle.h"

HideCommand::HideCommand(Turtle &turtle) : _turtle(turtle) {}

void HideCommand::Execute() { _turtle.SetVisible(false); }