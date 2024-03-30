#ifndef INPUT_SHAPES_HPP
#define INPUT_SHAPES_HPP
#include "shape.hpp"
#include <istream>
#include <cstddef>

namespace novokhatskiy
{
  void freeShapes(Shape** shapes, size_t shapeCounter);
  Shape** inputShapes(std::istream& input, size_t& shapeCounter);
}

#endif
