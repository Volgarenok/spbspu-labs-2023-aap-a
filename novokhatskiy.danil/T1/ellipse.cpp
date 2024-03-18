#include "ellipse.hpp"
#include <stdexcept>

novokhatskiy::Ellipse::Ellipse(const point_t &center, double vert, double horizon):
  center_(center),
  vert_(vert),
  horizon_(horizon)
{
  if ((vert <= 0.0) || (horizon <= 0.0))
  {
    throw std::invalid_argument("Ellipse radiuses are wrong");
  }
}

double novokhatskiy::Ellipse::getArea() const
{
  const double PI = 3.1415926535;
  return PI * vert_ * horizon_;
}

novokhatskiy::rectangle_t novokhatskiy::Ellipse::getFrameRect() const
{
  return {2 * horizon_, 2 * vert_, center_};
}

void novokhatskiy::Ellipse::move(const point_t &point)
{
  center_ = point;
}

void novokhatskiy::Ellipse::move(double x, double y)
{
  center_ = {center_.x + x, center_.y + y};
}

void novokhatskiy::Ellipse::scale(double ratio)
{
  vert_ *= ratio;
  horizon_ *= ratio;
}
