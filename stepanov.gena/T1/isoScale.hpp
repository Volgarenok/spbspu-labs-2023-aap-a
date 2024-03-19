#ifndef ISO_SCALE_HPP
#define ISO_SCALE_HPP

#include "shape.hpp"
#include "cstddef"
namespace stepanov
{
  void isoScale(Shape ** figures, point_t& p, double ratio, size_t size_shapes);
}

#endif
