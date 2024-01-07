#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace marishin
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() = 0;
    virtual rectangle_t getFrameRect() = 0;
    virtual void move(const point_t newPos) = 0;
    virtual void move(const double dx, const double dy) = 0;
    virtual void scale(const double factor) = 0;
  };
}

#endif
