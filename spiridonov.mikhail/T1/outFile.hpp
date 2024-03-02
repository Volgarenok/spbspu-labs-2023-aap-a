#ifndef OUT_FILE_HPP
#define OUT_FILE_HPP
#include <ostream>
#include "compositeShape.hpp"

namespace spiridonov
{
  void outSh(std::ostream& out, const CompositeShape& shps, bool useGlCen, const double k, const double cenX, const double cenY);
}

#endif
