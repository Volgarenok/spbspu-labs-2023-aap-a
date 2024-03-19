#include "square.hpp"

sakovskaia::Square::Square(const point_t ll, double length):
  ll_(ll),
  length_(length)
{}

double sakovskaia::Square::getArea() const
{
  return length_ * length_;
}
