#include "parallelogram.hpp"
#include <stdexcept>
#include <cmath>
#include "base_type.hpp"
#include <algorithm>

shabalin::Parallelogram::Parallelogram(const point_t &p1, const point_t &p2, const point_t &p3):
  p1_(p1),
  p2_(p2),
  p3_(p3)
{
  if (!((p1_.y == p2_.y) || (p1_.y == p3_.y) || (p2_.y == p3_.y)))
  {
    throw std::invalid_argument("Sides are not parallel to axis!");
  }
}

double shabalin::Parallelogram::getArea() const
{
  return std::abs((p1_.x * (p2_.y - p3_.y) + p2_.x * (p3_.y - p1_.y) + p3_.x * (p1_.y - p2_.y)));
}

shabalin::rectangle_t shabalin::Parallelogram::getFrameRect() const
{
  double width = {};
  double height = {};

  (p1_.x == p2_.x) ?  width = std::abs(p2_.x - p3_.x) :
  width = std::abs(p2_.x - p3_.x);
  (p1_.y == p2_.y) ? height = std::abs(p2_.y - p3_.y) :
  height = std::abs(p1_.y - p2_.y);

  point_t center = parallelogramCenter(p1_, p2_, p3_);

  return { width, height, center };
}

void shabalin::Parallelogram::move(const point_t &del)
{
  point_t center = parallelogramCenter(p1_, p2_, p3_);
  double del_x = del.x - center.x;
  double del_y = del.y - center.y;
  move(del_x, del_y);
}

void shabalin::Parallelogram::move(double del_x, double del_y)
{
  p1_.x += del_x;
  p2_.x += del_x;
  p3_.x += del_x;

  p1_.y += del_y;
  p2_.y += del_y;
  p3_.y += del_y;
}

void shabalin::Parallelogram::unsafeScale(double ratio)
{
  point_t center = parallelogramCenter(p1_, p2_, p3_);
  point_t *points[] = { &p1_, &p2_, &p3_};
  for (size_t i = 0; i < 3; ++i)
  {
    points[i]->x = center.x + (points[i]->x - center.x) * ratio;
    points[i]->y = center.y + (points[i]->y - center.y) * ratio;
  }
}