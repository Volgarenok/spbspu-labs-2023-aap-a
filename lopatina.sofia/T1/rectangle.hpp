#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
#include "base-types.hpp"
namespace lopatina
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(point_t a, point_t b);
    virtual ~Rectangle() = default;
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(point_t s);
    virtual void move(double x, double y);
    virtual void scale(double k);
  private:
    point_t left_corner_;
    point_t right_corner_;
  };
}

#endif
