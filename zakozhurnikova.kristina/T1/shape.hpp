#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace zakozhurnikova
{
  class Shape
  {
  public:
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t& p) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void scale(double k) = 0;
    virtual ~Shape() {}
  };
}
#endif
