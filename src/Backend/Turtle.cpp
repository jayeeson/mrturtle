#include "Turtle.h"
#include "Size.h"
#include <cmath>
#include <iostream>

Turtle::Turtle(Size<int> &canvasSize)
    : _heading(M_PI / 2.),
      _position(canvasSize.width() / 2., canvasSize.height() / 2.),
      _penDown(true),
      _penColor(PenColor::black),
      _penSize(3),
      _canvasSize(canvasSize)
{
}

void Turtle::Forward(double distance, bool backward)
{
  double backwardModifier = backward ? M_PI : 0;
  _position.x = _position.x + fmod(distance * cos(backwardModifier + _heading), static_cast<double>(_canvasSize.width()));
  _position.y = _position.y + fmod(distance * sin(backwardModifier + _heading), static_cast<double>(_canvasSize.height()));
}

void Turtle::Backward(double distance)
{
  Forward(distance, true);
}

void Turtle::RotateRad(double angle)
{
  _heading += angle;
  if (_heading < 0)
  {
    _heading = 2 * M_PI + _heading;
  }
  if (_heading >= 2 * M_PI)
  {
    _heading = fmod(_heading, 2 * M_PI);
  }
}

void Turtle::RotateDeg(double angle)
{
  RotateRad(angle * M_PI / 180);
}

void Turtle::PenDown(bool down)
{
  _penDown = down;
}