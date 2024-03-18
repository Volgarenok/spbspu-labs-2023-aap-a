#ifndef INPUTOUTPUTSHAPES_HPP
#define INPUTOUTPUTSHAPES_HPP
#include "shape.hpp"
#include <cstddef>
#include "rectangle.hpp"
#include "Triangle.hpp"
#include "square.hpp"
#include "parallelogram.hpp"

namespace shabalin
{
  void readPoints(std::istream &input, double *points, size_t count);
  void readOfRectangle(std::istream &input, Shape **Shapes, size_t &countOfShape);
  void readOfTriangle(std::istream &input, Shape **Shapes, size_t &countOfShape);
  void readOfSquare(std::istream &input, Shape **Shapes, size_t &countOfShape);
  void readOfParallelogram(std::istream &input, Shape **Shapes, size_t &countOfShape);
  Shape **readOfShapes(std::istream &input, Shape **Shapes, size_t &countOfShape, const std::string &name);
  void cleanOfShapes(Shape **Shapes, size_t &countOfShape);
  void outputOfShapes(std::ostream &output, const Shape **shapes, const size_t &numberOfShapes);

}

#endif
