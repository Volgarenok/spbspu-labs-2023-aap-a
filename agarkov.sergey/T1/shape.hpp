#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace agarkov
{
  class Shape
  {
  public:
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void move(point_t position) = 0;
    virtual void scale(double k) = 0;

    virtual ~Shape() = default;
  };
}

#endif
