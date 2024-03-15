#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include <ostream>
#include <iomanip>
#include "shape.hpp"

namespace ishmuratov
{
  void outputShape(std::ostream & output, const Shape * const * shapes, size_t count);
}

#endif
