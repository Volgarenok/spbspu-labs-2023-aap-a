#include "shape.hpp"
#include <stdexcept>

void sakovskaia::Shape::scale(const double k)
{
  if (k < 0)
  {
    throw std::logic_error("Negative scale argument");
  }
  scaleShape(k);
}
