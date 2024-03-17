#include "triangle.hpp"
#include <stdexcept>
#include <cmath>
#include "base-types.hpp"
#include "geom_func.hpp"

erohin::Triangle::Triangle(point_t corner1, point_t corner2, point_t corner3):
  vertex_{ corner1, corner2, corner3 }
{
  double side[3]{ 0.0 };
  getSides(side, vertex_, 3);
  for (size_t i = 0; i < 3; ++i)
  {
    if (side[i % 3] >= side[(i + 1) % 3] + side[(i + 2) % 3])
    {
      throw std::invalid_argument("Wrong figure creation");
    }
  }
}

erohin::Triangle::~Triangle() = default;

double erohin::Triangle::getArea() const
{
  double side[3]{ 0.0 };
  getSides(side, vertex_, 3);
  double perimeter = 0.0;
  for (size_t i = 0; i < 3; ++i)
  {
    perimeter += side[i];
  }
  double result = perimeter / 2.0;
  for (size_t i = 0; i < 3; ++i)
  {
    result *= (perimeter / 2.0 - side[i]);
  }
  return std::sqrt(result);
}

erohin::rectangle_t erohin::Triangle::getFrameRect() const
{
  return findPointsFrameRect(vertex_, 3);
}

void erohin::Triangle::move(double dx, double dy)
{
  for (size_t i = 0; i < 3; ++i)
  {
    vertex_[i].x += dx;
    vertex_[i].y += dy;
  }
}

erohin::point_t erohin::Triangle::getCenter() const
{
  point_t center = { 0.0, 0.0 };
  for (size_t i = 0; i < 3; ++i)
  {
    center.x += vertex_[i].x / 3.0;
    center.y += vertex_[i].y / 3.0;
  }
  return center;
}

void erohin::Triangle::move(point_t point)
{
  point_t center = getCenter();
  double dx = point.x - center.x;
  double dy = point.y - center.y;
  move(dx, dy);
}

void erohin::Triangle::unsafeScale(double ratio)
{
  point_t center = getCenter();
  for (size_t i = 0; i < 3; ++i)
  {
    vertex_[i].x = center.x + (vertex_[i].x - center.x) * ratio;
    vertex_[i].y = center.y + (vertex_[i].y - center.y) * ratio;
  }
}

erohin::Shape* erohin::Triangle::clone() const
{
  Shape* shape = new Triangle(vertex_[0], vertex_[1], vertex_[2]);
  return shape;
}
