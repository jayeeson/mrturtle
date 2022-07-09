#include "Turtle.h"
#include <cmath>
#include <iostream>

Turtle::Turtle(CanvasData &canvas)
    : _heading(M_PI / 2.),
      _position(0, 0),
      _penDown(true),
      _penColor(PenColor::black),
      _penSize(3),
      _canvas(canvas),
      _visible(true)
{
}

void Turtle::Forward(double distance, bool backward)
{
  const double backardModifier = backward ? M_PI : 0;
  const double newX = _position.x() + distance * cos(backardModifier + _heading) + _canvas.GetOriginalCanvasSize().width() / 2;
  const double newY = _position.y() + distance * sin(backardModifier + _heading) + _canvas.GetOriginalCanvasSize().height() / 2;
  const int negativeXModifier = newX < 0 ? -1 : 1;
  const int negativeYModifier = newY < 0 ? -1 : 1;

  _position.setX(negativeXModifier * newX -
                 floor(newX / _canvas.GetCanvasSize().width()) * _canvas.GetCanvasSize().width() - _canvas.GetOriginalCanvasSize().width() / 2);
  _position.setY(negativeYModifier * newY -
                 floor(newY / _canvas.GetCanvasSize().height()) * _canvas.GetCanvasSize().height() - _canvas.GetOriginalCanvasSize().height() / 2);

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
  emit HeadingChanged();
}

void Turtle::RotateDeg(double angle)
{
  RotateRad(angle * M_PI / 180);
}

void Turtle::SetHeading(double angle)
{
  double newHeading = angle;
  _heading = ClampAngleToUnitCircle(newHeading);
  emit HeadingChanged();
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
