#include "UnknownCommand.h"
#include "CanvasData.h"
#include <QObject>
#include <QMetaObject>

UnknownCommand::UnknownCommand(CanvasData &canvas, QString input) : _canvas(canvas), _input(input)
{
}

void UnknownCommand::Execute()
{
    QString str = "Unknown command: " + _input;
    _canvas.DoAddLineToCommandHistoryPanel(str, "darkred");
}