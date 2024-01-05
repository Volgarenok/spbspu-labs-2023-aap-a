#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "shape.hpp"

namespace nikitov
{
  class Diamond: public Shape
  {
  public:
    Diamond(point_t& firstPoint, point_t& secondPoint, point_t& thirdPoint);
    virtual double getArea();
    virtual rectangle_t getFrameRect();
    virtual void move(const point_t& point);
    virtual void move(double dx, double dy);
    virtual void scale(double ratio);
  private:
    point_t firstPoint_;
    point_t secondPoint_;
    point_t thirdPoint_;
  };
}
#endif
