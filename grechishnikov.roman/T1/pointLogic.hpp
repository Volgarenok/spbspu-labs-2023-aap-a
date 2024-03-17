#ifndef POINT_LOGIC_HPP
#define POINT_LOGIC_HPP

#include <cstddef>
#include "base-types.hpp"

namespace grechishnikov
{
  point_t getAveragePoint(const point_t* points, size_t size);
  rectangle_t getFrameRectGeneral(const point_t* points, size_t size);
  void scalePoints(point_t* points, size_t size, size_t rate);
  void unsafeScalePoints(point_t* points, size_t size, size_t rate);
  void scalePoint(point_t& point, const point_t& scalePoint, size_t rate);
  void movePoints(point_t* points, size_t size, double dx, double dy);
}

#endif
