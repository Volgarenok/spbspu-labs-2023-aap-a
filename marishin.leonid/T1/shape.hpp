#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace marishin
{
  class Shape
  {
  public:
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t& newPos) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void unsafeScale(double factor) = 0;
    void scale(double factor);
    virtual ~Shape() = default;
  };
}

#endif
