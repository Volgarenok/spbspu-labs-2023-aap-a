#include "shape.hpp"
#include <stdexcept>
void shabalin::Shape::unsafeScale(const double ratio)
{
  if (ratio < 0.0)
  {
    throw std::logic_error("Ratio can't be less than 0");
  }
  unsafeScale(ratio);
}