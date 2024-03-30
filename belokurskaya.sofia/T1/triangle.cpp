#include "triangle.hpp"

#include <stdexcept>
#include <cmath>

#include "base-types.hpp"

belokurskaya::Triangle::Triangle(const point_t & a, const point_t & b, const point_t & c):
  a_(a),
  b_(b),
  c_(c)
{
  double area = getArea();

  if (area == 0)
  {
    throw std::logic_error("Invalid triangle: degenerate triangle (zero area).");
  }

  if (a_ == b_ || a_ == c_ || b_ == c_)
  {
    throw std::logic_error("Invalid triangle: vertices cannot be equal.");
  }

  if (std::labs((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y)) < 1e-9)
  {
    throw std::logic_error("Is not a triangle.");
  }
}

double belokurskaya::Triangle::getArea() const
{
  double ab = std::hypot(a_.x - b_.x, a_.y - b_.y);
  double bc = std::hypot(b_.x - c_.x, b_.y - c_.y);
  double ca = std::hypot(c_.x - a_.x, c_.y - a_.y);
  double s = (ab + bc + ca) / 2.0;
  return std::sqrt(s * (s - ab) * (s - bc) * (s - ca));
}

belokurskaya::rectangle_t belokurskaya::Triangle::getFrameRect() const
{
  double min_x = std::min(std::min(a_.x, b_.x), c_.x);
  double max_x = std::max(std::max(a_.x, b_.x), c_.x);
  double min_y = std::min(std::min(a_.y, b_.y), c_.y);
  double max_y = std::max(std::max(a_.y, b_.y), c_.y);

  double width = max_x - min_x;
  double height = max_y - min_y;

  point_t center{(min_x + max_x) / 2.0, (min_y + max_y) / 2.0};

  return {center, width, height};
}

void belokurskaya::Triangle::move(const point_t & new_pos)
{
  point_t centroid = calculateCentroid();
  double dx = new_pos.x - centroid.x;
  double dy = new_pos.y - centroid.y;

  move(dx, dy);
}

void belokurskaya::Triangle::move(double dx, double dy)
{
  a_.x += dx;
  a_.y += dy;
  b_.x += dx;
  b_.y += dy;
  c_.x += dx;
  c_.y += dy;
}

void belokurskaya::Triangle::scale(double factor)
{
  if (factor <= 0)
  {
    throw std::invalid_argument("Invalid scaling factor");
  }

  point_t centroid = calculateCentroid();

  a_.x = centroid.x + (a_.x - centroid.x) * factor;
  a_.y = centroid.y + (a_.y - centroid.y) * factor;

  b_.x = centroid.x + (b_.x - centroid.x) * factor;
  b_.y = centroid.y + (b_.y - centroid.y) * factor;

  c_.x = centroid.x + (c_.x - centroid.x) * factor;
  c_.y = centroid.y + (c_.y - centroid.y) * factor;
}

belokurskaya::point_t belokurskaya::Triangle::calculateCentroid() const
{
  double centroid_x = (a_.x + b_.x + c_.x) / 3.0;
  double centroid_y = (a_.y + b_.y + c_.y) / 3.0;
  return {centroid_x, centroid_y};
}
