#include "complexquad.hpp"
#include <stdexcept>
#include <cstring>
#include <cstddef>
#include <algorithm>
#include "base-types.hpp"
#include "geometric_functions.hpp"

zaitsev::Complexquad::Complexquad(point_t vertex1, point_t vertex2, point_t vertex3, point_t vertex4):
  vertices_{ vertex1, vertex2, vertex3, vertex4 }
{
  if (!checkIntersection(vertices_))
  {
    throw std::invalid_argument("Lines are parallel");
  }
}

double zaitsev::Complexquad::getArea() const
{
  point_t center = getCenter();
  return getAreaOfTriangle(center, vertices_[0], vertices_[3]) + getAreaOfTriangle(center, vertices_[0], vertices_[3]);
}

zaitsev::rectangle_t zaitsev::Complexquad::getFrameRect() const
{
  point_t left_corner = vertices_[0];
  point_t right_corner = vertices_[0];
  for (size_t i = 1; i < 4; ++i)
  {
    changeRectangleBounds(left_corner, right_corner, vertices_[i]);
  }
  return transformRectangleBounds(left_corner, right_corner);
}

void zaitsev::Complexquad::move(point_t dest_pos)
{
  point_t pos = getCenter();
  move(dest_pos.x - pos.x, dest_pos.y - pos.y);
}

void zaitsev::Complexquad::move(double x_shift, double y_shift)
{
  point_t shift = { x_shift, y_shift };
  for (size_t i = 0; i < 4; ++i)
  {
    vertices_[i] += shift;
  }
}

zaitsev::point_t zaitsev::Complexquad::getCenter() const
{
  return findIntersection(vertices_);
}

void zaitsev::Complexquad::unsafeScale(double factor)
{
  point_t center = getCenter();
  for (size_t i = 0; i < 4; ++i)
  {
    vertices_[i] = center + (vertices_[i] - center) * factor;
  }
}

zaitsev::Shape* zaitsev::Complexquad::clone() const
{
  return new Complexquad(*this);
}
