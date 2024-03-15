#ifndef INPUTSHAPE_HPP
#define INPUTSHAPE_HPP
#include <istream>
#include "compositeshape.hpp"
#include "shape.hpp"

namespace piyavkin
{
  void inputParameters(std::istream& in, double* parameters, size_t parametersCount);
  void clearMemory(Shape** shapes, size_t shapeCount);
  Shape* inputRectangle(std::istream& in);
  Shape* inputTriangle(std::istream& in);
  Shape* inputParallelogram(std::istream& in);
  void inputShape(std::istream& in, CompositeShape& cs);
}
#endif
