#pragma once

#include <stdexcept>

template <class T>
class Size
{
public:
  Size() = default;
  Size(T height, T width) : _height(height), _width(width)
  {
    if (_height < 0 || _width < 0)
    {
      throw std::invalid_argument("Initializing size with negative value");
    }
  }

  void SetHeight(T height);
  void SetWidth(T width);
  inline T height() { return _height; };
  inline T width() { return _width; };

private:
  T _height;
  T _width;
};

template <class T>
void Size<T>::SetHeight(T height)
{
  if (height < 0)
  {
    throw std::invalid_argument("can't set size to negative value");
  }
  _height = height;
}

template <class T>
void Size<T>::SetWidth(T width)
{
  if (width < 0)
  {
    throw std::invalid_argument("can't set size to negative value");
  }
  _width = width;
}