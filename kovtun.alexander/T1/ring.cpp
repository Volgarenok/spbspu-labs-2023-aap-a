#include "ring.h"

kovtun::Ring::Ring(const kovtun::point_t & center, double outerRadius, double innerRadius):
    center_(center),
    outerRadius_(outerRadius),
    innerRadius_(innerRadius)
{}

double kovtun::Ring::getArea() const
{
  return 0.0;
}

kovtun::rectangle_t kovtun::Ring::getFrameRect() const
{
  return {};
}

void kovtun::Ring::move(const kovtun::point_t & point)
{

}

void kovtun::Ring::move(double dx, double dy)
{

}

void kovtun::Ring::scale(double k)
{

}

