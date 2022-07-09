#pragma once

#include "AbstractCommand.h"

class Turtle;

class LeftCommand : public AbstractCommand
{
public:
  LeftCommand(Turtle &turtle, double deg);

  void Execute() override;

private:
  double _deg;
  Turtle &_turtle;
};
