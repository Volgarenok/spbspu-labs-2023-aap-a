#ifndef INPUT_SHAPES_HPP
#define INPUT_SHAPES_HPP

#include <iostream>
#include <cstddef>
#include "shape.hpp"

namespace stepanov
{
  void inputArrayShape(std::istream& input, size_t const size, double * arguments);
  void inputRectangle(std::istream& input, Shape** shapes, size_t& size_shapes);
  void inputCircle(std::istream& input, Shape** shapes, size_t& size_shapes);
  void inputEllipse(std::istream& input, Shape** shapes, size_t& size_shapes);
  void inputSquare(std::istream& input, Shape** shapes, size_t& size_shapes);
  void deleteShapes(Shape** shapes, size_t size_shapes);
  Shape** inputShapes(std::istream& input, size_t& size_shapes);
  void outputShapes(std::ostream& output, const Shape * const * shapes,size_t size_shapes);
}
#endif
