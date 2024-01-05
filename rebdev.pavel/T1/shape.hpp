#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"
namespace rebdev
{
  class Shape
  {
    public:
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() = 0;
    virtual void move(const point_t point) = 0;
    virtual void move(const double x, const double y) = 0;
    virtual void scale(const double k) = 0;
  };
}
#endif
