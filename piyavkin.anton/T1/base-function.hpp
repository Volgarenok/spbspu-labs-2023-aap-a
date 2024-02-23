#ifndef BASE_FUNCTION_HPP
#define BASE_FUNCTION_HPP
#include "base-types.hpp"

namespace piyavkin
{
  double getLength(const point_t& p1, const point_t& p2);
  point_t& addShift(point_t& p, double dx, double dy);
  point_t& scalePoint(point_t& p, const point_t& pos, double k);
}

#endif
