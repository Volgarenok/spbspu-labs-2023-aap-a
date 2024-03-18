#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.hpp"
#include "base-types.hpp"

namespace shabalin
{
  class Triangle : public Shape
  {
  public:
    Triangle(point_t p1, point_t p2, point_t p3);
    void move(point_t p) override;
    void move(double shift_x, double shift_y) override;
    void scale(double scale) override;
    double getArea() const override;
    double distance(point_t p1, point_t p2);
    bool isTriangle(point_t p1, point_t p2, point_t p3);
    rectange_t getFrameRect() const override;
    Shape* clone() const override;
  private:
    point_t p1_;
    point_t p2_;
    point_t p3_;
  };
}

#endif
