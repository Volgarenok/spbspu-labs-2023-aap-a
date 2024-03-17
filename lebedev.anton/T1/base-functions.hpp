#ifndef BASE_FUNCTIONS_HPP
#define BASE_FUNCTIONS_HPP

#include "base-types.hpp"

namespace lebedev
{
  point_t & scalePoint(point_t & p, const point_t & pos, double ratio);
  bool checkLinesIntersection(const point_t & p1, const point_t & p2, const point_t & p3, const point_t & p4);
  point_t findLinesIntersection(const point_t & p1, const point_t & p2, const point_t & p3, const point_t & p4);
  double findAreaOfTriangle(const point_t & p1, const point_t & p2, const point_t & p3);
}

#endif
