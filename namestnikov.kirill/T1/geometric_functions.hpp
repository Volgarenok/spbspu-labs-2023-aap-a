#ifndef GEOMETRIC_FUNCTIONS_H
#define GEOMETRIC_FUNCTIONS_H

#include "base-types.hpp"
#include "shape.hpp"
#include <cstddef>

namespace namestnikov
{
  double getSizeOfLine(const point_t & p1, const point_t & p2);
  double getAreaOfTriangle(const point_t & p1, const point_t & p2, const point_t & p3);
  point_t getIntersectionOfTwoLines(point_t * points);
  void fillLineCoefficients(const point_t & p1, const point_t & p2, double & a, double & b, double & c);
  void isoScale(Shape * shape, const point_t & point, double coefficient);
  void deleteShapes(Shape ** shapes, size_t size);
}

#endif
