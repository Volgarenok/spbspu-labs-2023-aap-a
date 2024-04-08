#include "ring.hpp"

kovtun::Ring::Ring(const kovtun::point_t & center, double outerRadius, double innerRadius):
    outerEllipse_(center, outerRadius, outerRadius),
    innerEllipse_(center, innerRadius, innerRadius)
{}

double kovtun::Ring::getArea() const
{
  return outerEllipse_.getArea() - innerEllipse_.getArea();
}

kovtun::rectangle_t kovtun::Ring::getFrameRect() const
{
  return outerEllipse_.getFrameRect();
}

void kovtun::Ring::move(const kovtun::point_t & point)
{
  outerEllipse_.move(point);
  innerEllipse_.move(point);
}

void kovtun::Ring::move(double dx, double dy)
{
  outerEllipse_.move(dx, dy);
  innerEllipse_.move(dx, dy);
}

void kovtun::Ring::scale(double k)
{
  outerEllipse_.scale(k);
  innerEllipse_.scale(k);
}

