#include "triangle.hpp"
#include <stdexcept>
#include "checkTriangle.hpp"

marishin::Triangle::Triangle(const point_t& first, const point_t& second, const point_t& third):
  first_(first),
  second_(second),
  third_(third)
{
  checkTriangle(first_, second_, third_);
}

double marishin::Triangle::getArea() const
{
  return getAreaTriangle(first_, second_, third_);
}

marishin::rectangle_t marishin::Triangle::getFrameRect() const
{
  return getFrameRectTriangle(first_, second_, third_);
}

void marishin::Triangle::move(const point_t& newPos)
{
  point_t pos = { (first_.x + second_.x + third_.x) / 3, (first_.y + second_.y + third_.y) / 3 };
  move(newPos.x - pos.x, newPos.y - pos.y);
}

void marishin::Triangle::move(double dx, double dy)
{
  first_ = mixPoint(first_, dx, dy);
  second_ = mixPoint(second_, dx, dy);
  third_ = mixPoint(third_, dx, dy);
}

void marishin::Triangle::unsafeScale(double factor)
{
  point_t pos = { (first_.x + second_.x + third_.x) / 3, (first_.y + second_.y + third_.y) / 3 };
  first_ = scaleCorner(first_, pos, factor);
  second_ = scaleCorner(second_, pos, factor);
  third_ = scaleCorner(third_, pos, factor);
}
