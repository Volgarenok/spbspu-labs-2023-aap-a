#include "shape.hpp"
#include <stdexcept>

void stepanov::Shape::scale(double ratio)
{
  if (ratio <= 0.0)
  {
    throw std::invalid_argument("Error: Wrong argument for scaling");
  }
  doScale(ratio);
}

void stepanov::Shape::unsafeScale(double ratio)
{
  doScale(ratio);
}
