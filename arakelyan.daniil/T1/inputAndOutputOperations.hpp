#ifndef INPUT_HPP
#define INPUT_HPP
#include <iostream>

#include "base-types.hpp"
#include "shape.hpp"

namespace arakelyan
{
  void inputScaleParam(const char *string, point_t &point, double &k);
  void shapeOutput(std::ostream &output, const Shape *const *shapes, size_t shapesCount);
}
#endif
