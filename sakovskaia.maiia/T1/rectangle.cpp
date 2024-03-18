#include "rectangle.hpp"

sakovskaia::Rectangle::Rectangle(point_t ll_, point_t ur_):
  ll_(ll_),
  ur_(ur_)
{}

double sakovskaia::Rectangle::getArea() const
{
  double height = ur_.y - ll_.y;
  double width = ur_.x - ll.x;
  return height * width;
}
