#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace zhalilov
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t &point) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void unsafeScale(double ratio) = 0;
    void scale(double ratio);
  };
}

#endif
