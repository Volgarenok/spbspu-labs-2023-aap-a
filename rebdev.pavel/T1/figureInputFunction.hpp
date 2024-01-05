#ifndef FIGUREINPUTFUNCTION_HPP
#define FIGUREINPUTFUNCTION_HPP
#include <iostream>
#include <cstddef>
#include "base-types.hpp"
#include "shape.hpp"
#include "concave.hpp"
#include "polygon.hpp"
#include "rectangle.hpp"

namespace rebdev
{
  bool isRectangle(point_t * pointsArr);
  bool isConcave(point_t * pointsArr);
  bool isPolygon(const point_t * pointsArr, const size_t size);
  bool isTriangle(const point_t f, const point_t s, const point_t t);

  bool isNameCorrect(std::istream input, const int nameSize, const char * name);
  bool ipnutVertexs(std::istream input, point_t * vertexsArr, size_t & numOfVertexs);
  bool figureIsCorrect(const point_t * vertexsArr, const size_t numOfVertexs, const int figureNumber);

  Shape * newFigure(const point_t * vertexsArr, const size_t numOfVertexs, const int figureNumber);
  void newArrOfVertexs(point_t * vertexsArr, const size_t numOfVertexs);
}
#endif
