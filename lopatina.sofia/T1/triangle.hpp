#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"
#include "base-types.hpp"
namespace lopatina
{
  class Triangle: public Shape
  {
  public:
    Triangle(point_t point1, point_t point2, point_t point3);
    virtual ~Triangle() = default;
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(point_t s);
    virtual void move(double x, double y);
    virtual void scale(double k);
  private:
    point_t points_[3];
  };
}

#endif
