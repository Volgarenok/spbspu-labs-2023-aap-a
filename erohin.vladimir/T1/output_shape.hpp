#ifndef OUTPUT_SHAPE_HPP
#define OUTPUT_SHAPE_HPP

#include <iosfwd>
#include "composite_shape.hpp"

namespace erohin
{
  void outputShape(std::ostream& output, const CompositeShape& composite_shape);
}

#endif
