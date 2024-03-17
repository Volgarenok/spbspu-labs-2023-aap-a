#include "parallelogram.hpp"

#include <stdexcept>
#include <cmath>
#include <algorithm>

skuratov::point_t findCenOfParal(const skuratov::point_t& p1, const skuratov::point_t& p2, const skuratov::point_t& p3)
{
  skuratov::point_t mid1 = { (p1.x + p2.x) / 2, (p1.y + p2.y) / 2 };
  skuratov::point_t mid2 = { (p2.x + p3.x) / 2, (p2.y + p3.y) / 2 };

  double slope1 = (p1.y - p3.y) / (p1.x - p3.x);
  double slope2 = (p2.y - p3.y) / (p2.x - p3.x);

  skuratov::point_t center = {};
  center.x = (slope1 * mid1.x - slope2 * mid2.x + mid2.y - mid1.y) / (slope1 - slope2);
  center.y = slope1 * (center.x - mid1.x) + mid1.y;
  return center;
}

skuratov::Parallelogram::Parallelogram(const point_t& p1, const point_t& p2, const point_t& p3):
  p1_(p1),
  p2_(p2),
  p3_(p3)
{
  if ((p1_.x != p2_.x || p1_.y != p2_.y) || (p1_.x != p3_.x || p1_.y != p3_.y) || (p2_.x != p3_.x || p2_.y != p3_.y))
  {
    throw std::invalid_argument("At least one of the sides must be parallel to the abscissa axis!");
  }
}

double skuratov::Parallelogram::getArea() const
{
  double side1 = std::sqrt(std::pow(p2_.x - p1_.x, 2) + std::pow(p2_.y - p1_.y, 2));
  double side2 = std::sqrt(std::pow(p3_.x - p1_.x, 2) + std::pow(p3_.y - p1_.y, 2));
  return side1 * side2;
}

skuratov::rectangle_t skuratov::Parallelogram::getFrameRect() const
{
  double width = {};
  if (p1_.x == p2_.x)
  {
    width = std::abs(p2_.x - p3_.x);
  }
  else
  {
    width = std::abs(p2_.x - p1_.x);
  }
  double height = {};
  if (p1_.y == p2_.y)
  {
    height = std::abs(p2_.y - p3_.y);
  }
  else
  {
    height = std::abs(p1_.y - p2_.y);
  }
  point_t center = findCenOfParal(p1_, p2_, p3_);
  return { width, height, center };
}

void skuratov::Parallelogram::move(const point_t& A)
{
  point_t center = findCenOfParal(p1_, p2_, p3_);
  double dx = A.x - center.x;
  double dy = A.y - center.y;
  move(dx, dy);
}

void skuratov::Parallelogram::move(double dx, double dy)
{
  p1_.x += dx;
  p2_.x += dx;
  p3_.x += dx;

  p1_.y += dy;
  p2_.y += dy;
  p3_.y += dy;
}

void skuratov::Parallelogram::scale(double scalingFactor)
{
  if (scalingFactor <= 0)
  {
    throw std::invalid_argument("Error: scale factor of parallelogram should be a positive");
  }

  point_t center = findCenOfParal(p1_, p2_, p3_);

  point_t points[] = { p1_, p2_, p3_ };
  for (auto& point : points)
  {
    point.x = center.x + scalingFactor * (point.x - center.x);
    point.y = center.y + scalingFactor * (point.y - center.y);
  }
}
