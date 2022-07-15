#pragma once

#include "AbstractCommand.h"
#include <QPointF>
#include <QString>

class CanvasData;

class UnknownCommand : public AbstractCommand
{
   public:
    UnknownCommand(CanvasData &canvas, QString input);

    void Execute() override;

   private:
    CanvasData &_canvas;
    QString _input;
};
