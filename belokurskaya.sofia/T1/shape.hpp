#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace belokurskaya
{
  class Shape
  {
    public:
      virtual ~Shape() = default;
      virtual double getArea() const = 0;
      virtual rectangle_t getFrameRect() const = 0;
      virtual void move(const point_t & new_pos) = 0;
      virtual void move(double dx, double dy) = 0;
      virtual void scale(double factor) = 0;
  };
}

#endif
