#include "shape.hpp"
#include <stdexcept>

void zakozhurnikova::Shape::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Scale coefficient should be a positive real number.");
  }
  unsafeScale(k);
}
