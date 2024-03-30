#ifndef ISO_SCALE_HPP
#define ISO_SCALE_HPP

#include "shape.hpp"

namespace grechishnikov
{
  void isoScale(Shape* shape, point_t scalePoint, double ratio);
  void unsafeIsoScale(Shape* shape, point_t scalePoint, double ratio);
}

#endif
