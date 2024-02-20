#ifndef OUT_FILE_HPP
#define OUT_FILE_HPP
#include <ostream>
#include "compositeShape.hpp"

namespace spiridonov
{
  void setCenter(double centerX, double centerY);
  void outputShapes(std::ostream& out, const CompositeShape& shapes, bool useGlobalCenter);
}

#endif
