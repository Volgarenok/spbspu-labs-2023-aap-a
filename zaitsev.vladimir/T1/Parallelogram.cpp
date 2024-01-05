#include "Parallelogram.h"
#include <stdexcept>
#include <cstring>
#include <cmath>
#include <cstddef>
#include <limits>
#include <algorithm>

zaitsev::Parallelogram::Parallelogram(const point_t* vertices)
{
  if (vertices[0].x != vertices[1].x && vertices[2].x != vertices[1].x)
  {
    throw std::invalid_argument("Sides are not parallel to x axis");
  }
  if (vertices[0].x != vertices[1].x)
  {
    def_vertices_[0] = vertices[2];
    def_vertices_[1] = vertices[1];
    def_vertices_[2] = vertices[0];
  }
  else
  {
    memcpy(def_vertices_, vertices, 3 * sizeof(point_t));
  }
}

double zaitsev::Parallelogram::getArea() const
{
  return abs(def_vertices_[0].x - def_vertices_[1].x) * abs(def_vertices_[1].y - def_vertices_[2].y);
}

zaitsev::rectangle_t zaitsev::Parallelogram::getFrameRect() const
{
  double lower = std::numeric_limits< double >::max();
  double upper = std::numeric_limits< double >::min();
  double left = std::numeric_limits< double >::max();
  double right = std::numeric_limits< double >::min();

  for (size_t i = 0; i < 3; ++i)
  {
    lower = std::min(lower, def_vertices_[i].y);
    upper = std::max(upper, def_vertices_[i].y);
    left = std::min(left, def_vertices_[i].x);
    right = std::max(right, def_vertices_[i].x);
  }

  point_t vertex4 = { def_vertices_[0].x + def_vertices_[2].x - def_vertices_[1].x,
    def_vertices_[0].y + def_vertices_[2].y - def_vertices_[1].y };

  lower = std::min(lower, vertex4.y);
  upper = std::max(upper, vertex4.y);
  left = std::min(left, vertex4.x);
  right = std::max(right, vertex4.x);

  double width = right - left;
  double height = upper - lower;
  point_t pos = { (lower + upper) / 2, (left + right) / 2 };
  return { width, height, pos };
}

void zaitsev::Parallelogram::move(const point_t& dest_pos)
{
  point_t pos = getCenter();
  this->move(dest_pos.x - pos.x, dest_pos.y - pos.y);
}

void zaitsev::Parallelogram::move(double x_shift, double y_shift)
{
  for (size_t i = 0; i < 3; ++i)
  {
    def_vertices_[i].x += x_shift;
    def_vertices_[i].y += y_shift;
  }
}

void zaitsev::Parallelogram::scale(double factor)
{
  if (factor <= 0)
  {
    throw std::invalid_argument("Scale factor must be positive");
  }
  point_t center = getCenter();
  for (size_t i = 0; i < 3; ++i)
  {
    def_vertices_[i].x = center.x + (def_vertices_[i].x - center.x) * factor;
    def_vertices_[i].y = center.y + (def_vertices_[i].y - center.y) * factor;
  }
}

zaitsev::point_t zaitsev::Parallelogram::getCenter() const
{
  double x = (def_vertices_[0].x + def_vertices_[2].x) / 2 - def_vertices_[1].x;
  double y = (def_vertices_[0].y + def_vertices_[2].y) / 2 - def_vertices_[1].y;
  return { x,y };
}
