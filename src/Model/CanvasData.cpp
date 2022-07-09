#include "CanvasData.h"

void CanvasData::SetCanvasSize(const QSize &size)
{
  _canvasSize = size;
  emit CanvasSizeChanged();
}

void CanvasData::SetOriginalCanvasSize(const QSize &size)
{
  _origCanvasSize = size;
  emit OriginalCanvasSizeChanged();
}

void CanvasData::DoAddLineToCommandHistoryPanel(QString line, QString color)
{
  emit addLineToCommandHistoryPanel(line, color);
}