#ifndef ISOTROPSCALE_HPP
#define ISOTROPSCALE_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace chistyakov
{
  void isotropScale(Shape ** shapes, const point_t & point, const double ratio, const size_t size);
}

#endif
