#include "PositionCommand.h"
#include "Turtle.h"
#include "Math.h"
#include <QObject>
#include <QMetaObject>
#include <QString>
#include <QPoint>

static int DECIMAL_PRECISION{3};

PositionCommand::PositionCommand(Turtle &turtle) : _turtle(turtle) {}

bool PositionCommand::Execute()
{
    QPointF pos = _turtle.GetPosition();

    QString line = "position (" + QString::number(Math::SetPrecision(pos.x(), DECIMAL_PRECISION)) +
                   "," + QString::number(Math::SetPrecision(pos.y(), DECIMAL_PRECISION)) + ")";

    _turtle.GetCanvas().DoAddLineToCommandHistoryPanel(line, "blue");
    return true;
}