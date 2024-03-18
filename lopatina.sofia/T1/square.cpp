#include "square.hpp"
#include <stdexcept>

lopatina::Square::Square(point_t left_corner, double side):
  left_corner_(left_corner),
  side_(side)
{
  if (side <= 0.0)
  {
    throw std::invalid_argument("Figure has wrong parameter\n");
  }
}

double lopatina::Square::getArea() const
{
  return side_ * side_;
}

lopatina::rectangle_t lopatina::Square::getFrameRect() const
{
  point_t pos = {left_corner_.x + (side_ / 2.0), left_corner_.y + (side_ / 2.0)};
  rectangle_t newRect{side_, side_, pos};
  return newRect;
}

void lopatina::Square::move(point_t new_pos)
{
  point_t pos = getFrameRect().pos;
  double dx = new_pos.x - pos.x;
  double dy = new_pos.y - pos.y;
  move(dx, dy);
}

void lopatina::Square::move(double dx, double dy)
{
  left_corner_.x += dx;
  left_corner_.y += dy;
}

void lopatina::Square::scale(double k)
{
  if (k <= 0.0)
  {
    throw std::invalid_argument("Incorrect scale index\n");
  }
  point_t pos = getFrameRect().pos;
  left_corner_.x = pos.x + (left_corner_.x - pos.x) * k;
  left_corner_.y = pos.y + (left_corner_.y - pos.y) * k;
  side_ = side_ * k;
}
