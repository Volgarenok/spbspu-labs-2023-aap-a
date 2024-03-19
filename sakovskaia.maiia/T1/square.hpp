#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "shape.hpp"
namespace sakovskaia
{
  class Square: public Shape
  {
  public:
    Square(const point_t ll, double length);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t);
    virtual void move(double dx, double dy);
    virtual void scaleShape(double k);
  private:
    point_t ll_;
    double length_;
  };
}
#endif
