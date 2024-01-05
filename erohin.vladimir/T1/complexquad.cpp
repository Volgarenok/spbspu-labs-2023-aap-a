#include "complexquad.hpp"
#include <stdexcept>
#include "base-types.hpp"
#include "geom_func.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

erohin::Complexquad::Complexquad() :
  center_({ 0.0, 0.0 })
{
  vertex_ = new point_t[4]{ {0.0, 0.0} };
}

erohin::Complexquad::Complexquad(point_t* corner)
{
  vertex_ = new point_t[4]{ {0.0, 0.0} };
  center_ = { 0.0, 0.0 };
  for (int i = 0; i < 4; ++i)
  {
    vertex_[i] = corner[i];
  }
  double x = 0.0;
  double y = 0.0;
  double dx[3]{ 0.0 };
  double dy[3]{ 0.0 };
  for (int i = 0; i < 3; ++i)
  {
    dx[i] = vertex_[i + 1].x - vertex_[i].x;
    dy[i] = vertex_[i + 1].y - vertex_[i].y;
  }
  if (vertex_[1].x != vertex_[0].x && vertex_[3].x != vertex_[2].x && dy[0] != dy[2])
  {
    x = dx[0] * vertex_[0].y - dy[0] * vertex_[0].x + dy[2] * vertex_[2].x - dx[2] * vertex_[2].y;
    x /= (dy[2] - dy[0]);
    y = vertex_[1].y + dy[0] * (x - vertex_[2].x) / dx[0];
  }
  center_ = {x, y};
}

erohin::Complexquad::~Complexquad()
{
  delete[] vertex_;
}

double erohin::Complexquad::getArea() const
{
  double area = 0.0;
  /*
  for (int i = 0; i < 4; ++i)
  {
    area += (vertex_[i].x * (vertex_[(i + 1) % 4].y - vertex_[(i + 3) % 4].y));
  }
  area /= 2.0;
  */
  point_t point[3]{ {0.0, 0.0} };
  point[0] = center_;
  for (int i = 0; i < 2; ++i)
  {
    point[1] = vertex_[i];
    point[2] = vertex_[3 - i];
    area += Triangle(point).getArea();
  }
  return area;
}

erohin::rectangle_t erohin::Complexquad::getFrameRect() const
{
  point_t left = vertex_[0];
  point_t right = vertex_[0];
  for (int i = 1; i < 4; ++i)
  {
    if (vertex_[i].x < left.x)
    {
      left.x = vertex_[i].x;
    }
    if (vertex_[i].y < left.y)
    {
      left.y = vertex_[i].y;
    }
    if (vertex_[i].x > right.x)
    {
      right.x = vertex_[i].x;
    }
    if (vertex_[i].y > right.y)
    {
      right.y = vertex_[i].y;
    }
  }
  return Rectangle(left, right).getFrameRect();
}

void erohin::Complexquad::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
  for (int i = 0; i < 4; ++i)
  {
    vertex_[i].x += dx;
    vertex_[i].y += dy;
  }
}

void erohin::Complexquad::move(point_t point)
{
  double dx = point.x - center_.x;
  double dy = point.y - center_.y;
  move(dx, dy);
}

void erohin::Complexquad::scale(double ratio)
{
  if (ratio <= 0)
  {
    throw std::invalid_argument("Wrong scale ratio");
  }
  for (int i = 0; i < 4; ++i)
  {
    vertex_[i].x = center_.x + (vertex_[i].x - center_.x) * ratio;
    vertex_[i].y = center_.y + (vertex_[i].y - center_.y) * ratio;
  }
}
