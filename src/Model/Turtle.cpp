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
    const double qtCoordinateOffsetX =
        _canvas.GetOriginalCanvasSize().width() / 2 + _canvas.GetHalfWidthDiff();
    const double qtCoordinateOffsetY =
        _canvas.GetOriginalCanvasSize().height() / 2 + _canvas.GetHalfHeightDiff();
    double newX = _position.x() + distance * cos(backardModifier + _heading) + qtCoordinateOffsetX;
    double newY = _position.y() + distance * sin(backardModifier + _heading) + qtCoordinateOffsetY;

    if (newX < 0)
    {
        auto wraps = floor(-newX / _canvas.GetCanvasSize().width());
        newX = _canvas.GetCanvasSize().width() + (newX + wraps * _canvas.GetCanvasSize().width());
        _position.setX(newX - qtCoordinateOffsetX);
    }
    else
    {
        _position.setX(
            newX - floor(newX / _canvas.GetCanvasSize().width()) * _canvas.GetCanvasSize().width() -
            qtCoordinateOffsetX);
    }

    if (newY < 0)
    {
        auto wraps = floor(-newY / _canvas.GetCanvasSize().height());
        newY = _canvas.GetCanvasSize().height() + (newY + wraps * _canvas.GetCanvasSize().height());
        _position.setY(newY - qtCoordinateOffsetY);
    }
    else
    {
        _position.setY(newY -
                       floor(newY / _canvas.GetCanvasSize().height()) *
                           _canvas.GetCanvasSize().height() -
                       qtCoordinateOffsetY);
    }

    emit PositionChanged();
}

void Turtle::Backward(double distance) { Forward(distance, true); }

void Turtle::RotateRad(double angle)
{
    _heading += angle;
    _heading = ClampAngleToUnitCircle(_heading);
    emit HeadingChanged();
}

void Turtle::RotateDeg(double angle) { RotateRad(angle * M_PI / 180); }

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
