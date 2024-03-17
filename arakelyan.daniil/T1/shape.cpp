#include "shape.hpp"

#include <stdexcept>

void arakelyan::Shape::scale(const double k)
{
  if (k < 0.0)
  {
    throw std::logic_error("K of scale cannot be less than zero!");
  }
  scaleShape(k);
}
