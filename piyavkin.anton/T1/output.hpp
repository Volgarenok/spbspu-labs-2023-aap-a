#ifndef OUTPUT_HPP
#define OUTPUT_HPP
#include <ostream>
#include <iostream>
#include "shape.hpp"
#include "base-types.hpp"
namespace piyavkin
{
  void output(std::ostream& out, size_t shapeCount, Shape** shapes);
}
#endif
