#ifndef OUTPUT_SHAPES_HPP
#define OUTPUT_SHAPES_HPP
#include <cstddef>
#include <ostream>
#include "shape.hpp"

namespace novokhatskiy
{
  void outputShapes(std::ostream &output, const Shape* const* shapes, size_t shapeCounter);
}

#endif
