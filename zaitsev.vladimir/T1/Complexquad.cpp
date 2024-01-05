#include "Complexquad.h"
#include <stdexcept>
#include <cstring>
#include <cmath>
#include <cstddef>
#include <limits>
#include <algorithm>
#include "base-types.h"
#include "Geom_functions.h"

zaitsev::Complexquad::Complexquad(const point_t* sections)
{
 if (!checkIntersection(sections))
 {
   throw std::invalid_argument("Lines are parallel");
 }
 std::memcpy(vertices_, sections, 4 * sizeof(point_t));
}

double zaitsev::Complexquad::getArea() const
{
  point_t center = getCenter();
  return getAreaOfTriangle(center, vertices_[0], vertices_[3]) + getAreaOfTriangle(center, vertices_[0], vertices_[3]);
}

zaitsev::rectangle_t zaitsev::Complexquad::getFrameRect() const
{
  double lower = std::numeric_limits< double >::max();
  double upper = std::numeric_limits< double >::min();
  double left = std::numeric_limits< double >::max();
  double right = std::numeric_limits< double >::min();

  for (size_t i = 0; i < 4; ++i)
  {
    lower = std::min(lower, vertices_[i].y);
    upper = std::max(upper, vertices_[i].y);
    left = std::min(left, vertices_[i].x);
    right = std::max(right, vertices_[i].x);
  }

  double width = right - left;
  double height = upper - lower;
  point_t pos = { (lower + upper) / 2, (left + right) / 2 };
  return { width, height, pos };
}

void zaitsev::Complexquad::move(const point_t& dest_pos)
{
  point_t pos = getCenter();
  this->move(dest_pos.x - pos.x, dest_pos.y - pos.y);
}

void zaitsev::Complexquad::move(double x_shift, double y_shift)
{
  for (size_t i = 0; i < 4; ++i)
  {
    vertices_[i].x += x_shift;
    vertices_[i].y += y_shift;
  }
}

zaitsev::point_t zaitsev::Complexquad::getCenter() const
{
  return findIntersection(vertices_);
}

void zaitsev::Complexquad::scale(double factor)
{
  if (factor <= 0)
  {
    throw std::invalid_argument("Scale factor must be positive");
  }
  point_t center = getCenter();
  for (size_t i = 0; i < 4; ++i)
  {
    vertices_[i].x = center.x + (vertices_[i].x - center.x) * factor;
    vertices_[i].y = center.y + (vertices_[i].y - center.y) * factor;
  }
  return;
}
