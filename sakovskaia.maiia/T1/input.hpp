#ifndef INPUT_HPP
#define INPUT_HPP
#include <cstddef>
namespace sakovskaia
{
  void coorShapes(const char * string, double * coordinates, size_t cnt_points);
  Shape * inputRectangle(const char * string);
}
#endif
