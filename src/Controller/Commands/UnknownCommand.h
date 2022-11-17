#pragma once

#include "AbstractCommand.h"
#include <string>

class CanvasData;

class UnknownCommand : public AbstractCommand
{
   public:
    UnknownCommand(CanvasData &canvas, std::string input);

    bool Execute() override;

   private:
    CanvasData &_canvas;
    std::string _input;
};
