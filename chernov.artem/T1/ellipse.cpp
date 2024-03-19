#include "ellipse.hpp"
#include "base-types.hpp"
#include <stdexcept>

chernov::Ellipse::Ellipse(point_t center, double vertical_radius, double horizontal_radius) :
  center_(center),
  vertical_radius_(vertical_radius),
  horizontal_radius_(horizontal_radius)
{
  if (vertical_radius_ <= 0 || horizontal_radius_ <= 0)
  {
    throw std::invalid_argument("radii are written incorrectly\n");
  }
}


double chernov::Ellipse::getArea() const
{
  double PI = 3.141592653589793;
  return vertical_radius_ * horizontal_radius_ * PI;
}

chernov::rectangle_t chernov::Ellipse::getFrameRect()
{
  return { horizontal_radius_ * 2, vertical_radius_ * 2, center_ };
}

void chernov::Ellipse::move(point_t pos)
{
  center_ = pos;
}

void chernov::Ellipse::move(double moveX, double moveY)
{
  center_.x = moveX;
  center_.y = moveY;
}

void chernov::Ellipse::scale(double multiplier)
{
  if (multiplier <= 0)
  {
    throw std::invalid_argument("Multiplier must be more than 0\n");
  }
  horizontal_radius_ *= multiplier;
  vertical_radius_ *= multiplier;
}

chernov::Shape* chernov::Ellipse::clone() const
{
  return new Ellipse(center_, vertical_radius_, horizontal_radius_);
}
