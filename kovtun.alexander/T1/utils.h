#ifndef UTILS_H
#define UTILS_H

#include <iostream>

#include "shape.h"
#include "rectangle.h"

namespace kovtun
{
  size_t parseShapes(std::istream & in, Shape ** shapes);
  void isotropicScale(Shape * shape, const point_t & center, double ratio);
}

#endif

