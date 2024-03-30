#include "shape.hpp"
#include <stdexcept>

void grechishnikov::Shape::scale(double rate)
{
  if (rate <= 0)
  {
    throw std::logic_error("Incorrect scale ratio");
  }
  unsafeScale(rate);
}
