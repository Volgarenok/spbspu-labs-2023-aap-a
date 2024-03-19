#include "square.hpp"
#include <stdexcept>

sakovskaia::Square::Square(const point_t ll, double length):
  ll_(ll),
  length_(length)
{
  if (length <= 0)
  {
    throw std::invalid_argument("Invalid arguments for square");
  }
}

double sakovskaia::Square::getArea() const
{
  return length_ * length_;
}

sakovskaia::rectangle_t
sakovskaia::Square::getFrameRect() const
{
  point_t s_center = {ll_.x + (length_ / 2.0), ll_.y + (length_ / 2.0)};
  return rectangle_t{length_, length_, s_center};
}

void sakovskaia::Square::move(const point_t new_center)
{
  point_t center = {ll_.x + (length_ / 2.0), ll_.y + (length_ / 2.0)};
  double dx_ = new_center.x - center.x;
  double dy_ = new_center.y - center.y;
  this->move(dx_,  dy_);
}

void sakovskaia::Square::move(double dx, double dy)
{
  point_t center = {ll_.x + (length_ / 2.0), ll_.y + (length_ / 2.0)};
  center.x += dx;
  center.y += dy;
  point_t * points[] = {&ll_, &center};
  for (size_t i = 0; i < 2; i++)
  {
    points[i]->x += dx;
    points[i]->y += dy;
  }
}

void sakovskaia::Square::scaleShape(double k)
{
  point_t center = {ll_.x + (length_ / 2.0), ll_.y + (length_ / 2.0)};
  point_t center_p = {center.x, center.y};
  point_t new_center = {center_p.x - ll_.x, center_p.y - ll_.y};
  ll_.x = center.x - new_center.x * k;
  ll_.y = center.y - new_center.y * k;
  length_ *= k;
}
