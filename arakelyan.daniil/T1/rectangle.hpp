#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "base-types.hpp"
#include "shape.hpp"

namespace arakelyan
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(point_t fp, point_t sp);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(point_t point);
    virtual void move(double delX, double delY);
    virtual void scaleShape(double k);
    virtual ~Rectangle() = default;
  private:
    point_t pointRightUp_;
    point_t pointLeftDown_;
  };
}
#endif
