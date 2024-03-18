#ifndef OUTPUT_SHAPES_HPP
#define OUTPUT_SHAPES_HPP

#include <ostream>
#include <cstddef>
#include "shape.hpp"

namespace grechishnikov
{
  void outputShapes(std::ostream& out, const Shape* const* shapes, size_t size);
}

#endif
