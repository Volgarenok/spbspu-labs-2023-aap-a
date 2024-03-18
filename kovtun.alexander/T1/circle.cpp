#include "circle.h"

kovtun::Circle::Circle(const kovtun::point_t &center, double radius):
    center_(center),
    radius_(radius)
{}

double kovtun::Circle::getArea() const
{
  double pi = 3.141592;
  return radius_ * radius_ * pi;
}

kovtun::rectangle_t kovtun::Circle::getFrameRect() const
{
  double side = radius_ * 2;
  rectangle_t selfRect = {side, side, center_};
  return selfRect;
}

void kovtun::Circle::move(const kovtun::point_t & point)
{
  center_ = point;
}

void kovtun::Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void kovtun::Circle::scale(double k)
{
  radius_ *= k;
}
