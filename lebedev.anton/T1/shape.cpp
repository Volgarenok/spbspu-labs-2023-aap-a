#include "shape.hpp"
#include <stdexcept>

void lebedev::Shape::scale(double ratio)
{
  if (ratio <= 0.0)
  {
    throw std::invalid_argument("Error: invalid argument for the Scale");
  }
  doScale(ratio);
}
