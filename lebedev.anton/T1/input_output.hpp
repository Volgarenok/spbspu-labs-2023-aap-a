#ifndef INPUT_OUTPUT_HPP
#define INPUT_OUTPUT_HPP

#include <iostream>
#include <cstddef>
#include "shape.hpp"

namespace lebedev
{
  void clearShapes(Shape ** shapes, size_t shape_count);
  void inputRectangle(std::istream & input, Shape ** shapes, size_t & shapes_count);
  void inputParallelogram(std::istream & input, Shape ** shapes, size_t & shapes_count);
  void inputDiamond(std::istream & input, Shape ** shapes, size_t & shapes_count);
  void inputComplexquad(std::istream & input, Shape ** shapes, size_t & shapes_count);
  Shape ** inputShapes(std::istream & input, size_t & shapes_count);
  void outputFrameRect(std::ostream & output, const Shape * const * shapes, size_t shape_num);
  void outputShapes(std::ostream & output, const Shape * const * shapes, size_t shapes_count);
}

#endif
