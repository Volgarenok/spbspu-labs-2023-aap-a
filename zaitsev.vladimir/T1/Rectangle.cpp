#include "Rectangle.h"
#include <stdexcept>
#include "base-types.h"


zaitsev::Rectangle::Rectangle(const point_t& left_corner, const point_t& right_corner) :
  left_corner_(left_corner),
  right_corner_(right_corner)
{
  if (left_corner.x > right_corner.x || left_corner.y > right_corner.y)
  {
    throw std::invalid_argument("Invalid order of points");
  }
}

double zaitsev::Rectangle::getArea() const
{
  return (right_corner_.x - left_corner_.x) * (right_corner_.y - left_corner_.y);
}

zaitsev::rectangle_t zaitsev::Rectangle::getFrameRect() const
{
  double width = right_corner_.x - left_corner_.x;
  double height = right_corner_.y - left_corner_.y;
  point_t pos = { left_corner_.x + width / 2, left_corner_.y + height / 2 };
  return { width, height, pos };
}

void zaitsev::Rectangle::move(const point_t& dest_pos)
{
  point_t center = getCenter();
  point_t diff = { dest_pos.x - center.x, dest_pos.y - center.y };
  left_corner_.x += diff.x;
  left_corner_.y += diff.y;
  right_corner_.x += diff.x;
  right_corner_.y += diff.y;
}

void zaitsev::Rectangle::move(double x_shift, double y_shift)
{
  left_corner_.x += x_shift;
  left_corner_.y += y_shift;
  right_corner_.x += x_shift;
  right_corner_.y += y_shift;
}

zaitsev::point_t zaitsev::Rectangle::getCenter() const
{
  double width = right_corner_.x - left_corner_.x;
  double height = right_corner_.y - left_corner_.y;
  return { left_corner_.x + width / 2, left_corner_.y + height / 2 };
}

void zaitsev::Rectangle::scale(double factor)
{
  if (factor <= 0)
  {
    throw std::invalid_argument("Scale factor must be positive");
  }
  point_t center = getCenter();
  left_corner_.x = center.x + (left_corner_.x - center.x) * factor;
  right_corner_.x = center.x + (right_corner_.x - center.x) * factor;
  left_corner_.y = center.y + (left_corner_.y - center.y) * factor;
  right_corner_.y = center.y + (right_corner_.y - center.y) * factor;
}
