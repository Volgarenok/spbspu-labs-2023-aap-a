#include "ring.hpp"
#include <stdexcept>
#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>

novokhatskiy::Ring::Ring(const point_t &center, double radius1, double radius2)
{
  if ((radius1 < 0.0) && (radius2 < 0.0))
  {
    throw std::invalid_argument("Ring radiuses are wrong\n");
  }
  center_ = center;
  if (radius1 > radius2)
  {
    std::swap(radius1, radius2);
  }
  radius1_ = radius1;
  radius2_ = radius2;
}
double novokhatskiy::Ring::getArea() const
{
  return (M_PI * radius2_ * radius2_) - (M_PI * radius1_ * radius1_);
}
rectangle_t novokhatskiy::Ring::getFrameRect() const
{
  return {2 * radius2_, 2 * radius2_, center_};
}
void novokhatskiy::Ring::move(const point_t &point)
{
  center_ = point;
}
void novokhatskiy::Ring::move(double x, double y)
{
  center_ = {center_.x + x, center_.y + y};
}
void novokhatskiy::Ring::scale(double ratio)
{
  if (ratio < 0.0)
  {
    std::invalid_argument("The ratio can't be negative\n");
  }
  radius1_ *= ratio;
  radius2_ *= ratio;
}
