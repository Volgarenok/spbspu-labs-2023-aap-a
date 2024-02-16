#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "base-types.hpp"
#include "shape.hpp"

namespace spiridonov
{
class Rectangle: public Shape
{
 public:
  Rectangle(const point_t & p1, const point_t & p2);
  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(point_t pos);
  void move(double x, double y);
  void scale(double coefficient);

 private:
  point_t bottomLeft_;
  point_t topRight_;
};
}

#endif
