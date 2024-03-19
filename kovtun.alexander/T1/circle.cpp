#include "circle.hpp"

kovtun::Circle::Circle(const kovtun::point_t & center, double radius):
    ellipse_(center, radius, radius)
{}

double kovtun::Circle::getArea() const
{
  return ellipse_.getArea();
}

kovtun::rectangle_t kovtun::Circle::getFrameRect() const
{
  return ellipse_.getFrameRect();
}

void kovtun::Circle::move(const kovtun::point_t & point)
{
  ellipse_.move(point);
}

void kovtun::Circle::move(double dx, double dy)
{
  ellipse_.move(dx, dy);
}

void kovtun::Circle::scale(double k)
{
  ellipse_.scale(k);
}

