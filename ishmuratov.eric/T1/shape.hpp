#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace ishmuratov
{
  class Shape
  {
    public:
      virtual ~Shape() = default;
      virtual double getArea() = 0;
      virtual rectangle_t getFrameRect() const = 0;
      virtual void move(point_t& position) = 0;
      virtual void move(double dx, double dy) = 0;
      virtual void scale(double factor) = 0;
  };
}

#endif