#ifndef SHAPE_H
#define SHAPE_H
#include "base-types.h"

namespace zaitsev
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t& dest_pos) = 0;
    virtual void move(double x_shift, double y_shift) = 0;
    virtual void scale(double factor) = 0;
  };
}
#endif
