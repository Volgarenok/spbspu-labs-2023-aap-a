#ifndef OUTPUT_HPP
#define OUTPUT_HPP
#include <iostream>
#include "shape.hpp"

namespace vyzhanov
{
  void outputShapes(std::ostream& output, const Shape* const* shapes, size_t count);
}

#endif
