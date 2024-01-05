#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

class Shape
{
  public:
    virtual ~Shape() = default;

    virtual float getArea() const = 0;

    virtual rectangle_t getFrameRect() const = 0;

    virtual void move(const point_t & new_pos) = 0;

    virtual void move(float dx, float dy) = 0;

    virtual void scale(float factor) = 0;
};

#endif
