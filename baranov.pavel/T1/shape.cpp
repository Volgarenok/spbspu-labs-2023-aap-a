#include "shape.hpp"
#include <stdexcept>

void baranov::Shape::scale(const double ratio)
{
  if (ratio <= 0)
  {
    throw std::invalid_argument("Invalid scale ratio");
  }
  doScale(ratio);
}

