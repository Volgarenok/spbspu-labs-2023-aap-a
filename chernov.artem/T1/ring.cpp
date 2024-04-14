#include "ring.hpp"
#include "base-types.hpp"
#include <stdexcept>

chernov::Ring::Ring(point_t center, double outer_radius, double inner_radius):
  center_(center),
  outer_radius_(outer_radius),
  inner_radius_(inner_radius)
{
  if (outer_radius_ <= 0 || outer_radius_ <= 0 || outer_radius_ <= outer_radius_)
  {
    throw std::invalid_argument("radii are written incorrectly\n");
  }
}


double chernov::Ring::getArea() const
{
  double PI = 3.141592653589793;
  return (outer_radius_ * outer_radius_ * PI) - (inner_radius_ * inner_radius_ * PI);
}

chernov::rectangle_t chernov::Ring::getFrameRect()
{
  return { outer_radius_ * 2, outer_radius_ * 2, center_ };
}

void chernov::Ring::move(point_t pos)
{
  center_ = pos;
}

void chernov::Ring::move(double moveX, double moveY)
{
  center_.x = moveX;
  center_.y = moveY;
}

void chernov::Ring::scale(double multiplier)
{
  if (multiplier <= 0)
  {
    throw std::invalid_argument("Multiplier must be more than 0\n");
  }
  outer_radius_ *= multiplier;
  inner_radius_ *= multiplier;
}

chernov::Shape* chernov::Ring::clone() const
{
  return new Ring(center_, outer_radius_, inner_radius_);
}
