#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
#include "scaleRectangle.hpp"

namespace marishin
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(const point_t& lowerLeftCorner, const point_t& topRightCorner);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t& newPos);
    virtual void move(double dx, double dy);
    virtual void unsafeScale(double factor);
  private:
    point_t lowerLeftCorner_;
    point_t topRightCorner_;
  };
}

#endif
