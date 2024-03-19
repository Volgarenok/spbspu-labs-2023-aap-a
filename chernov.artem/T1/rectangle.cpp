#include "rectangle.hpp"
#include "base-types.hpp"
#include <stdexcept>
#include <cmath>

double chernov::Rectangle::getArea() const
{
  return std::abs((left_down_.x - right_high_.x) * (left_down_.y - right_high_.y));
}

chernov::rectangle_t chernov::Rectangle::getFrameRect()
{
  rectangle_t rectangle;
  rectangle.height = right_high_.y - left_down_.y;
  rectangle.width = right_high_.x - left_down_.x;
  rectangle.pos.x = (right_high_.x - left_down_.x) / 2;
  rectangle.pos.y = (right_high_.y - left_down_.y) / 2;
  return rectangle;
}

void chernov::Rectangle::move(point_t pos)
{
  left_down_.x += pos.x;
  left_down_.y += pos.y;
  right_high_.x += pos.x;
  right_high_.y += pos.y;
}

void chernov::Rectangle::move(double moveX, double moveY)
{
  left_down_.x += moveX;
  left_down_.y += moveY;
  right_high_.x += moveX;
  right_high_.y += moveY;
}

void chernov::Rectangle::scale(double multiplier)
{
  if (multiplier <= 0)
  {
    throw std::invalid_argument("Multiplier must be more than 0\n");
  }
  left_down_.x *= multiplier;
  left_down_.y *= multiplier;
  right_high_.x *= multiplier;
  right_high_.y *= multiplier;
}

chernov::Shape* chernov::Rectangle::clone() const
{
  return new chernov::Rectangle(left_down_, right_high_);
}
