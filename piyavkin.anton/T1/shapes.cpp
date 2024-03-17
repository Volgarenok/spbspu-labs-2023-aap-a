#include "shape.hpp"
#include <stdexcept>

void piyavkin::Shape::scale(double k)
{
  if (k < 0)
  {
    throw std::logic_error("Сoefficient less than 0");
  }
  unsafeScale(k);
}
