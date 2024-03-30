#ifndef OUTPUT_SHAPES_HPP
#define OUTPUT_SHAPES_HPP
#include <iostream>
#include "shape.hpp"

namespace baranov
{
  double getSumArea(const Shape * const * shapes, size_t count);
  void outputShapes(std::ostream & output, const Shape * const * shapes, size_t count);
}

#endif

