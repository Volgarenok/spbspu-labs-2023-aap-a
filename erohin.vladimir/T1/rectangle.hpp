#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "base-types.hpp"
#include "shape.hpp"

namespace erohin
{
  class Rectangle: public Shape
  {
  public:
    Rectangle();
    Rectangle(point_t left_corner, point_t right_corner);
    virtual ~Rectangle();
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(double dx, double dy);
    virtual void move(point_t point);
    virtual void scale(double ratio);
  private:
    rectangle_t frameRect_;
  };
}

#endif
