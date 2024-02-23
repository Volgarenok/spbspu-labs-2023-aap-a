#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace sivkov
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(const point_t leftBotton, const point_t rightTop);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(const point_t newPos);
    void move(const double dx, const double dy);
    void scale(const double k);
  private:
    point_t leftBottom_;
    point_t rightTop_;
  };
}

#endif
