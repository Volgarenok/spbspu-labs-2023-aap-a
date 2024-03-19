#include "circle.hpp"
#include <stdexcept>
#include <cmath>

petuhov::Circle::Circle(const petuhov::point_t &center, double radius):
  center_(center),
  radius_(radius)
{
  if (radius_ < 0)
  {
    throw std::invalid_argument("Invalid radius");
  }
}

double petuhov::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

petuhov::rectangle_t petuhov::Circle::getFrameRect() const
{
  return {center_, 2 * radius_, 2 * radius_};
}

void petuhov::Circle::move(const petuhov::point_t &pos)
{
  center_ = pos;
}

void petuhov::Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void petuhov::Circle::scale(double factor)
{
  if (factor < 0)
  {
    throw std::invalid_argument("Invalid factor");
  }
  radius_ *= factor;
}
