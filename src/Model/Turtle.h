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
    Q_PROPERTY(bool visible READ IsVisible NOTIFY VisibleChanged)
    Q_PROPERTY(double speed READ GetSpeed NOTIFY SpeedChanged)
    Q_PROPERTY(double defaultSpeed MEMBER _defaultSpeed NOTIFY DefaultSpeedChanged)

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
    inline void SetSpeed(double speed);

    inline QPointF GetPosition();
    inline double GetHeading();
    inline double GetHeadingDeg();
    inline bool IsVisible();
    inline double GetSpeed();
    inline double GetDefaultSpeed();
    inline bool IsPenDown();

    inline CanvasData &GetCanvas();

   signals:
    void PositionChanged();
    void HeadingChanged();
    void VisibleChanged();
    void SpeedChanged();
    void DefaultSpeedChanged();
    void doRotate(double angle);

   public:
    double _defaultSpeed;

   private:
    double _heading;  // value in radians
    QPointF _position;
    bool _visible;
    double _speed;

    CanvasData &_canvas;
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

inline void Turtle::SetVisible(bool visible)
{
    if (_visible != visible)
    {
        _visible = visible;
    }
    emit VisibleChanged();
}

inline void Turtle::SetPosition(const QPointF &position)
{
    if (abs(position.x() * 2) > _canvas.GetCanvasSize().width() ||
        abs(position.y() * 2) > _canvas.GetCanvasSize().height())
    {
        std::cout << "error setting turtle position";
        return;
    }
    if (_position != position)
    {
        _position = position;
        emit PositionChanged();
    }
}

inline QPointF Turtle::GetPosition() { return _position; }

inline double Turtle::GetHeading() { return _heading; }

inline double Turtle::GetHeadingDeg() { return _heading * 180 / M_PI; }

inline bool Turtle::IsVisible() { return _visible; }

inline double Turtle::GetSpeed() { return _speed; }

inline void Turtle::SetSpeed(double speed)
{
    if (!qFuzzyCompare(_speed, speed))
    {
        _speed = speed;
        emit SpeedChanged();
    }
}

inline CanvasData &Turtle::GetCanvas() { return _canvas; }

inline double Turtle::GetDefaultSpeed() { return _defaultSpeed; }