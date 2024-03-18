#ifndef UTILS_H
#define UTILS_H

#include <iostream>

#include "shape.h"
#include "rectangle.h"

namespace kovtun
{
  size_t parseShapes(std::istream & in, Shape ** shapes);
  void showResult(std::ostream & out, Shape ** shapes, size_t shapesCount);
  void isotropicScale(Shape * shape, const point_t & center, double ratio);
}

#endif

