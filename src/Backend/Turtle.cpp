#include "Turtle.h"
#include "Size.h"
#include <cmath>

Turtle::Turtle(Size<int> &canvasSize)
    : _heading(M_PI / 2),
      _position(canvasSize.width() / 2, canvasSize.height() / 2),
      _penDown(true),
      _penColor(PenColor::black),
      _penSize(3),
      _canvasSize(canvasSize)
{
}

void Turtle::Forward(double distance, bool backward)
{
  const int backwardModifier = backward ? -1 : 1;
  double newX = _position.x + distance * cos(backwardModifier * _heading);
  int timesAroundTheWorld = newX / _canvasSize.width();
  _position.x = newX - backwardModifier * timesAroundTheWorld * _canvasSize.width();

  double newY = _position.y + distance * sin(backwardModifier * _heading);
  timesAroundTheWorld = newY / _canvasSize.height();
  _position.y = newY - backwardModifier * timesAroundTheWorld * _canvasSize.height();
}

void Turtle::Backward(double distance)
{
  Forward(distance, true);
}

void Turtle::PenDown(bool down)
{
  _penDown = down;
}