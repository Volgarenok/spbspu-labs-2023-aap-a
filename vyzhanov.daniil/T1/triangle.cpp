#include "triangle.hpp"
#include <stdexcept>
#include <cmath>
#include <algorithm>

vyzhanov::Triangle::Triangle(const point_t& a, const point_t& b, const point_t& c):
  a_(a),
  b_(b),
  c_(c)
{
  if (getArea() == 0)
  {
    throw std::invalid_argument("Invalid points");
  }
}

double vyzhanov::Triangle::getArea() const
{
  double area = ((b_.x - a_.x) * (c_.y - a_.y) - (c_.x - a_.x) * (b_.y - a_.y)) / 2;
  return area;
}

vyzhanov::rectangle_t vyzhanov::Triangle::getFrameRect() const
{
  double height = (std::max(std::max(a_.y, b_.y), c_.y) - std::min(std::min(b_.y, a_.y), c_.y));
  double width = (std::max(std::max(a_.x, b_.x), c_.x) - std::min(std::min(a_.x, b_.x), c_.x));
  point_t cen = { std::min(std::min(a_.x, b_.x), c_.x) + width / 2, std::min(std::min(a_.y, b_.y), c_.y) + height / 2 };
  return { width, height, cen };
}

void vyzhanov::Triangle::move(const point_t& pos)
{
  point_t cen = { (a_.x +b_.x + c_.x) / 3, (a_.y + b_.y + c_.y) / 3 };
  move(pos.x - cen.x, pos.y - cen.y);
}

void vyzhanov::Triangle::move(double dx, double dy)
{
  a_.x += dx;
  a_.y += dy;
  b_.x += dx;
  b_.y += dy;
  c_.x += dx;
  c_.y += dy;
}

void vyzhanov::Triangle::scale(const double ratio)
{
  point_t cen = { (a_.x + b_.x + c_.x) / 3, (a_.y + b_.y + c_.y) / 3 };
  a_.x = cen.x + ratio * (cen.y - a_.x);
  a_.y = cen.y + ratio * (cen.y - a_.y);
  b_.x = cen.x + ratio * (cen.y - b_.x);
  b_.y = cen.y + ratio * (cen.y - b_.y);
  c_.x = cen.x + ratio * (cen.y - c_.x);
  c_.y = cen.y + ratio * (cen.y - c_.y);
}

