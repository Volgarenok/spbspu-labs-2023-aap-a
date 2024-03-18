#ifndef SHAPE
#define SHAPE
#include "base-types.hpp"

namespace petuhov
{
  class Shape
  {
    public:
      virtual ~Shape() = default;

      virtual float getArea() const = 0;
      virtual rectangle_t getFrameRect() const = 0;
      virtual void move(const petuhov::point_t & newPos) = 0;
      virtual void move(float dx, float dy) = 0;
      virtual void scale(const petuhov::point_t &center, float factor) = 0;
  };
}

#endif
