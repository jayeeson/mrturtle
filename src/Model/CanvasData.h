#pragma once

#include <QObject>
#include <QPointF>
#include <QLine>
#include <QList>
#include <QSize>
#include <QString>
#include <QColor>
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
    Q_PROPERTY(QColor cppPenColor READ GetPenColor NOTIFY PenColorChanged)
    Q_PROPERTY(double cppPenSize READ GetPenSize NOTIFY PenSizeChanged)

    CanvasData();

    inline QSize GetCanvasSize();
    inline QSize GetOriginalCanvasSize();
    inline QSize GetMaxCanvasSize();
    inline bool IsPenDown();
    inline QColor GetPenColor();
    inline double GetPenSize();
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

    inline void SetPenDown(bool down);
    void SetPenColor(const QString &color);
    inline void SetPenSize(double size);

   signals:
    void CanvasSizeChanged();
    void OriginalCanvasSizeChanged();
    void MaxCanvasSizeChanged();
    void PenColorChanged();
    void PenSizeChanged();
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

    bool _penDown;
    QColor _penColor;
    double _penSize;
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

inline QSize CanvasData::GetCanvasSize() { return _canvasSize; }

inline QSize CanvasData::GetOriginalCanvasSize() { return _origCanvasSize; }

inline QSize CanvasData::GetMaxCanvasSize() { return _maxCanvasSize; }

inline bool CanvasData::IsPenDown() { return _penDown; }

inline QColor CanvasData::GetPenColor() { return _penColor; }

inline double CanvasData::GetPenSize() { return _penSize; }

inline void CanvasData::SetPenDown(bool down) { _penDown = down; }

inline void CanvasData::SetPenSize(double size)
{
    if (size > 0)
    {
        _penSize = size;
    }
}