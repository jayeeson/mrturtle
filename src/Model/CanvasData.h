#pragma once

#include "PenColor.h"
#include <QObject>
#include <QPointF>
#include <QLine>
#include <QList>
#include <QSize>
#include <QString>
#include <QVariantList>
#include <iostream>
#include <cmath>

class CanvasData : public QObject
{
    Q_OBJECT

   public:
    Q_PROPERTY(QSize cppCanvasSize READ GetCanvasSize WRITE SetCanvasSize NOTIFY CanvasSizeChanged)
    Q_PROPERTY(QSize cppOrigCanvasSize READ GetOriginalCanvasSize WRITE SetOriginalCanvasSize NOTIFY
                   OriginalCanvasSizeChanged)
    Q_PROPERTY(QSize cppMaxCanvasSize READ GetMaxCanvasSize WRITE SetMaxCanvasSize NOTIFY
                   MaxCanvasSizeChanged)
    CanvasData(){};

    inline QSize GetCanvasSize();
    inline QSize GetOriginalCanvasSize();
    inline QSize GetMaxCanvasSize();
    void SetCanvasSize(const QSize &size);
    void SetOriginalCanvasSize(const QSize &size);
    void SetMaxCanvasSize(const QSize &size);

    QList<QLineF> GetTurtlePath(const QPointF &pos, double heading, double distance);

    void DoAddLineToCommandHistoryPanel(QString line, QString color = "");
    void DoDrawPaths(const QList<QLineF> &pathList);
    void DoClearCanvas();

    QPointF tl();
    QPointF tr(const QSize &canvas);
    QPointF bl(const QSize &canvas);
    QPointF br(const QSize &canvas);

   signals:
    void CanvasSizeChanged();
    void OriginalCanvasSizeChanged();
    void MaxCanvasSizeChanged();
    void addLineToCommandHistoryPanel(QString line, QString color = "");
    void drawPaths(QList<int> x1, QList<int> y1, QList<int> x2, QList<int> y2);
    void clearCanvas();

   private:
    void UpdateMaxCanvasSizeIfNeeded();
    void GetCanvasBordersThatCouldIntersect(double heading, QLineF &edge1, QLineF &edge2);

   private:
    QSize _canvasSize;
    QSize _origCanvasSize;
    QSize _maxCanvasSize;
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

inline QSize CanvasData::GetCanvasSize() { return _canvasSize; }

inline QSize CanvasData::GetOriginalCanvasSize() { return _origCanvasSize; }

inline QSize CanvasData::GetMaxCanvasSize() { return _maxCanvasSize; }