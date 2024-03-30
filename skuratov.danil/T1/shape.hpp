#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace skuratov
{
  class Shape
  {
  public:
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t& A) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void scale(double scalingFactor) = 0;
    virtual ~Shape() = default;
  };
}

#endif
