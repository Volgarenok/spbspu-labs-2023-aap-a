#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace arakelyan
{
  struct Shape
  {
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t) = 0;
    virtual void move(double, double) = 0;
    void scale(double k);
    virtual void scaleShape(double k) = 0;
    virtual ~Shape() = default;
  };
}
#endif
