#ifndef INPUTSHAPES_HPP
#define INPUTSHAPES_HPP
#include "shape.hpp"
#include <cstddef> 

namespace shabalin
{
  void creatingPoints(const size_t numberOfPoints, double *coords, point_t *points);
  Shape* inputOfRectangle(const char *);
}

#endif
