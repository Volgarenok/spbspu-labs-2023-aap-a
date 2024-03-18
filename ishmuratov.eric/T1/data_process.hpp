#ifndef DATA_PROCESS_HPP
#define DATA_PROCESS_HPP

#include <cmath>
#include <cstddef>
#include "shape.hpp"

namespace ishmuratov
{
  double triangleArea(const point_t & point1, const point_t & point2, const point_t & point3);
  point_t triangleCenter(const point_t & point1, const point_t & point2, const point_t & point3);
  point_t diamondCenter(const point_t & point1, const point_t & point2, const point_t & point3);
  double pseudoScalar(const point_t & point1, const point_t & point2);
  void scaleTriangle(point_t * array, point_t center, double factor);
  void scaleShapes(Shape * shapes, point_t position, double factor);
}

#endif
