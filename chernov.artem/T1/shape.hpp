#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace chernov
{
  class Shape
  {
  public:
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() = 0;
    virtual void move(const point_t pos) = 0;
    virtual void move(const double moveX, const double moveY) = 0;
    virtual void scale(const double multiplier) = 0;
    virtual ~Shape() = default;
    virtual Shape* clone() const = 0;
  };
}

#endif
