#ifndef CONCAVE_HPP
#define CONCAVE_HPP
#include "shape.hpp"
#include "base-types.hpp"

namespace spiridonov
{
  class Concave: public Shape
  {
  public:
    Concave(point_t p1, point_t p2, point_t p3, point_t p4);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t pos);
    void move(double x, double y);
    void scale(double coefficient);
    Concave* clone() const;
  private:
    point_t arrayOfPoints_[4];
    rectangle_t frameRect_;

    void updateFrameRect();
  };
}

#endif

