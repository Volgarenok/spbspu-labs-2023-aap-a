#ifndef OUTPUT_HPP
#define OUTPUT_HPP
#include <iostream>
#include "shape.hpp"

namespace sivkov
{
  void output(std::ostream& out, const Shape* const* shapes, size_t count);
}

#endif

