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

double CanvasData::GetHalfWidthDiff()
{
  const double diff = _canvasSize.width() - _origCanvasSize.width();
  return diff / 2;
}

double CanvasData::GetHalfHeightDiff()
{
  const double diff = _canvasSize.height() - _origCanvasSize.height();
  return diff / 2;
}

void CanvasData::DrawTurtlePath(QPointF pos, double heading, double distance)
{
}