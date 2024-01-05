#ifndef INPUT_SHAPES_HPP
#define INPUT_SHAPES_HPP
#include "shape.hpp"
#include <iostream>

namespace baranov
{
  baranov::Shape ** expandShapes(Shape ** shapes, size_t size, size_t newSize);
  baranov::Shape * parseRectangle(const char * string);
  baranov::Shape * parseRing(const char * string);
  baranov::Shape * parseEllipse(const char * string);
  void parseScale(const char * string, point_t & scalePoint, size_t & scaleRatio);
  baranov::Shape * parseShape(char * string);
  void freeShapes(Shape ** shapes, size_t size);
  baranov::Shape ** inputShapes(std::istream & input, size_t & size, point_t & scalePoint, size_t & scaleRatio);
}

#endif
