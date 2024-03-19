#ifndef SHAPE
#define SHAPE
#include "base-types.hpp"

namespace petuhov
{
  class Shape
  {
    public:
      virtual ~Shape() = default;

      virtual double getArea() const = 0;
      virtual rectangle_t getFrameRect() const = 0;
      virtual void move(const petuhov::point_t & newPos) = 0;
      virtual void move(double dx, double dy) = 0;
      virtual void scale(double center_x, double center_y, double factor) = 0;
  };
}

#endif
