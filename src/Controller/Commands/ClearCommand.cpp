#include "ClearCommand.h"
#include "CanvasData.h"

ClearCommand::ClearCommand(CanvasData &canvas) : _canvas(canvas) {}

bool ClearCommand::Execute()
{
    _canvas.DoClearCanvas();
    return true;
}