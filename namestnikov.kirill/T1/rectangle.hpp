#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.hpp"

namespace namestnikov
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const point_t & leftAnglePoint, const point_t & rightAnglePoint);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t & p);
    virtual void move(const double dx, const double dy);
    virtual void scale(const double coefficient);
  private:
    rectangle_t frameRect_;
  };
}

#endif
