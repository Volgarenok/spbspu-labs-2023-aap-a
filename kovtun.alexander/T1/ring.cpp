#include "ring.h"

kovtun::Ring::Ring(const kovtun::point_t & center, double outerRadius, double innerRadius):
    center_(center),
    outerRadius_(outerRadius),
    innerRadius_(innerRadius)
{}

double kovtun::Ring::getArea() const
{
  return (outerRadius_ * outerRadius_ - innerRadius_ * innerRadius_) * 3.141592;
}

kovtun::rectangle_t kovtun::Ring::getFrameRect() const
{
  double side = outerRadius_ * 2;
  rectangle_t selfRect = { side, side, center_ };
  return selfRect;
}

void kovtun::Ring::move(const kovtun::point_t & point)
{
  center_ = point;
}

void kovtun::Ring::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void kovtun::Ring::scale(double k)
{
  outerRadius_ *= k;
  innerRadius_ *= k;
}

