#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"
#include "calculatetriangle.hpp"

namespace marishin
{
  class Triangle : public Shape
  {
  public:
    Triangle(const point_t firstPoint, const point_t secondPoint, const point_t thirdPoint);
    virtual ~Triangle();
    virtual double getArea();
    virtual rectangle_t getFrameRect();
    virtual void move(const point_t newPos);
    virtual void move(const double dx, const double dy);
    virtual void scale(const double factor);
  private:
    point_t firstPoint_;
    point_t secondPoint_;
    point_t thirdPoint_;
  }
}

#endif
