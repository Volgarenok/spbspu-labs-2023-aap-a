#ifndef OPERATIONS_HPP
#define OPERATIONS_HPP
#include "base_type.hpp"
#include "shape.hpp"
#include <iostream>
#include <cstddef>

namespace shabalin
{
  void isoScale(Shape *shapeObject, point_t position, double ratio);
  void outOfScale(shabalin::Shape **shapes, std::ostream &out, const size_t shapeCount, const point_t pointOfScale, const double r);
}

#endif
