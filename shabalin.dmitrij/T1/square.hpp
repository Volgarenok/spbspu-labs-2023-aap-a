#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "shape.hpp"

namespace shabalin
{
  class Square: public Shape
  {
  public:
    Square(const point_t &, double);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t);
    virtual void move(double, double);
    virtual void scale(double);
    virtual ~Square() = default;
  private:
    point_t leftCorner_;
    double lengthOfSide_;
  };
}

#endif