#pragma once

class Point
{
public:
  Point();
  Point(double x, double y) : x(x), y(y)
  {
  }

  double x;
  double y;
};