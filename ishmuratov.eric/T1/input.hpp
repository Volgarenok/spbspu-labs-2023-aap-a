#ifndef INPUT_HPP
#define INPUT_HPP

#include <stdexcept>
#include <string>
#include <istream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "diamond.hpp"
#include "concave.hpp"
#include "data_process.hpp"

namespace ishmuratov
{
  void inputShape(std::istream & input, Shape ** shapeArray, size_t & count);
  void freeMemory(Shape ** shapeArray, size_t & count);
  void inputPoint(std::istream & input, double * pointArray, size_t count);
  Shape * initShape(const std::string & shapeName, std::istream & input);
}

#endif
