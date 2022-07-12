#include "CanvasData.h"

void CanvasData::SetCanvasSize(const QSize &size)
{
    _canvasSize = size;

    UpdateMaxCanvasSizeIfNeeded();
    emit CanvasSizeChanged();
}

void CanvasData::SetOriginalCanvasSize(const QSize &size)
{
    _origCanvasSize = size;
    emit OriginalCanvasSizeChanged();
}

void CanvasData::SetMaxCanvasSize(const QSize &size)
{
    _maxCanvasSize = size;
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

void CanvasData::DrawTurtlePath(QPointF pos, double heading, double distance) {}

void CanvasData::UpdateMaxCanvasSizeIfNeeded()
{
    bool changed = false;
    if (_canvasSize.height() > _maxCanvasSize.height())
    {
        _maxCanvasSize.rheight() = _canvasSize.height();
        changed = true;
    }
    if (_canvasSize.width() > _maxCanvasSize.width())
    {
        _maxCanvasSize.rwidth() = _canvasSize.width();
        changed = true;
    }

    if (changed)
    {
        emit MaxCanvasSizeChanged();
    }
}