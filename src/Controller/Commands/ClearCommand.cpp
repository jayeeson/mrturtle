#include "ClearCommand.h"
#include "CanvasData.h"

ClearCommand::ClearCommand(CanvasData &canvas) : _canvas(canvas) {}

void ClearCommand::Execute() { _canvas.DoClearCanvas(); }