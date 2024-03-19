#include "square.hpp"

sakovskaia::Square::Square(const point_t ll, double length):
  ll_(ll),
  length_(length)
{}

double sakovskaia::Square::getArea() const
{
  return length_ * length_;
}

sakovskaia::rectangle_t
sakovskaia::Square::getFrameRect() const
{
  point_t position = {ll_.x + (length_ / 2.0), ll_.y + (length_ / 2.0)};
  return rectangle_t{length_, length_, position};
}
