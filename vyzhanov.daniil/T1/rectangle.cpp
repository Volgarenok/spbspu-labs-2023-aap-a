#include "rectangle.hpp"

#include <stdexcept>

vyzhanov::Rectangle::Rectangle(const point_t& leftCorner, const point_t& rightCorner):
  leftCorner_(leftCorner),
  rightCorner_(rightCorner)
{
  if (leftCorner_.x >= rightCorner_.x || leftCorner_.y >= rightCorner_.y)
  {
    throw std::invalid_argument("invalid rectangle source");
  }
}

double vyzhanov::Rectangle::getArea() const
{
  rectangle_t rect = getFrameRect();
  return rect.width * rect.height;
}

vyzhanov::rectangle_t vyzhanov::Rectangle::getFrameRect() const
{
  double width = rightCorner_.x - leftCorner_.x;
  double height = rightCorner_.y - leftCorner_.y;
  point_t pos = { leftCorner_.x + width / 2.0, leftCorner_.y + height / 2.0 };
  return { width, height, pos };
}

void vyzhanov::Rectangle::move(const point_t& point)
{
  rectangle_t rect = getFrameRect();
  move(point.x - rect.pos.x, point.y - rect.pos.y);
}

void vyzhanov::Rectangle::move(const double dx, const double dy)
{
  leftCorner_.x += dx;
  leftCorner_.y += dy;
  rightCorner_.x += dx;
  rightCorner_.y += dy;
}

void vyzhanov::Rectangle::scale(const double ratio)
{
  rectangle_t rect = getFrameRect();
  leftCorner_.x = rect.pos.x - (rect.pos.x - leftCorner_.x) * ratio;
  leftCorner_.y = rect.pos.y - (rect.pos.y - leftCorner_.y) * ratio;
  rightCorner_.x = rect.pos.x + (rightCorner_.x - rect.pos.x) * ratio;
  rightCorner_.y = rect.pos.y + (rightCorner_.y - rect.pos.y) * ratio;
}
