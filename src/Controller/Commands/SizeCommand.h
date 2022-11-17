#pragma once

#include "AbstractCommand.h"
#include <QPointF>

class CanvasData;

class SizeCommand : public AbstractCommand
{
   public:
    SizeCommand(CanvasData &canvas);

    bool Execute() override;

   private:
    CanvasData &_canvas;
};
