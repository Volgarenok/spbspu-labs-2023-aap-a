#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "shape.hpp"

namespace skuratov
{
  class Square: public Shape
  {
  public:
    Square(const point_t& bottomLeftCorner, double sideLength);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t& A);
    virtual void move(double dx, double dy);
    virtual void scale(double scalingFactor);
    virtual ~Square() = default;
  private:
    point_t bottomLeftCorner_;
    double sideLength_;
  };
}

#endif
