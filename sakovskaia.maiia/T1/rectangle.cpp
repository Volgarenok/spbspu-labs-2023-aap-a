#include "rectangle.hpp"
#include <cmath>

sakovskaia::Rectangle::Rectangle(point_t ll_, point_t ur_):
  ll_(ll_),
  ur_(ur_)
{}

double sakovskaia::Rectangle::getArea() const
{
  double height = ur_.y - ll_.y;
  double width = ur_.x - ll_.x;
  return height * width;
}

sakovskaia::rectangle_t
sakovskaia::Rectangle::getFrameRect() const
{
  double height = std::abs(ur_.y - ll_.y);
  double width = std::abs(ur_.x - ll_.x);
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

void sakovskaia::Rectangle::move(double dx, double dy)
{
  point_t center{((ur_.x + ll_.x) / 2), ((ur_.y + ll_.y) / 2)};
  center.x += dx;
  center.y += dy;
  point_t * points[] = {&ll_, &ur_};
  for (size_t i = 0; i < 2; i++)
  {
    points[i]->x += dx;
    points[i]->y += dy;
  }
}

void sakovskaia::Rectangle::scaleShape(double k)
{
  double height = ur_.y - ll_.y;
  double width = ur_.x - ll_.x;
  double new_height = height * k;
  double new_width = width * k;
  double dx_ = (new_width - width) / 2.0;
  double dy_ = (new_height - height) / 2.0;
  ll_.x -= dx_;
  ll_.y -= dy_;
  ur_.x += dx_;
  ur_.y += dy_;
}
