#ifndef SCALE_HPP
#define SCALE_HPP
#include "shape.hpp"
#include <ostream>
namespace sakovskaia
{
  void isoScaleShapes(Shape * shape, point_t scalePoint, double scaleRatio);
  void scaleOp(const char * string, Shape * const * shapes, size_t cnt, std::ostream& output);
  void scaleShapes(Shape * const * shapes, size_t cnt, const double * args, std::ostream& output);
}
#endif
