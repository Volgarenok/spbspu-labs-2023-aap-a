#ifndef DOSCALE_HPP
#define DOSCALE_HPP

#include <cstddef>
#include <istream>

#include "shape.hpp"
#include "base-types.hpp"

namespace vyzhanov
{
  void doScale(Shape& shape, const point_t& point, const double ratio);
}

#endif
