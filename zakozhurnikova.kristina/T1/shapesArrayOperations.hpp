#ifndef SHAPES_ARRAY_OPERATIONS_HPP
#define SHAPES_ARRAY_OPERATIONS_HPP
#include <iosfwd>
#include <cstddef>
#include "shape.hpp"

namespace zakozhurnikova
{
  void freeShapesArray(Shape** shapes, size_t size);
  Shape* readShape(const char* string);
  void readScale(const char* string, zakozhurnikova::point_t& scalePoint, double& k);
  void inputShapesArray(std::istream& in, Shape** shapes, size_t& size, point_t& scalePoint, double& k);
}
#endif
