#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "base-types.hpp"
#include "shape.hpp"

namespace erohin
{
  class Triangle: public Shape
  {
  public:
    Triangle(point_t corner1, point_t corner2, point_t corner3);
    virtual ~Triangle();
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(double dx, double dy);
    virtual void move(point_t point);
    virtual void unsafeScale(double ratio);
    virtual Shape* clone() const;
  private:
    point_t vertex_[3];
    point_t getCenter() const;
  };
}

#endif
