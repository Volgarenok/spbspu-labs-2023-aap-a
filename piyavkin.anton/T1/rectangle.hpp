#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "base-types.hpp"
#include "shape.hpp"
namespace piyavkin
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(point_t p1, point_t p2);
    virtual double getArea();
    virtual rectangle_t getFrameRect();
    virtual void move(point_t bias);
    virtual void move(double dx, double dy);
    virtual void scale(double k);
  private:
    point_t p1_;
    point_t p2_;
  };
}
#endif
