#ifndef PARAMETERS_LOGIC_HPP
#define PARAMETERS_LOGIC_HPP

#include <cstddef>
#include "base-types.hpp"

namespace grechishnikov
{
  const double* parseValues(const char* str, size_t& size);
  const point_t* makePairs(const double* values, size_t size);
}

#endif

