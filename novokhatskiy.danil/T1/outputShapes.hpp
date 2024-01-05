#ifndef OUTPUT_SHAPES_HPP
#define OUTPUT_SHAPES_HPP
#include "shape.hpp"
#include <cstddef>
#include <ostream>

namespace novokhatskiy
{
  void outputShapes(std::ostream &output, size_t shapeCounter, Shape **shapes);
}

#endif