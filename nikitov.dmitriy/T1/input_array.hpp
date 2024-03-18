#ifndef INPUT_ARRAY_HPP
#define INPUT_ARRAY_HPP

#include <iostream>
#include <string>
#include "shape.hpp"
#include "composite_shape.hpp"

namespace nikitov
{
  Shape* insertRectangle(std::string line);

  Shape* insertDiamond(std::string line);

  Shape* insertRegular(std::string line);

  void inputArray(CompositeShape& composition, std::string& line, std::istream& input);
}
#endif
