#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP

#include <stdexcept>
#include <cmath>
#include <cstddef>
#include "shape.hpp"
#include "base-types.hpp"

namespace namestnikov
{
  class Complexquad: public Shape
  {
  public:
    Complexquad(const point_t & p1, const point_t & p2, const point_t & p3, const point_t & p4);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t & p);
    virtual void move(double dx, double dy);
    virtual void unsafeScale(double coefficient);
  private:
    point_t points_[4];
    point_t getCenter() const;
  };
}

#endif
