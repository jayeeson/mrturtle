#include "PositionCommand.h"

#include <QMetaObject>
#include <QObject>
#include <QString>
#include <iostream>

#include "CanvasData.h"
#include "Turtle.h"

PositionCommand::PositionCommand(Turtle &turtle, CanvasData &canvas)
    : _turtle(turtle), _canvas(canvas)
{
}

void PositionCommand::Execute()
{
    QPointF pos = _turtle.GetPosition();
    QString line = "position (" + QString::number(pos.x()) + "," + QString::number(pos.y()) + ")";
    _canvas.DoAddLineToCommandHistoryPanel(line, "blue");
}