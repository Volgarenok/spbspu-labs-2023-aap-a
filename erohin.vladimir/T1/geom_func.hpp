#ifndef GEOM_FUNC_HPP
#define GEOM_FUNC_HPP

#include <cstddef>
#include "base-types.hpp"
#include "shape.hpp"
#include "composite_shape.hpp"

namespace erohin
{
  void isoScale(Shape* shape, point_t pos, double ratio);
  void isoScale(CompositeShape& composite_shape, point_t pos, double ratio);
  double getDistance(point_t from, point_t to);
  double* getSides(double* result, const point_t* point, size_t side_number);
  bool isPointOnSegment(point_t point, point_t begin, point_t end);
  point_t findIntersectionPoint(const point_t* point);
  rectangle_t findPointsFrameRect(const point_t* point, size_t number);
  rectangle_t findRectangleFrameRect(point_t left_lower_corner, point_t right_upper_corner);
  rectangle_t findDiamondFrameRect(point_t corner1, point_t corner2, point_t corner3);
}

#endif
