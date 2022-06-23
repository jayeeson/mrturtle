#pragma once

#include "PenColor.h"
#include "Point.h"
#include "Size.h"

class Turtle
{
public:
  Turtle(Size<int> &canvasSize);

  void Forward(double distance, bool backward = false);
  void Backward(double distance);
  void RotateRad(double angle);
  void RotateDeg(double angle);
  void SetHeading(double angle);

  inline void PenDown(bool down);
  inline void SetVisible(bool visible);
  inline void SetPosition(Point position);

  inline Point GetPosition();
  inline double GetHeading();
  inline bool IsVisible();
  inline bool IsPenDown();

  // helpers
private:
  double ClampAngleToUnitCircle(double angle);

private:
  double _heading; // value in radians
  Point _position;
  bool _penDown;
  PenColor _penColor;
  double _penSize;
  Size<int> &_canvasSize;
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

inline void Turtle::SetPosition(Point position)
{
  if (abs(position.x * 2) > _canvasSize.width() || abs(position.y * 2) > _canvasSize.height())
  {
    // todo: log error
    return;
  }
  _position = position;
}

inline Point Turtle::GetPosition()
{
  return _position;
}

inline double Turtle::GetHeading()
{
  return _heading;
}

inline bool Turtle::IsVisible()
{
  return _visible;
}

inline bool Turtle::IsPenDown()
{
  return _penDown;
}