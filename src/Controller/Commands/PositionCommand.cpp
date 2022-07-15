#include "PositionCommand.h"
#include "Turtle.h"
#include <QObject>
#include <QMetaObject>
#include <QString>

PositionCommand::PositionCommand(Turtle &turtle) : _turtle(turtle) {}

void PositionCommand::Execute()
{
    QPointF pos = _turtle.GetPosition();
    QString line = "position (" + QString::number(pos.x()) + "," + QString::number(pos.y()) + ")";
    _turtle.GetCanvas().DoAddLineToCommandHistoryPanel(line, "blue");
}