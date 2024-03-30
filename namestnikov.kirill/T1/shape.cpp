#include "shape.hpp"
#include <stdexcept>

void namestnikov::Shape::scale(const double coefficient)
{
  if (coefficient <= 0.0)
  {
    throw std::invalid_argument("Scaling coefficient must be greater than zero");
  }
  unsafeScale(coefficient);
}
