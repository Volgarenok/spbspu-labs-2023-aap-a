#ifndef SCALEOPERATIONS_HPP
#define SCALEOPERATIONS_HPP
#include <iostream>
#include <cstddef>

#include "base-types.hpp"
#include "shape.hpp"

namespace arakelyan
{
  void scaleFunction(arakelyan::Shape **shapes, size_t shapesCount, point_t scalePoint, double scaleK, std::ostream &out);
  void isoScale(Shape *shapeObj, point_t scalePoint, double scaleK);
}
#endif
