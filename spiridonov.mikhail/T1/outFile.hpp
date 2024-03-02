#ifndef OUT_FILE_HPP
#define OUT_FILE_HPP
#include <ostream>
#include "compositeShape.hpp"

namespace spiridonov
{
  void outputShapes(std::ostream& out, const CompositeShape& shapes, bool useGlCent, const double k, const double cenX, const double cenY);
}

#endif
