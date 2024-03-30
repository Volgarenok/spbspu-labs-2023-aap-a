#ifndef SHAPEOUTPUT_HPP
#define SHAPEOUTPUT_HPP

#include <ostream>
#include <cstddef>

#include "shape.hpp"
#include "base-types.hpp"

namespace gladyshev
{
  std::ostream& outData(std::ostream& out, const Shape * const * shapes, size_t counter);
}

#endif
