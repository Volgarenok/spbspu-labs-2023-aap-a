#ifndef SHAPE_HPP 
#define SHAPE_HPP
#include "base_type.hpp"

namespace shabalin
{
  struct Shape
  {
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t postion) = 0;
    virtual void move(double, double) = 0;
    virtual void scale(double);
  };
}

#endif 
