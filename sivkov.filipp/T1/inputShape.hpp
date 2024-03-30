#ifndef INPUTSHAPE_HPP
#define INPUTSHAPE_HPP
#include <iostream>
#include "shape.hpp"

namespace sivkov
{
  void inputRectangle(std::istream& in, Shape** shapes, size_t count);
  void inputConcave(std::istream& in, Shape** shapes, size_t count);
  void inputComplexQuad(std::istream& in, Shape** shapes, size_t count);
  Shape** inputShapes(std::istream& input, size_t& count);
}

#endif

