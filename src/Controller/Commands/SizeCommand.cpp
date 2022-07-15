#include "SizeCommand.h"
#include "CanvasData.h"
#include <QObject>
#include <QMetaObject>
#include <QString>

SizeCommand::SizeCommand(CanvasData &canvas) : _canvas(canvas) {}

void SizeCommand::Execute()
{
    QSizeF size = _canvas.GetCanvasSize();
    QString str =
        "size (" + QString::number(size.width()) + "," + QString::number(size.height()) + ")";
    _canvas.DoAddLineToCommandHistoryPanel(str, "blue");
}