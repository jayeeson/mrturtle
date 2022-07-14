#include "ColorCommand.h"
#include "Turtle.h"

ColorCommand::ColorCommand(Turtle &turtle, QString color) : _turtle(turtle), _color(color) {}

void ColorCommand::Execute() { _turtle.GetCanvas().SetPenColor(_color); }