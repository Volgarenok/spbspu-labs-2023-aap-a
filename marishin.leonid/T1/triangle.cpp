#include "triangle.hpp"
#include <stdexcept>

marishin::Triangle::Triangle(const point_t firstPoint, const point_t secondPoint, const point_t thirdPoint):
  firstPoint_(firstPoint),
  secondPoint_(secondPoint),
  thirdPoint_(thirdPoint)
{
  if (!(isTriangleExist(firstPoint_, secondPoint_, thirdPoint_)))
  {
    throw std::logic_error("Irregular triangle");
  }
}

marishin::Triangle::~Triangle()
{
}

double marishin::Triangle::getArea()
{
  double area = calculateTriangleArea(firstPoint_, secondPoint_, thirdPoint_);
  return area;
}

rectangle_t marishin::Triangle::getFrameRect()
{
  point_t pos = { (std::max(firstPoint_.x, (std::max(secondPoint_.x, thirdPoint_.x))) - std::min(firstPoint_.x, (std::min(secondPoint_.x, thirdPoint_.x)))) / 2, (std::max(firstPoint_.y, (std::max(secondPoint_.y, thirdPoint_.y))) - std::min(firstPoint_.y, (std::min(secondPoint_.y, thirdPoint_.y)))) / 2 };
  double height = (std::max(firstPoint_.y, (std::max(secondPoint_.y, thirdPoint_.y))) - std::min(firstPoint_.y, (std::min(secondPoint_.y, thirdPoint_.y))));
  double width = (std::max(firstPoint_.x, (std::max(secondPoint_.x, thirdPoint_.x))) - std::min(firstPoint_.x, (std::min(secondPoint_.x, thirdPoint_.x))));
  return { pos, height, width };
}

void marishin::Triangle::move(const point_t newPos)
{
  point_t pos = { (firstPoint_.x + secondPoint_.x + thirdPoint_.x) / 3.0, (firstPoint_.y + secondPoint_.y + thirdPoint_.y) / 3.0 };
  move(newPos.x - pos.x, newPos.y - pos.y);
}

void marishin::Triangle::move(const double dx, const double dy)
{
  point_t pos = { (firstPoint_.x + secondPoint_.x + thirdPoint_.x) / 3.0, (firstPoint_.y + secondPoint_.y + thirdPoint_.y) / 3.0 };

  pos.x += dx;
  pos.y += dy;

  firstPoint_.x += dx;
  firstPoint_.y += dy;

  secondPoint_.x += dx;
  secondPoint_.y += dy;

  thirdPoint_.x += dx;
  thirdPoint_.y += dy;
}

void marishin::Triangle::scale(const double factor)
{
  point_t pos = { (firstPoint_.x + secondPoint_.x + thirdPoint_.x) / 3.0, (firstPoint_.y + secondPoint_.y + thirdPoint_.y) / 3.0 };

  firstPoint_.x = pos.x + (firstPoint_.x - pos.x) * factor;
  firstPoint_.y = pos.y + (firstPoint_.y - pos.y) * factor;

  secondPoint_.x = pos.x + (secondPoint_.x - pos.x) * factor;
  secondPoint_.y = pos.y + (secondPoint_.y - pos.y) * factor;

  thirdPoint_.x = pos.x + (thirdPoint_.x - pos.x) * factor;
  thirdPoint_.y = pos.y + (thirdPoint_.y - pos.y) * factor;
}
