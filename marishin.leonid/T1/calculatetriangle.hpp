#ifndef CALCULATETRIANGLE_HPP
#define CALCULATETRIANGLE_HPP

#include "base-types.hpp"
#include "shape.hpp"
#include "triangle.hpp"
#include <cmath>

namespace marishin
{
  double calculateDistance(const point_t& p1, const point_t& p2);
  bool isTriangleExist(const point_t& p1, const point_t& p2, const point_t& p3);
  double calculateTriangleArea(const point_t& p1, const point_t& p2, const point_t& p3);
}

#endif
