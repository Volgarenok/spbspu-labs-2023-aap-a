#ifndef INPUT_SHAPES_HPP
#define INPUT_SHAPES_HPP

#include <cstddef>
#include "shape.hpp"
#include "base-types.hpp"

namespace grechishnikov
{
  Shape* inputShape(const char* str);
  Shape* inputRectangle(const point_t* points, size_t size);
  Shape* inputTriangle(const point_t* points, size_t size);
  Shape* inputPolygon(const point_t* points, size_t size);
  void freeShapes(const Shape* const* shapes, size_t size);
  const char* parseName(const char* str);
}

#endif
