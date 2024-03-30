#ifndef DEL_OUT_FUNCTIONS_HPP
#define DEL_OUT_FUNCTIONS_HPP

#include <iostream>
#include "shape.hpp"
#include "base-types.hpp"
namespace lopatina
{
  void outputResult(std::ostream & output, const Shape * const * array, size_t counter);
  void deleteArray(Shape ** array, size_t counter);
}

#endif
