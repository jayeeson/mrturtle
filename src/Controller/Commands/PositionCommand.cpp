#include "PositionCommand.h"
#include "Turtle.h"
#include "CanvasData.h"
#include <QObject>
#include <QMetaObject>
#include <QString>
#include <iostream>

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