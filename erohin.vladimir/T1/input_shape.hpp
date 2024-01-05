#ifndef IOSHAPE_HPP
#define IOSHAPE_HPP

#include "base-types.hpp"
#include "shape.hpp"
#include <iosfwd>

namespace erohin
{
  Shape** inputShape(std::istream& input, Shape** shape, size_t& size, point_t& pos, double& ratio);
  Shape** resize(Shape** str, size_t size, size_t shift);
  bool isNullFrameRect(rectangle_t frameRect);
}

#endif
