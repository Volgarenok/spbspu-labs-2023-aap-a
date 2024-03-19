#ifndef INPUT_HPP
#define INPUT_HPP
#include <cstddef>
#include "shape.hpp"
namespace sakovskaia
{
  void coorShape(const char * string, double * coordinates, size_t cnt);
  Shape * inputRectangle(const char * string);
  Shape * inputParallelogram(const char * string);
  Shape * inputSquare(const char * string);
  Shape * inputEllipse(const char * string);
}
#endif
