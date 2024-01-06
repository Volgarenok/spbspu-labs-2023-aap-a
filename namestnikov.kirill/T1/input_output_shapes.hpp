#ifndef INPUT_OUTPUT_SHAPES_HPP
#define INPUT_OUTPUT_SHAPES_HPP
#include "shape.hpp"
#include <iostream>
#include <cstddef>

namespace namestnikov
{
  Shape ** inputShapes(std::istream & in, size_t & count);
  std::ostream & outputShapes(std::ostream & out, size_t count, Shape ** shapes);
}

#endif
