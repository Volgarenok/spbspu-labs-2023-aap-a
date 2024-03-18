#ifndef CREATE_SHAPE_HPP
#define CREATE_SHAPE_HPP

#include <cstddef>
#include <string>
#include "shape.hpp"

namespace erohin
{
  Shape* createShape(const std::string name, const double* par, size_t par_size);
  Shape* createRectangle(const double* par, size_t par_size);
  Shape* createTriangle(const double* par, size_t par_size);
  Shape* createComplexquad(const double* par, size_t par_size);
  Shape* createDiamond(const double* par, size_t par_size);
  void inputScaleParameteres(const double* par, size_t par_size, point_t& pos, double& ratio);
}

#endif
