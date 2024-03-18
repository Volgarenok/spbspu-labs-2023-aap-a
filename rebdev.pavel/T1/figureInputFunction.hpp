#ifndef FIGUREINPUTFUNCTION_HPP
#define FIGUREINPUTFUNCTION_HPP
#include <iostream>
#include <cstddef>
#include <string>
#include "base-types.hpp"
#include "shape.hpp"

namespace rebdev
{
  Shape * newFigure(std::istream & input, const std::string & name);
  point_t * inputPoints(std::istream & input, size_t & numOfPoints);
}
#endif
