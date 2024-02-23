#include "ring.hpp"

marishin::Ring::Ring(const point_t& center, double outerRadius, double innerRadius):
  center_(center),
  innerRadius_(innerRadius),
  outerRadius_(outerRadius)
{
  if ((innerRadius <= 0) || (outerRadius <= 0) || (innerRadius >= outerRadius))
  {
    throw std::invalid_argument("Ring radiuses are wrong");
  }
}

double marishin::Ring::getArea() const
{
  const double PI = 3.141592;
  return PI * (outerRadius_ * outerRadius_ - innerRadius_ * innerRadius_);
}

marishin::rectangle_t marishin::Ring::getFrameRect() const
{
  return { center_, outerRadius_ * 2, outerRadius_ * 2 };
}

void marishin::Ring::move(const point_t& newPos)
{
  center_ = newPos;
}

void marishin::Ring::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void marishin::Ring::unsafeScale(double factor)
{
  innerRadius_ *= factor;
  outerRadius_ *= factor;
}
