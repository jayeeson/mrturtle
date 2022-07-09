#pragma once

#include "AbstractCommand.h"
#include <QPointF>

class Turtle;
class CanvasData;

class PositionCommand : public AbstractCommand
{
public:
  PositionCommand(Turtle &turtle, CanvasData &canvas);

  void Execute() override;

private:
  Turtle &_turtle;
  CanvasData &_canvas;
};
