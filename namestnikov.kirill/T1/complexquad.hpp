#ifndef COMPLEXQUAD_H
#define COMPLEXQUAD_H

#include "shape.hpp"
#include <stdexcept>
#include <cmath>
#include <cstddef>

namespace namestnikov
{
  class Complexquad : public Shape
  {
  public:
    Complexquad(point_t * points, size_t size);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t & p);
    virtual void move(const double dx, const double dy);
    virtual void scale(const double coefficient);
  private:
    point_t complexquadPoints_;
    size_t complexquadSize_;
  };
}

#endif
