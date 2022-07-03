#pragma once

#include "PenColor.h"
#include <QObject>
#include <QPointF>
#include <QSize>
#include <iostream>
#include <cmath>

class Turtle : public QObject
{
  Q_OBJECT
  Q_PROPERTY(QPointF position READ GetPosition NOTIFY PositionChanged)
  Q_PROPERTY(double heading READ GetHeadingDeg NOTIFY HeadingChanged)
  Q_PROPERTY(QSize canvasSize READ GetCanvasSize WRITE SetCanvasSize NOTIFY CanvasSizeChanged)

public:
  Turtle();

  void Forward(double distance, bool backward = false);
  void Backward(double distance);
  // CCW is +, CW is -
  void RotateRad(double angle);
  void RotateDeg(double angle);
  void SetHeading(double angle);

  inline void PenDown(bool down);
  inline void SetVisible(bool visible);
  inline void SetPosition(QPointF position);

  inline QPointF GetPosition();
  inline double GetHeading();
  inline double GetHeadingDeg();
  inline bool IsVisible();
  inline bool IsPenDown();

  inline QSize GetCanvasSize();
  void SetCanvasSize(const QSize &size);

signals:
  void PositionChanged();
  void HeadingChanged();
  void CanvasSizeChanged();

  // helpers
private:
  double ClampAngleToUnitCircle(double angle);

private:
  double _heading; // value in radians
  QPointF _position;
  bool _penDown;
  PenColor _penColor;
  double _penSize;
  QSize _canvasSize;
  bool _visible;
};

inline void Turtle::PenDown(bool down)
{
  _penDown = down;
}

inline void Turtle::SetVisible(bool visible)
{
  _visible = visible;
}

inline void Turtle::SetPosition(QPointF position)
{
  if (abs(position.x() * 2) > _canvasSize.width() || abs(position.y() * 2) > _canvasSize.height())
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
  return _position;
}

inline double Turtle::GetHeading()
{
  return _heading;
}

inline double Turtle::GetHeadingDeg()
{
  return _heading * 180 / M_PI;
}

inline bool Turtle::IsVisible()
{
  return _visible;
}

inline bool Turtle::IsPenDown()
{
  return _penDown;
}

inline QSize Turtle::GetCanvasSize()
{
  return _canvasSize;
}