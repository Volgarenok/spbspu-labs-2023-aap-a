#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "baseTypes.hpp"

namespace spiridonov
{
  class Shape
  {
  public:
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t pos) = 0;
    virtual void move(double x, double y) = 0;
    virtual void scale(double coefficient) = 0;
    virtual ~Shape() = default;
  };
}

#endif
