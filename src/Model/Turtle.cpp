#include "Turtle.h"
#include "Size.h"
#include <cmath>
#include <iostream>

Turtle::Turtle(Size<int> &canvasSize)
    : _heading(M_PI / 2.),
      _position(0, 0),
      _penDown(true),
      _penColor(PenColor::black),
      _penSize(3),
      _canvasSize(canvasSize),
      _visible(true)
{
}

void Turtle::Forward(double distance, bool backward)
{
  double backwardModifier = backward ? M_PI : 0;
  _position.setX(_position.x() + fmod(distance * cos(backwardModifier + _heading), static_cast<double>(_canvasSize.width())));
  _position.setY(_position.y() + fmod(distance * sin(backwardModifier + _heading), static_cast<double>(_canvasSize.height())));
  emit PositionChanged();
}

void Turtle::Backward(double distance)
{
  Forward(distance, true);
}

void Turtle::RotateRad(double angle)
{
  _heading += angle;
  _heading = ClampAngleToUnitCircle(_heading);
}

void Turtle::RotateDeg(double angle)
{
  RotateRad(angle * M_PI / 180);
}

void Turtle::SetHeading(double angle)
{
  double newHeading = angle;
  _heading = ClampAngleToUnitCircle(newHeading);
}

double Turtle::ClampAngleToUnitCircle(double angle)
{
  if (abs(angle) >= 2 * M_PI)
  {
    angle = fmod(angle, 2 * M_PI);
  }
  if (angle < 0)
  {
    angle = 2 * M_PI + angle;
  }
  return angle;
}