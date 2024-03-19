#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "shape.hpp"
namespace sakovskaia
{
  class Square: public Shape
  {
  public:
    Square(const point_t ll, double length);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(const point_t);
    void move(double dx, double dy);
    void scaleShape(double k);
  private:
    point_t ll_;
    double length_;
  };
}
#endif
