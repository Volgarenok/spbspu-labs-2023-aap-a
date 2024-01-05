#ifndef SCALE_HPP
#define SCALE_HPP
#include "shape.hpp"
#include <cstddef>

namespace baranov
{
  void scale(baranov::Shape * shape, baranov::point_t scalePoint, size_t scaleRatio);
}

#endif

