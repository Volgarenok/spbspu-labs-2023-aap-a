#ifndef INPUT_SHAPES_HPP
#define INPUT_SHAPES_HPP
#include "shape.hpp"
#include <cstddef>
namespace strelyaev
{
  void createPoints(size_t, double*, point_t*);
  Shape* inputRectangle(const char*);
  Shape* inputTriangle(const char*);
  Shape* inputParallelogram(const char*);
}
#endif
