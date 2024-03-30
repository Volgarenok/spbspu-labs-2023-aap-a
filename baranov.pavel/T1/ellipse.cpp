#include "ellipse.hpp"
#include <stdexcept>

baranov::Ellipse::Ellipse(const point_t & center, const double yRadius, const double xRadius):
  center_(center),
  yRadius_(yRadius),
  xRadius_(xRadius)
{
  if (xRadius <= 0 || yRadius <= 0)
  {
    throw std::invalid_argument("Invalid ellipse parameters");
  }
}

double baranov::Ellipse::getArea() const
{
  const double pi = 3.141593;
  return pi * xRadius_ * yRadius_;
}

baranov::rectangle_t baranov::Ellipse::getFrameRect() const
{
  double height = yRadius_ * 2;
  double width = xRadius_ * 2;
  point_t pos = center_;
  return { width, height, pos };
}

void baranov::Ellipse::move(const point_t & destPos)
{
  center_ = destPos;
}

void baranov::Ellipse::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void baranov::Ellipse::doScale(const double ratio)
{
  xRadius_ *= ratio;
  yRadius_ *= ratio;
}

