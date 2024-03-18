#ifndef OUTPUTSHAPE_HPP
#define OUTPUTSHAPE_HPP

#include <ostream>
#include <cstddef>

#include "shape.hpp"
#include "base-types.hpp"

namespace chistyakov
{
  void outputShape(std::ostream & out, const Shape * const * shapes, size_t size);
}

#endif
