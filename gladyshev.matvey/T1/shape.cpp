#include "shape.hpp"

#include <stdexcept>

void gladyshev::Shape::scale(double factor)
{
  if (factor <= 0)
  {
    throw std::underflow_error("factor mast be positive");
  }
  unsafeScale(factor);
}
