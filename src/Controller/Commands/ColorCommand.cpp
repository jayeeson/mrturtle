#include "ColorCommand.h"
#include "Turtle.h"

ColorCommand::ColorCommand(Turtle &turtle, QString color) : _turtle(turtle), _color(color) {}

bool ColorCommand::Execute()
{
    _turtle.GetCanvas().SetPenColor(_color);
    return true;
}