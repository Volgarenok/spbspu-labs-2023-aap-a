#include "shape.hpp"
#include <stdexcept>

void erohin::Shape::scale(double ratio)
{
  if (ratio <= 0.0)
  {
    throw std::invalid_argument("Wrong figure creation");
  }
  unsafeScale(ratio);
}
