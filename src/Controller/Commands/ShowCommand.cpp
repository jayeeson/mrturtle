#include "ShowCommand.h"
#include "Turtle.h"

ShowCommand::ShowCommand(Turtle &turtle) : _turtle(turtle) {}

void ShowCommand::Execute() { _turtle.SetVisible(true); }