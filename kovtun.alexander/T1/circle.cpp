#include "circle.h"

kovtun::Circle::Circle(const kovtun::point_t &center, double radius):
    center_(center),
    radius_(radius)
{}

double kovtun::Circle::getArea() const
{
  return 0.0;
}

kovtun::rectangle_t kovtun::Circle::getFrameRect() const
{
  return {};
}

void kovtun::Circle::move(const kovtun::point_t &point)
{

}

void kovtun::Circle::move(double dx, double dy)
{

}

void kovtun::Circle::scale(double k)
{

}
