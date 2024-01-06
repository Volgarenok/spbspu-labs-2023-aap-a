#ifndef SHAPE_H
#define SHAPE_H

#include "base-types.hpp"

namespace namestnikov
{
  class Shape
  {
  public:
    Shape();
    ~Shape() = default;
    virtual double getArea() const;
    virtual rectangle_t getFrameRect();
    virtual void move(const point_t & p);
    virtual void move(const double dx, const double dy);
    virtual void scale(const double coefficient);
  };
}

#endif
