#pragma once

#include "AbstractCommand.h"

class CanvasData;

class ClearCommand : public AbstractCommand
{
   public:
    ClearCommand(CanvasData &canvas);

    void Execute() override;

   private:
    CanvasData &_canvas;
};
