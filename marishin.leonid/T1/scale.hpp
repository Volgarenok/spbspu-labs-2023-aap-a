#ifndef SCALE_HPP
#define SCALE_HPP

#include <stdexcept>
#include "shape.hpp"
#include "base-types.hpp"

namespace marishin
{
  void isoScale(Shape *shape, const point_t& center, double coefficient);
  void scale(Shape *shape, const point_t& center, double coefficient);
}

#endif
