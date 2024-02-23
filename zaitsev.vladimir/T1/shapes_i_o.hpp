#ifndef SHAPES_I_O_H
#define SHAPES_I_O_H
#include <iostream>
#include <cstddef>
#include "base-types.hpp"
#include "shape.hpp"

namespace zaitsev
{
  double readValue(std::istream& input);
  void readPoint(std::istream& input, point_t& dest);
  void readArray(std::istream& input, point_t* dest, size_t size);
  Shape* readRectangle(std::istream& input);
  Shape* readComplexquad(std::istream& input);
  Shape* readParallelogram(std::istream& input);
  void readScale(std::istream& input, point_t& center, double& factor);
  std::ostream& shapesOutput(std::ostream& output, const Shape* const* shapes, size_t size);
  void freeShapes(Shape** shapes, size_t size);
}
#endif
