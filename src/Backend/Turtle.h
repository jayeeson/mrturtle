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

  void PenDown(bool down);

  inline Point GetPosition();
  inline double GetHeading();

private:
  double _heading; // value in radians
  Point _position;
  bool _penDown;
  PenColor _penColor;
  double _penSize;
  Size<int> &_canvasSize;
};

inline Point Turtle::GetPosition()
{
  return _position;
}

inline double Turtle::GetHeading()
{
  return _heading;
}