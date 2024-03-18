#include "triangle.hpp"
#include <cmath>
#include <algorithm>
#include <stdexcept>

lopatina::Triangle::Triangle(point_t point1, point_t point2, point_t point3):
  points_{point1, point2, point3}
{
  double a = std::sqrt(std::pow(point1.x - point2.x, 2.0) + std::pow(point1.y - point2.y, 2.0));
  double b = std::sqrt(std::pow(point2.x - point3.x, 2.0) + std::pow(point2.y - point3.y, 2.0));
  double c = std::sqrt(std::pow(point1.x - point3.x, 2.0) + std::pow(point1.y - point3.y, 2.0));
  if ((a >= (b + c)) || (b >= (a + c)) || (c >= (a + b)))
  {
    throw std::invalid_argument("Figure has wrong parameter\n");
  }
}

double lopatina::Triangle::getArea() const
{
  point_t p1 = points_[0];
  point_t p2 = points_[1];
  point_t p3 = points_[2];
  return 0.5 * (std::abs ((p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y)));
}

lopatina::rectangle_t lopatina::Triangle::getFrameRect() const
{
  point_t p1 = points_[0];
  point_t p2 = points_[1];
  point_t p3 = points_[2];
  double max_x = std::max({p1.x, p2.x, p3.x});
  double min_x = std::min({p1.x, p2.x, p3.x});
  double max_y = std::max({p1.y, p2.y, p3.y});
  double min_y = std::min({p1.y, p2.y, p3.y});
  double height = max_y - min_y;
  double width = max_x - min_x;
  point_t pos = {min_x + (width / 2.0), min_y + (height / 2.0)};
  rectangle_t newRect{height, width, pos};
  return newRect;
}

void lopatina::Triangle::move(point_t new_pos)
{
  point_t pos_tri = {(points_[0].x + points_[1].x + points_[2].x) / 3.0, (points_[0].y + points_[1].y + points_[2].y) / 3.0};
  double dx = new_pos.x - pos_tri.x;
  double dy = new_pos.y - pos_tri.y;
  move(dx, dy);
}

void lopatina::Triangle::move(double dx, double dy)
{
  for (size_t i = 0; i < 3; ++i)
  {
    points_[i].x += dx;
    points_[i].y += dy;
  }
}

void lopatina::Triangle::scale(double k)
{
  if (k <= 0.0)
  {
    throw std::invalid_argument("Incorrect scale index\n");
  }
  point_t pos_tri = {(points_[0].x + points_[1].x + points_[2].x) / 3.0, (points_[0].y + points_[1].y + points_[2].y) / 3.0};
  for (size_t i = 0; i < 3; ++i)
  {
    points_[i].x = pos_tri.x + (points_[i].x - pos_tri.x) * k;
    points_[i].y = pos_tri.y + (points_[i].y - pos_tri.y) * k;
  }
}
