#ifndef INPUT_HPP
#define INPUT_HPP
#include <cstddef>
#include "shape.hpp"
namespace sakovskaia
{
  void coorShapes(const char * string, double * coordinates, size_t cnt);
  Shape * inputRectangle(const char * string);
}
#endif
