#ifndef IOOPERATIONS_HPP
#define IOOPERATIONS_HPP
#include "shape.hpp"
#include "base_type.hpp"
#include <iostream>

namespace shabalin
{
  void inputOfShapes(const char *str, point_t &point, double &ratio);
  void outputOfShapes(std::ostream &output, const Shape *const *shapes, const size_t numberOfShapes);
}

#endif
