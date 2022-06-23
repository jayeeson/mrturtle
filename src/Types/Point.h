#pragma once

class Point
{
public:
  Point();
  Point(double x, double y) : x(x), y(y)
  {
  }

  inline bool operator==(const Point &rhs) const;

  double x;
  double y;
};

inline bool Point::operator==(const Point &rhs) const
{
  return x == rhs.x && y == rhs.y;
}