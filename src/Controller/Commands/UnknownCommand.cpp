#include "UnknownCommand.h"
#include "CanvasData.h"
#include <QObject>
#include <QMetaObject>

UnknownCommand::UnknownCommand(CanvasData &canvas, std::string input)
    : _canvas(canvas), _input(input)
{
}

void UnknownCommand::Execute()
{
    QString str = "Unknown command: " + QString{_input.c_str()};
    _canvas.DoAddLineToCommandHistoryPanel(str, "darkred");
}