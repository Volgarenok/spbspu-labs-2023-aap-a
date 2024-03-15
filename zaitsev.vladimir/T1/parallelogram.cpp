#include "parallelogram.hpp"
#include <stdexcept>
#include <cstddef>
#include "base-types.hpp"
#include "geometric_functions.hpp"

zaitsev::Parallelogram::Parallelogram(point_t vertex1, point_t vertex2, point_t vertex3):
  def_vertices_{ vertex1, vertex2, vertex3 }
{
  if (vertex1.y != vertex2.y && vertex3.y != vertex2.y)
  {
    throw std::invalid_argument("Sides are not parallel to x axis");
  }
  if (getAreaOfTriangle(vertex1, vertex2, vertex3)==0)
  {
    throw std::invalid_argument("Parallelogram degenerated into a point");
  }
  if (vertex1.y != vertex2.y)
  {
    def_vertices_[0] = vertex3;
    def_vertices_[1] = vertex2;
    def_vertices_[2] = vertex1;
  }
}

double zaitsev::Parallelogram::getArea() const
{
  return 2 * getAreaOfTriangle(def_vertices_[0], def_vertices_[1], def_vertices_[2]);
}

zaitsev::rectangle_t zaitsev::Parallelogram::getFrameRect() const
{
  point_t left_corner = def_vertices_[0] + def_vertices_[2] - def_vertices_[1];
  point_t right_corner = left_corner;

  for (size_t i = 0; i < 3; ++i)
  {
    changeRectangleBounds(left_corner, right_corner, def_vertices_[i]);
  }
  return transformRectangleBounds(left_corner, right_corner);
}

void zaitsev::Parallelogram::move(point_t dest_pos)
{
  point_t pos = getCenter();
  move(dest_pos.x - pos.x, dest_pos.y - pos.y);
}

void zaitsev::Parallelogram::move(double x_shift, double y_shift)
{
  point_t shift = { x_shift, y_shift };
  for (size_t i = 0; i < 3; ++i)
  {
    def_vertices_[i] += shift;
  }
}

void zaitsev::Parallelogram::unsafeScale(double factor)
{
  point_t center = getCenter();
  for (size_t i = 0; i < 3; ++i)
  {
    def_vertices_[i] = center + (def_vertices_[i] - center) * factor;
  }
}

zaitsev::Shape* zaitsev::Parallelogram::clone() const
{
  return new Parallelogram(*this);
}

zaitsev::point_t zaitsev::Parallelogram::getCenter() const
{
  return (def_vertices_[0] + def_vertices_[2]) / 2;
}
