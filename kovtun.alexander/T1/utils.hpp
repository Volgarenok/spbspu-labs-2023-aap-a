#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>

#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "ellipse.hpp"
#include "ring.hpp"

namespace kovtun
{
  size_t parseShapes(std::istream & in, Shape ** shapes);
  void showResult(std::ostream & out, Shape ** shapes, size_t shapesCount);
  void isotropicScale(Shape * shape, const point_t & center, double ratio);
  void removeShapes(kovtun::Shape ** shapes, size_t shapesCount);
}

#endif

