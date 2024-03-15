#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace nikitov
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t& point) = 0;
    virtual void move(double dx, double dy) = 0;
    void scale(double ratio);
    void unsafeScale(double ratio);
    virtual Shape* clone() const = 0;
  private:
    virtual void doScale(double ratio) = 0;
  };
}
#endif
