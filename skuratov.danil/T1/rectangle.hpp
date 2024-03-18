#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace skuratov
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(const point_t& lowerLeftCorner, const point_t& upperRightCorner);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t& A);
    virtual void move(double dx, double dy);
    virtual void scale(double scalingFactor);
    virtual ~Rectangle() = default;

  private:
    point_t lowerLeftCorner_;
    point_t upperRightCorner_;
  };
}

#endif
