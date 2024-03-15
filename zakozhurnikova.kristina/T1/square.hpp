#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "shape.hpp"

namespace zakozhurnikova
{

  class Square: public Shape
  {
  public:
    Square(const point_t& downLeft, double length);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(const point_t& p);
    void move(double dx, double dy);
    void unsafeScale(double k);

  private:
    point_t downLeft_;
    double length_;
  };
}
#endif
