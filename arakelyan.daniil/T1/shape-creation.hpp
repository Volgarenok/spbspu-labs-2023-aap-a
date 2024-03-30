#ifndef SHAPE_CREATION_HPP
#define SHAPE_CREATION_HPP
#include <cstddef>

#include "base-types.hpp"
#include "shape.hpp"

namespace arakelyan
{
  void defineAndCreateShape(Shape **myShapes, size_t shapesCount, const char *sting);
  Shape * createPar(const char *string);
  Shape * createRect(const char *string);
  Shape * createDiam(const char *string);
  void extractDataForShape(const char *string, double *coordStorage, size_t pointsCount, size_t wordLen);
  void freeMem(Shape **myShapes, size_t shapesCount);
  void scaleForParAndDiam(rectangle_t dataOfFameRect, point_t &p1_, point_t &p2_, point_t &p3_, const double k);
}
#endif
