#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <cstddef>
#include "base-types.hpp"

namespace rebdev
{
  class Shape
  {
    public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t & point) = 0;
    virtual void move(double x, double y) = 0;
    virtual void scale(double k) = 0;
  };

  void isoScale(Shape ** arr, size_t numOfShape, const point_t & scalePoint, double k);
  void deleteShapes(Shape ** shapes, size_t numOfShape);
}

#endif
