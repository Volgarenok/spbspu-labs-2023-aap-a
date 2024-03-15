#ifndef OUT_FILE_HPP
#define OUT_FILE_HPP
#include <ostream>
#include "compositeShape.hpp"

namespace spiridonov
{
  void outShapes(std::ostream& out, const CompositeShape& shapes, bool useGlCen, double k, double cenX, double cenY);
}

#endif
