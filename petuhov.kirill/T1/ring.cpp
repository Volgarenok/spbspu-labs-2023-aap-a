#include "ring.hpp"
#include <stdexcept>
#include <cmath>

petuhov::Ring::Ring(const point_t &center, double outer_radius, double inner_radius):
  center_(center),
  outer_radius_(outer_radius),
  inner_radius_(inner_radius)
{
  if (outer_radius <= inner_radius)
  {
    throw std::invalid_argument("Outer radius must be greater than inner radius.");
  }
}

double petuhov::Ring::getArea() const
{
  return static_cast<double>(M_PI * (outer_radius_ * outer_radius_ - inner_radius_ * inner_radius_));
}

petuhov::rectangle_t petuhov::Ring::getFrameRect() const
{
  double diameter = outer_radius_ * 2;
  return {{center_.x, center_.y}, diameter, diameter};
}

void petuhov::Ring::move(const point_t &newPos)
{
  center_ = newPos;
}

void petuhov::Ring::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void petuhov::Ring::scale(const petuhov::point_t &scale_center, double factor)
{
  if (factor <= 0)
  {
    throw std::invalid_argument("Scale factor must be positive.");
  }

  double dx = center_.x - scale_center_x;
  double dy = center_.y - scale_center_y;

  outer_radius_ *= factor;
  inner_radius_ *= factor;

  center_.x = scale_center_x + dx * factor;
  center_.y = scale_center_y + dy * factor;
}
