#ifndef SHAPE
#define SHAPE
#include "base-types.hpp"

namespace petuhov
{
  class Shape
  {
    public:
      virtual double getArea() const = 0;
      virtual rectangle_t getFrameRect() const = 0;
      virtual void move(const petuhov::point_t & pos) = 0;
      virtual void scale(double factor) = 0;
  };
}

#endif
