#include "ellipse.hpp"
#include <math.h>
#include <stdexcept>
#define _USE_MATH_DEFINES

novokhatskiy::Ellipse::Ellipse(const point_t &center, double vert, double horizon)
{
  if ((vert < 0.0) && (horizon < 0.0))
  {
    throw std::invalid_argument("Ellipse radiuses are wrong\n");
  }
  center_ = center;
  vert_ = vert;
  horizon_ = horizon;
}

double novokhatskiy::Ellipse::getArea() const
{
  return M_PI * vert_ * horizon_;
}

rectangle_t novokhatskiy::Ellipse::getFrameRect() const
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
  if (ratio < 0.0)
  {
    throw std::invalid_argument("The ratio can't be negative\n");
  }
  vert_ *= ratio;
  horizon_ *= ratio;
}
