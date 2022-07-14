#pragma once

#include "CanvasData.h"
#include <QObject>
#include <QPointF>
#include <iostream>

class Turtle : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QPointF position READ GetPosition NOTIFY PositionChanged)
    Q_PROPERTY(double heading READ GetHeadingDeg NOTIFY HeadingChanged)

   public:
    Turtle(CanvasData &canvas);

    void Forward(double distance, bool backward = false);
    void Backward(double distance);
    // CCW is +, CW is -
    void RotateRad(double angle);
    void RotateDeg(double angle);
    void SetHeading(double angle);

    inline void SetVisible(bool visible);
    inline void SetPosition(const QPointF &position);

    inline QPointF GetPosition();
    inline double GetHeading();
    inline double GetHeadingDeg();
    inline bool IsVisible();
    inline bool IsPenDown();

    inline CanvasData &GetCanvas();

    static double ClampAngleToUnitCircle(double angle);

   signals:
    void PositionChanged();
    void HeadingChanged();

   private:
    double _heading;  // value in radians
    QPointF _position;
    bool _visible;

    CanvasData &_canvas;
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

inline void Turtle::SetVisible(bool visible) { _visible = visible; }

inline void Turtle::SetPosition(const QPointF &position)
{
    if (abs(position.x() * 2) > _canvas.GetCanvasSize().width() ||
        abs(position.y() * 2) > _canvas.GetCanvasSize().height())
    {
        // todo: log error
        std::cout << "error setting turtle position";
        return;
    }
    _position = position;
    emit PositionChanged();
}

inline QPointF Turtle::GetPosition()
{
    // std::cout << "position:" << QString::number(_position.x()).toStdString() << "," <<
    // QString::number(_position.y()).toStdString() << std::endl;
    return _position;
}

inline double Turtle::GetHeading() { return _heading; }

inline double Turtle::GetHeadingDeg() { return _heading * 180 / M_PI; }

inline bool Turtle::IsVisible() { return _visible; }

inline CanvasData &Turtle::GetCanvas() { return _canvas; }