#ifndef SCALERECTANGLE_HPP
#define SCALERECTANGLE_HPP

#include "base-types.hpp"

namespace marishin
{
  point_t mixPoint(point_t& corner, double dx, double dy);
  point_t scalePoint(point_t& corner, const point_t& pos, double factor);
}

#endif
