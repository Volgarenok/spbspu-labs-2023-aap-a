#ifndef SCALE_HPP
#define SCALE_HPP

#include "shape.hpp"
#include "base-types.hpp"
#include <iostream>

namespace marishin
{
  void scale(Shape* shape, point_t& center, double scaleCoefficient);
}

#endif
