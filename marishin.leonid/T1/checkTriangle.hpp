#ifndef CHECKTRIANGLE_HPP
#define CHECKTRIANGLE_HPP

#include "base-types.hpp"

namespace marishin
{
  void checkTriangle(const point_t& first, const point_t& second, const point_t& third);
  double getAreaTriangle(const point_t& first, const point_t& second, const point_t& third);
  rectangle_t getFrameRectTriangle(const point_t& first, const point_t& second, const point_t& third);
  point_t scaleCorner(point_t& corner, point_t& pos, double factor);
}

#endif
