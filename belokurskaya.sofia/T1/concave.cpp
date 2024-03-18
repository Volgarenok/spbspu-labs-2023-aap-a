#include "concave.hpp"

#include <iostream>
#include <stdexcept>
#include <cmath>

#include "shape.hpp"
#include "triangle.hpp"


belokurskaya::Concave::Concave(const point_t & a, const point_t & b, const point_t & c, const point_t & d):
  a_(a),
  b_(b),
  c_(c),
  d_(d)
{
  if (isTriangle())
  {
    if (!isInsideTriangle())
    {
      throw std::logic_error("Fourth vertex must be inside the triangle formed by the first three vertices");
    }
    if (!isConcave())
    {
      throw std::logic_error("The vertices do not form a concave quadrilateral");
    }
  }
  else
  {
    throw std::logic_error("The first three vertices do not form a triangle");
  }
}


double belokurskaya::Concave::getArea() const
{
  Triangle triangle1(a_, b_, d_);
  Triangle triangle2(a_, c_, d_);

  return triangle1.getArea() + triangle2.getArea();
}

belokurskaya::rectangle_t belokurskaya::Concave::getFrameRect() const
{
  double min_x = std::min(std::min(std::min(a_.x, b_.x), c_.x), d_.x);
  double min_y = std::min(std::min(std::min(a_.y, b_.y), c_.y), d_.y);
  double max_x = std::max(std::max(std::max(a_.x, b_.x), c_.x), d_.x);
  double max_y = std::max(std::max(std::max(a_.y, b_.y), c_.y), d_.y);
  point_t center = {(min_x + max_x) / 2, (min_y + max_y) / 2};
  return {center, max_x - min_x, max_y - min_y};
}

void belokurskaya::Concave::move(const point_t & new_pos)
{
  point_t center = calculateCentroid();
  double dx = new_pos.x - center.x;
  double dy = new_pos.y - center.y;
  move(dx, dy);
}

void belokurskaya::Concave::move(double dx, double dy)
{
  a_.x += dx;
  a_.y += dy;
  b_.x += dx;
  b_.y += dy;
  c_.x += dx;
  c_.y += dy;
  d_.x += dx;
  d_.y += dy;
}

void belokurskaya::Concave::scale(double factor)
{
  if (factor <= 0)
  {
    throw std::invalid_argument("Invalid scaling factor");
  }

  point_t center = calculateCentroid();

  a_ = {center.x + factor * (a_.x - center.x), center.y + factor * (a_.y - center.y)};
  b_ = {center.x + factor * (b_.x - center.x), center.y + factor * (b_.y - center.y)};
  c_ = {center.x + factor * (c_.x - center.x), center.y + factor * (c_.y - center.y)};
  d_ = {center.x + factor * (d_.x - center.x), center.y + factor * (d_.y - center.y)};
}

bool belokurskaya::Concave::isTriangle() const
{
  return ((a_.x - b_.x) * (c_.y - b_.y) - (a_.y - b_.y) * (c_.x - b_.x)) != 0;
}

bool belokurskaya::Concave::isInsideTriangle() const
{
  double a = ((b_.y - c_.y) * (a_.x - c_.x) + (c_.x - b_.x) * (a_.y - c_.y));
  double b = ((b_.y - c_.y) * (d_.x - c_.x) + (c_.x - b_.x) * (d_.y - c_.y));
  double c = ((c_.y - a_.y) * (b_.x - a_.x) + (a_.x - c_.x) * (b_.y - a_.y));
  double d = ((c_.y - a_.y) * (d_.x - a_.x) + (a_.x - c_.x) * (d_.y - a_.y));
  double e = ((a_.y - b_.y) * (c_.x - b_.x) + (b_.x - a_.x) * (c_.y - b_.y));
  double f = ((a_.y - b_.y) * (d_.x - b_.x) + (b_.x - a_.x) * (d_.y - b_.y));

  return a * b >= 0 && c * d >= 0 && e * f >= 0;
}

bool belokurskaya::Concave::isConcave()
{
  double cross_product1 = (b_.x - a_.x) * (c_.y - a_.y) - (b_.y - a_.y) * (c_.x - a_.x);
  double cross_product2 = (c_.x - b_.x) * (d_.y - b_.y) - (c_.y - b_.y) * (d_.x - b_.x);
  double cross_product3 = (d_.x - c_.x) * (a_.y - c_.y) - (d_.y - c_.y) * (a_.x - c_.x);
  double cross_product4 = (a_.x - d_.x) * (b_.y - d_.y) - (a_.y - d_.y) * (b_.x - d_.x);

  int sign_changes = 0;
  if ((cross_product1 > 0) != (cross_product2 > 0))
  {
    sign_changes++;
  }
  if ((cross_product2 > 0) != (cross_product3 > 0))
  {
    sign_changes++;
  }
  if ((cross_product3 > 0) != (cross_product4 > 0))
  {
    sign_changes++;
  }
  if ((cross_product4 > 0) != (cross_product1 > 0))
  {
    sign_changes++;
  }
  return sign_changes > 0;
}

belokurskaya::point_t belokurskaya::Concave::calculateCentroid() const
{
  return d_;
}
