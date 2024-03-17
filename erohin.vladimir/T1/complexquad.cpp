#include "complexquad.hpp"
#include <stdexcept>
#include "base-types.hpp"
#include "geom_func.hpp"
#include "triangle.hpp"

erohin::Complexquad::Complexquad(point_t corner1, point_t corner2, point_t corner3, point_t corner4):
  vertex_{ corner1, corner2, corner3, corner4 }
{
  point_t center = findIntersectionPoint(vertex_);
  for (size_t i = 0; i < 3; i += 2)
  {
    if (!isPointOnSegment(center, vertex_[i], vertex_[i + 1]))
    {
      throw std::invalid_argument("Complexquad vertexes are same points");
    }
  }
}

erohin::Complexquad::~Complexquad() = default;

double erohin::Complexquad::getArea() const
{
  double area = 0.0;
  point_t point[3]{ 0.0, 0.0 };
  point[0] = getCenter();
  for (size_t i = 0; i < 2; ++i)
  {
    point[1] = vertex_[i];
    point[2] = vertex_[3 - i];
    area += Triangle(point[0], point[1], point[2]).getArea();
  }
  return area;
}

erohin::rectangle_t erohin::Complexquad::getFrameRect() const
{
  return findPointsFrameRect(vertex_, 4);
}

erohin::point_t erohin::Complexquad::getCenter() const
{
  return findIntersectionPoint(vertex_);
}

void erohin::Complexquad::move(double dx, double dy)
{
  for (size_t i = 0; i < 4; ++i)
  {
    vertex_[i].x += dx;
    vertex_[i].y += dy;
  }
}

void erohin::Complexquad::move(point_t point)
{
  point_t center = getCenter();
  double dx = point.x - center.x;
  double dy = point.y - center.y;
  move(dx, dy);
}

void erohin::Complexquad::unsafeScale(double ratio)
{
  point_t center = getCenter();
  for (size_t i = 0; i < 4; ++i)
  {
    vertex_[i].x = center.x + (vertex_[i].x - center.x) * ratio;
    vertex_[i].y = center.y + (vertex_[i].y - center.y) * ratio;
  }
}

erohin::Shape* erohin::Complexquad::clone() const
{
  Shape* shape = new Complexquad(vertex_[0], vertex_[1], vertex_[2], vertex_[3]);
  return shape;
}
