#ifndef SHAPES_I_O_H
#define SHAPES_I_O_H
#include <ostream>
#include <cstddef>
#include "base-types.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Complexquad.h"

namespace zaitsev
{
  double readNextValue(char* param);
  Shape* readRectangle(char* param);
  Shape* readComplexquad(char* param);
  Shape* readParallelogram(char* param);
  void readScale(char* param, point_t& center, double& factor);
  std::ostream& shapesOutput(std::ostream& output, const Shape* const* shapes, size_t size);
  void addShape(Shape*** shapes, size_t &size, size_t &capacity, Shape* new_shape);
}
#endif
