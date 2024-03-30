#include "rectangle.hpp"
#include <stdexcept>

lopatina::Rectangle::Rectangle(point_t low_left, point_t up_right):
  left_corner_(low_left),
  right_corner_(up_right)
{
  if ((low_left.x >= up_right.x) || (low_left.y >= up_right.y))
  {
    throw std::invalid_argument("Figure has wrong parameter\n");
  }
}

double lopatina::Rectangle::getArea() const
{
  rectangle_t frameRect = getFrameRect();
  return frameRect.height * frameRect.width;
}

lopatina::rectangle_t lopatina::Rectangle::getFrameRect() const
{
  double height = right_corner_.y - left_corner_.y;
  double width = right_corner_.x - left_corner_.x;
  point_t pos = {(left_corner_.x + right_corner_.x) / 2.0, (left_corner_.y + right_corner_.y) / 2.0};
  rectangle_t newRect{height, width, pos};
  return newRect;
}

void lopatina::Rectangle::move(point_t new_pos)
{
  point_t pos = getFrameRect().pos;
  double dx = new_pos.x - pos.x;
  double dy = new_pos.y - pos.y;
  move(dx, dy);
}

void lopatina::Rectangle::move(double dx, double dy)
{
  left_corner_.x += dx;
  left_corner_.y += dy;
  right_corner_.x += dx;
  right_corner_.y += dy;
}

void lopatina::Rectangle::scale(double k)
{
  if (k <= 0.0)
  {
    throw std::invalid_argument("Incorrect scale index\n");
  }
  point_t pos = getFrameRect().pos;
  left_corner_.x = pos.x + (left_corner_.x - pos.x) * k;
  left_corner_.y = pos.y + (left_corner_.y - pos.y) * k ;
  right_corner_.x = pos.x + (right_corner_.x - pos.x) * k;
  right_corner_.y = pos.y + (right_corner_.y - pos.y) * k;
}
