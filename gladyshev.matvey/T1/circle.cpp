#include "circle.hpp"

#include <stdexcept>

gladyshev::Circle::Circle(const point_t& p1, double radius):
  radius_{ radius },
  center_{ p1 }
{
  if (radius <= 0)
  {
    throw std::invalid_argument("radius mast be positive");
  }
}

gladyshev::Circle::~Circle() = default;

double gladyshev::Circle::getArea() const
{
  return radius_ * radius_ * 3.14;
}

gladyshev::rectangle_t gladyshev::Circle::getFrameRect() const
{
  double height = 2 * radius_;
  double width = 2 * radius_;
  point_t pos = { center_.x, center_.y };
  return { pos, width, height };
}

void gladyshev::Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}
void gladyshev::Circle::move(const point_t& newPos)
{
  move(newPos.x - getFrameRect().pos.x, newPos.y - getFrameRect().pos.y);
}

void gladyshev::Circle::unsafeScale(double factor)
{
  radius_ *= factor;
}
