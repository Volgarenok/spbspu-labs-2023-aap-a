#include "ellipse.hpp"

kovtun::Ellipse::Ellipse(const kovtun::point_t & center, double verticalRadius, double horizontalRadius):
    center_(center),
    verticalRadius_(verticalRadius),
    horizontalRadius_(horizontalRadius)
{}

double kovtun::Ellipse::getArea() const
{
  return verticalRadius_ * horizontalRadius_ * 3.141592;
}

kovtun::rectangle_t kovtun::Ellipse::getFrameRect() const
{
  double height = verticalRadius_ * 2;
  double width = horizontalRadius_ * 2;
  rectangle_t selfRect = { width, height, center_};
  return selfRect;
}

void kovtun::Ellipse::move(const kovtun::point_t & point)
{
  center_ = point;
}

void kovtun::Ellipse::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void kovtun::Ellipse::scale(double k)
{
  verticalRadius_ *= k;
  horizontalRadius_ *= k;
}

