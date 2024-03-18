#ifndef OUTPUTSHAPES_HPP
#define OUTPUTSHAPES_HPP

#include <iostream>
#include "shape.hpp"
#include "base-types.hpp"

namespace rebdev
{
  void printShapes(const Shape * const * shapes, size_t numOfShapes, std::ostream & out);
}

#endif
