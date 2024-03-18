#include "rectangle.hpp"
#include <cmath>

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

sakovskaia::rectangle_t
sakovskaia::Rectangle::getFrameRect() const
{
  double height = std::abs(ur_.y - ll_.y);
  double width = std::abs(ur_.x - ll.x);
  point_t center{((ur_.x + ll_.x) / 2), ((ur_.y + ll_.y) / 2)};
  return {width, height, center};
}

void sakoskaia::Rectangle::move(const point_t new_center)
{
  point_t center{((ur_.x + ll_.x) / 2), ((ur_.y + ll_.y) / 2)};
  double dx_ = new_center.x - center.x;
  double dy_ = new_center.y - center.y;
  move(dx_, dy_);
}
