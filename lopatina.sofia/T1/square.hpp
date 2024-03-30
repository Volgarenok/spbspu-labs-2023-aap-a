#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "shape.hpp"
#include "base-types.hpp"
namespace lopatina
{
  class Square: public Shape
  {
  public:
    Square(point_t a, double side);
    virtual ~Square() = default;
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(point_t s);
    virtual void move(double x, double y);
    virtual void scale(double k);
  private:
    point_t left_corner_;
    double side_;
  };
}

#endif
