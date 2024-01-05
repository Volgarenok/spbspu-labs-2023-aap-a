#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include <iostream>
#include "shape.hpp"
#include "base-types.hpp"
namespace piyavkin
{
  class Triangle: public Shape
  {
  public:
    Triangle(point_t p1, point_t p2, point_t p3);
    virtual double getArea();
    virtual rectangle_t getFrameRect();
    virtual void move(point_t bias);
    virtual void move(double dx, double dy);
    virtual void scale(double k);
  private:
    point_t a_;
    point_t b_;
    point_t c_;
  };
}
#endif
