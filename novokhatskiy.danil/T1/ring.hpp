#ifndef RING_HPP
#define RING_HPP
#include "shape.hpp"

namespace novokhatskiy
{
  class Ring: public Shape
  {
  public:
    Ring(const point_t &center, double outerRadius, double innerRadius);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t &point);
    virtual void move(double x, double y);
    virtual void scale(double ratio);

  private:
    point_t center_;
    double innerRadius_;
    double outerRadius_;
  };
}

#endif
