#include "ellipse.h"

kovtun::Ellipse::Ellipse(const kovtun::point_t & center, double verticalRadius, double horizontalRadius):
    center_(center),
    verticalRadius_(verticalRadius),
    horizontalRadius_(horizontalRadius)
{}

double kovtun::Ellipse::getArea() const
{
  return 0.0;
}

kovtun::rectangle_t kovtun::Ellipse::getFrameRect() const
{
  return {};
}

void kovtun::Ellipse::move(const kovtun::point_t &point)
{

}

void kovtun::Ellipse::move(double dx, double dy)
{

}

void kovtun::Ellipse::scale(double k)
{

}

