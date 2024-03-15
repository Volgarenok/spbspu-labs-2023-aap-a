#include "shape.hpp"
#include <stdexcept>

void zaitsev::Shape::scale(double factor)
{
  if (factor <= 0)
  {
    throw std::invalid_argument("Scale factor must be positive");
  }
  unsafeScale(factor);
}
