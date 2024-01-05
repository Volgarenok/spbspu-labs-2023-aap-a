#ifndef GEOM_FUNC_HPP
#define GEOM_FUNC_HPP

#include "shape.hpp"

namespace erohin
{
  void isoScale(Shape& shape, point_t pos, double ratio);
  double getDistance(point_t from, point_t to);
}

#endif
