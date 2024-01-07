#ifndef RING_HPP
#define RING_HPP

#include "shape.hpp"
#include <stdexcept>
#include <cmath>
#include <math.h>
#define _USE_MATH_DEFINES

namespace marishin
{
  class Ring : public Shape
  {
  public:
    Ring(point_t center, const double radius1, const double radius2);
    virtual ~Ring();
    virtual double getArea();
    virtual rectangle_t getFrameRect();
    virtual void move(const point_t newPos);
    virtual void move(const double dx, const double dy);
    virtual void scale(const double factor);
  private:
    point_t center_;
    double radius1_;
    double radius2_;
  };
}

#endif
