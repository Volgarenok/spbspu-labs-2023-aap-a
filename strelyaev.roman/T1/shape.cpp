#include "shape.hpp"
#include <stdexcept>

void strelyaev::Shape::scale(double k)
{
  if (k < 0)
  {
    throw std::logic_error("Invalid SCALE argument.");
  }
  unsafeScale(k);
}
