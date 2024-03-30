#ifndef GEOM_FUNCTIONS_H
#define GEOM_FUNCTIONS_H
#include "base-types.hpp"
#include "shape.hpp"
#include "composite_shape.hpp"

namespace zaitsev
{
  bool checkIntersection(const point_t* sections);
  point_t findIntersection(const point_t* sections);
  double getAreaOfTriangle(point_t p1, point_t p2, point_t p3);
  void changeRectangleBounds(point_t& left_corner, point_t& right_corner, point_t new_pt);
  rectangle_t transformRectangleBounds(point_t left_corner, point_t right_corner);
  template< typename T >
  void scale(T& shape, double factor, point_t iso_center)
  {
    if (factor <= 0)
    {
      throw std::invalid_argument("Scale factor must be positive");
    }
    point_t start_pos = shape.getFrameRect().pos;
    shape.move(iso_center);
    point_t iso_center_pos = shape.getFrameRect().pos;
    shape.scale(factor);
    shape.move(factor * (start_pos.x - iso_center_pos.x), factor * (start_pos.y - iso_center_pos.y));
  }
}
#endif
