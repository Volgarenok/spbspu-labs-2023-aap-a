#include "triangle.hpp"
#include "base-types.hpp"
#include "geom_func.hpp"
#include "rectangle.hpp"
#include <stdexcept>
#include <cmath>

erohin::Triangle::Triangle() :
  center_({ 0.0, 0.0 })
{
  vertex_ = new point_t[3]{ {0.0, 0.0} };
}

erohin::Triangle::Triangle(point_t* corner)
{
  vertex_ = new point_t[3]{ {0.0, 0.0} };
  center_ = { 0.0, 0.0 };
  for (int i = 0; i < 3; ++i)
  {
    vertex_[i] = corner[i];
  }
  double* side = getSide();
  for (int i = 0; i < 3; ++i)
  {
    if (side[i % 3] >= side[(i + 1) % 3] + side[(i + 2) % 3])
    {
      for (int j = 0; j < 3; ++j)
      {
        vertex_[j] = { 0.0, 0.0 };
      }
      break;
    }
  }
  delete[] side;
  for (int i = 0; i < 3; ++i)
  {
    center_.x += corner[i].x / 3.0;
    center_.y += corner[i].y / 3.0;
  }
}

erohin::Triangle::~Triangle()
{
  delete[] vertex_;
}

double erohin::Triangle::getArea() const
{
  double* side = getSide();
  double p = 0.0;
  for (int i = 0; i < 3; ++i)
  {
    p += side[i];
  }
  double result = p / 2.0;
  for (int i = 0; i < 3; ++i)
  {
    result *= (p / 2.0 - side[i]);
  }
  delete[] side;
  return std::sqrt(result);
}

erohin::rectangle_t erohin::Triangle::getFrameRect() const
{
  point_t left = vertex_[0];
  point_t right = vertex_[0];
  for (int i = 1; i < 3; ++i)
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

void erohin::Triangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
  for (int i = 0; i < 3; ++i)
  {
    vertex_[i].x += dx;
    vertex_[i].y += dy;
  }
}

void erohin::Triangle::move(point_t point)
{
  double dx = point.x - center_.x;
  double dy = point.y - center_.y;
  move(dx, dy);
}

void erohin::Triangle::scale(double ratio)
{
  if (ratio <= 0)
  {
    throw std::invalid_argument("Wrong scale ratio");
  }
  for (int i = 0; i < 3; ++i)
  {
    vertex_[i].x = center_.x + (vertex_[i].x - center_.x) * ratio;
    vertex_[i].y = center_.y + (vertex_[i].y - center_.y) * ratio;
  }
}

double* erohin::Triangle::getSide() const
{
  double* side = new double[3] { 0.0 };
  for (int i = 0; i < 3; ++i)
  {
    side[i] = getDistance(vertex_[i], vertex_[(i + 1) % 3]);
  }
  return side;
}
