#include "rectangle.hpp"
#include <stdexcept>
#include "base-types.hpp"

zaitsev::Rectangle::Rectangle(point_t left_corner, point_t right_corner):
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
  return { width, height, getCenter()};
}

void zaitsev::Rectangle::move(point_t dest_pos)
{
  point_t center = getCenter();
  move(dest_pos.x - center.x, dest_pos.y - center.y);
}

void zaitsev::Rectangle::move(double x_shift, double y_shift)
{
  point_t shift = { x_shift, y_shift };
  left_corner_ += shift;
  right_corner_ += shift;
}

zaitsev::point_t zaitsev::Rectangle::getCenter() const
{
  return (right_corner_ + left_corner_) / 2;
}

void zaitsev::Rectangle::unsafeScale(double factor)
{
  point_t center = getCenter();
  left_corner_ = center + (left_corner_ - center) * factor;
  right_corner_ = center + (right_corner_ - center) * factor;
}

zaitsev::Shape* zaitsev::Rectangle::clone() const
{
  return new Rectangle(*this);
}
