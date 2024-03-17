#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace novokhatskiy
{
  class Rectangle: public Shape
  {

  public:
    Rectangle(const point_t &leftCorner, const point_t &rightCorner);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t &p);
    virtual void move(double x, double y);
    virtual void scale(double ratio);

  private:
    point_t leftCorner_;
    point_t rightCorner_;
  };
}

#endif
