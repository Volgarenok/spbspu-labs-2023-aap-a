#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace piyavkin
{
  class Shape
  {
  public:
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t& bias) = 0;
    virtual void move(double dx, double dy) = 0;
    void scale(double k);
    virtual ~Shape() = default;
    virtual Shape* clone() const = 0;
    virtual void unsafeScale(double k) = 0;
  };
}
#endif
