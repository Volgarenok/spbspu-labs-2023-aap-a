#ifndef ISOSCALE_HPP
#define ISOSCALE_HPP

#include "compositeShape.hpp"

namespace isaychev
{
  void isoscale(const double * scaleParams, CompositeShape & cShape);
  void isoscaleFigure(const point_t & center, double coeff, Shape & figure);
}

#endif
