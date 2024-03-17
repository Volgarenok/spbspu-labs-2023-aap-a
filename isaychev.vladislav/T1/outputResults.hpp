#ifndef OUTPUTRESULTS_HPP
#define OUTPUTRESULTS_HPP

#include <cstddef>
#include <iosfwd>
#include "shape.hpp"
#include "compositeShape.hpp"

namespace isaychev
{
  void outputResults(std::ostream & out, const CompositeShape & cShape);
}

#endif
