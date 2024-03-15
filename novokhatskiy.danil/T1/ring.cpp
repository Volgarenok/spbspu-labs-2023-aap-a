#include "ring.hpp"
#include <stdexcept>
#include <algorithm>

novokhatskiy::Ring::Ring(const point_t &center, double outerRadius, double innerRadius):
  center_(center),
  innerRadius_(innerRadius),
  outerRadius_(outerRadius)
{
  if ((innerRadius <= 0.0) || (outerRadius <= 0.0) || (innerRadius >= outerRadius))
  {
    throw std::invalid_argument("Ring radiuses are wrong");
  }
}
double novokhatskiy::Ring::getArea() const
{
  const double PI = 3.1415926535;
  return (PI * outerRadius_ * outerRadius_) - (PI * innerRadius_ * innerRadius_);
}
novokhatskiy::rectangle_t novokhatskiy::Ring::getFrameRect() const
{
  return {2 * outerRadius_, 2 * outerRadius_, center_};
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
  innerRadius_ *= ratio;
  outerRadius_ *= ratio;
}
