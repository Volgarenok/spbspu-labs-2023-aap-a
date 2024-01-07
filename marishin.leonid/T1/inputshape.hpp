#ifndef INPUTSHAPE_HPP
#define INPUTSHAPE_HPP

#include "shape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "ring.hpp"
#include <string>
#include <iostream>

namespace marishin
{
  Shape** inputShape(std::istream& in, size_t& shapeCount);
  void cleanupShapes(Shape** shapes, size_t count);
  Shape* createShape(const std::string& name, double* parameters);
  void skipLine(std::istream& in);
}

#endif
