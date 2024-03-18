#ifndef OUTPUT_HPP
#define OUTPUT_HPP
#include <cstddef>
#include <iostream>
#include "shape.hpp"
namespace sakovskaia
{
  void outputShapes(std::ostream & output, const Shape * const * shapes, size_t count);
}
#endif
