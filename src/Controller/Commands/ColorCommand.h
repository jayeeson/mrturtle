#pragma once

#include "AbstractCommand.h"
#include <QString>

class Turtle;

class ColorCommand : public AbstractCommand
{
   public:
    ColorCommand(Turtle &turtle, QString color);

    bool Execute() override;

   private:
    Turtle &_turtle;
    QString _color;
};
