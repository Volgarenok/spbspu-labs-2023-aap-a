#include "shape.hpp"
#include <stdexcept>

void marishin::Shape::scale(double factor)
{
  if (factor <= 0.0)
  {
    throw std::invalid_argument("Invalid scale coefficient. Must be non-negative.");
  }
  unsafeScale(factor);
}
