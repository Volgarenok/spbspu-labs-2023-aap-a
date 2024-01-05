#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace baranov
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const point_t & ldCorner, const point_t & ruCorner);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t & destPos);
    virtual void move(double dx, double dy);
    virtual void scale(double ratio);
  private:
    point_t ldCorner_;
    point_t ruCorner_;
  };
}

#endif

