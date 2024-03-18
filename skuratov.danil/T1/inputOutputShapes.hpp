#ifndef INPUT_OUTPUT_HPP
#define INPUT_OUTPUT_HPP

#include <iostream>
#include <cstddef>

#include "shape.hpp"

namespace skuratov
{
  void clearingShapes(Shape** shapes, size_t count);
  void inputRectangle(std::istream& input, Shape** shapes, size_t& count);
  void outputFrameRec(std::ostream& out, const Shape* shape);
  void inputSquare(std::istream& input, Shape** shapes, size_t& count);
  void inputDiamond(std::istream& input, Shape** shapes, size_t& count);
  void inputParallelogram(std::istream& input, Shape** shapes, size_t& count);
  Shape** inputShapes(std::istream& input, size_t& count);
  void outputShapes(std::ostream& out, const Shape* const* shapes, size_t count);
}

#endif
