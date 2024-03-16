#ifndef INPUTSHAPES_HPP
#define INPUTSHAPES_HPP
#include "shape.hpp"
#include <cstddef>
#include "rectangle.hpp"
#include "Triangle.hpp"
#include "square.hpp"
#include "parallelogram.hpp"

namespace shabalin
{
  /*
  void creatingPoints(const size_t numberOfPoints, double *coords, point_t *points);
  Shape *inputOfRectangle(const char *);
  //void shabalin::makeShapesClear(Shape **shapes, size_t count);
  Shape *inputOfTriangle(const char str[])
  void clearingShapes(Shape **shapes, size_t count);
  void inputRectangle(std::istream &input, Shape **shapes, size_t &count);
  void outputFrameRec(std::ostream &out, const Shape *shape);
  void inputSquare(std::istream &input, Shape **shapes, size_t &count);
  void inputDiamond(std::istream &input, Shape **shapes, size_t &count);
  void inputParallelogram(std::istream &input, Shape **shapes, size_t &count);
  Shape **inputShapes(std::istream &input, size_t &count);
  void outputShapes(std::ostream &out, const Shape *const *shapes, size_t count);
  */
  void readPoints(std::istream &input, double *points, size_t count);
  void readOfRectangle(std::istream &input, Shape **Shapes, size_t &countOfShape);
  void readOfTriangle(std::istream &input, Shape **Shapes, size_t &countOfShape);
  void readOfSquare(std::istream &input, Shape **Shapes, size_t &countOfShape);
  void readOfParallelogram(std::istream &input, Shape **Shapes, size_t &countOfShape);
  void readOfShapes(std::istream &input, Shape **Shapes, size_t &countOfShape, const std::string &name);
  void cleanOfShapes(Shape **Shapes, size_t &countOfShape);
}

#endif
