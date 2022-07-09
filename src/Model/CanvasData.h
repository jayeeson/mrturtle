#pragma once

#include "PenColor.h"
#include <QObject>
#include <QPointF>
#include <QSize>
#include <QString>
#include <iostream>
#include <cmath>

class CanvasData : public QObject
{
  Q_OBJECT
  // Q_PROPERTY(QPointF position READ GetPosition NOTIFY PositionChanged)

public:
  Q_PROPERTY(QSize cppCanvasSize READ GetCanvasSize WRITE SetCanvasSize NOTIFY CanvasSizeChanged)
  Q_PROPERTY(QSize cppOrigCanvasSize READ GetOriginalCanvasSize WRITE SetOriginalCanvasSize NOTIFY OriginalCanvasSizeChanged)
  CanvasData(){};

  inline QSize GetCanvasSize();
  inline QSize GetOriginalCanvasSize();
  void SetCanvasSize(const QSize &size);
  void SetOriginalCanvasSize(const QSize &size);

  void DoAddLineToCommandHistoryPanel(QString line);

signals:
  void CanvasSizeChanged();
  void OriginalCanvasSizeChanged();
  void addLineToCommandHistoryPanel(QString line);

private:
  QSize _canvasSize;
  QSize _origCanvasSize;
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

inline QSize CanvasData::GetCanvasSize()
{
  return _canvasSize;
}

inline QSize CanvasData::GetOriginalCanvasSize()
{
  return _origCanvasSize;
}