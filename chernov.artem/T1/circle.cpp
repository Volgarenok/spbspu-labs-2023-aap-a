#include "circle.hpp"
#include "base-types.hpp"
#include <stdexcept>

chernov::Circle::Circle(point_t center, double radius) :
  center_(center),
  radius_(radius)
{
  if (radius <= 0)
  {
    throw std::invalid_argument("radius is a positive number!\n");
  }
}
double chernov::Circle::getArea() const
{
  double PI = 3.141592653589793;
  return radius_ * radius_ * PI;
}
chernov::rectangle_t chernov::Circle::getFrameRect()
{
  return {radius_ * 2, radius_ * 2, center_};
}
void chernov::Circle::move(point_t pos)
{
  center_ = pos;
}

void chernov::Circle::move(double moveX, double moveY)
{
  center_.x = moveX;
  center_.y = moveY;
}

void chernov::Circle::scale(double multiplier)
{
  if (multiplier <= 0)
  {
    throw std::invalid_argument("Multiplier must be more than 0\n");
  }
  radius_ *= multiplier;
}

chernov::Shape* chernov::Circle::clone() const
{
  return new Circle(center_, radius_);
}
