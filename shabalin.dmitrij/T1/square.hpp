#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "shape.hpp"

namespace shabalin
{
  class Square: public Shape
  {
  public:
    Square(const point_t &leftCorner, double lengthOfSide);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t &);
    virtual void move(double, double);
    void unsafeScale(double ratio);
  private:
    point_t leftCorner_;
    double lengthOfSide_;
  };
}

#endif