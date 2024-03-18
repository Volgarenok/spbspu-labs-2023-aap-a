#ifndef OUTPUT_OPERATIONS_HPP
#define OUTPUT_OPERATIONS_HPP
#include <iostream>
#include "shape.hpp"

namespace zakozhurnikova
{
  void showCoordinates(std::ostream& out, const rectangle_t& rec);
  void printShapes(std::ostream& output, const Shape* const* shapes, size_t size);
}
#endif
