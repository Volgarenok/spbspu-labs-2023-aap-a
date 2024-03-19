#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace stepanov
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t &p) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void scale(double ratio);
    virtual void unsafeScale(double ratio);
  private:
    virtual void doScale(double ratio) = 0;
  };
}

#endif
