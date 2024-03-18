#ifndef INPUTSHAPES_HPP
#define INPUTSHAPES_HPP

#include <iostream>
#include <string>
#include "shape.hpp"

namespace chistyakov
{
  void inputShapes(std::istream & input, Shape ** array, double * scaleInfo, size_t & size, bool & isBadShape);
  void inputDouble(std::istream & input, size_t numOfPoints, double * pointsArray);
  void inputRectangle(double * cords, Shape ** array);
  void inputSquare(double * cords, Shape ** array);
  void inputComplexquad(double * cords, Shape ** array);
  void parseInfoScale(double * cords, double * scaleInfo);
  void writeShapeInArray(Shape * shape, Shape ** array, size_t size);
  void freeArray(Shape ** array, size_t size);
}

#endif
