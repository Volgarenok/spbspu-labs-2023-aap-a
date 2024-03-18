#ifndef DISPLAYOUTPUT_HPP
#define DISPLAYOUTPUT_HPP

#include <ostream>
#include "shape.hpp"

namespace marishin
{
  void outputShapesInfo(std::ostream& out, const Shape* const* shapes, size_t& shapeCount);
}

#endif
