#ifndef IOSHAPE_HPP
#define IOSHAPE_HPP

#include <iosfwd>
#include "base-types.hpp"
#include "composite_shape.hpp"

namespace erohin
{
  void inputShape(CompositeShape& result, std::istream& input, point_t& pos, double& ratio);
}

#endif
