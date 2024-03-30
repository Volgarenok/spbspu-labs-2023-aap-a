#include "parallelogram.hpp"
#include <stdexcept>

lebedev::point_t findCenterOfParallelogram(const lebedev::point_t & p1, const lebedev::point_t & p2, const lebedev::point_t & p3)
{
  double center_y = (p1.y + p3.y) / 2;
  double center_x = 0;
  double width = std::abs(p2.x - p3.x) + std::abs(p1.x - p2.x);
  if (p1.y == p2.y)
  {
    if ((p1.x <= p2.x && p2.x <= p3.x) || (p1.x >= p2.x && p2.x >= p3.x))
    {
      center_x = (p1.x + p3.x) / 2;
    }
    else
    {
      if (p2.x <= p3.x)
      {
        center_x = p2.x + width / 2;
      }
      else
      {
        center_x = p2.x - width / 2;
      }
    }
  }
  else
  {
    if ((p1.x <= p2.x && p2.x <= p3.x) || (p1.x >= p2.x && p2.x >= p3.x))
    {
      center_x = (p1.x + p3.x) / 2;
    }
    else
    {
      if (p2.x <= p3.x)
      {
        center_x = p2.x + width / 2;
      }
      else
      {
        center_x = p2.x - width / 2;
      }
    }
  }
  return {center_x, center_y};
}

lebedev::Parallelogram::Parallelogram(const point_t & p1, const point_t & p2, const point_t & p3):
  p1_(p1),
  p2_(p2),
  p3_(p3)
{
  if (p1_.y != p2_.y && p2_.y != p3_.y)
  {
    throw std::invalid_argument("Error: invalid arguments for the Parallelogram");
  }
  if ((p1_.x == p2_.x && p1_.y == p2_.y) && (p1_.x == p3_.x && p1_.y == p3_.y) && (p2_.x == p3_.x && p2_.y == p3_.y))
  {
    throw std::invalid_argument("Error: invalid arguments for the Parallelogram");
  }
}
double lebedev::Parallelogram::getArea() const
{
  double a = 0;
  double h = 0;
  if (p1_.y == p2_.y)
  {
    a = std::abs(p1_.x - p2_.x);
    h = std::abs(p2_.y - p3_.y);
  }
  else
  {
    a = std::abs(p2_.x - p3_.x);
    h = std::abs(p1_.y - p2_.y);
  }
  return a * h;
}
lebedev::rectangle_t lebedev::Parallelogram::getFrameRect() const
{
  double width = std::abs(p2_.x - p3_.x) + std::abs(p1_.x - p2_.x);
  double height = 0;
  if (p1_.y == p2_.y)
  {
    height = std::abs(p2_.y - p3_.y);
  }
  else
  {
    height = std::abs(p1_.y - p2_.y);
  }
  point_t center = findCenterOfParallelogram(p1_, p2_, p3_);
  return {width, height, center};
}
void lebedev::Parallelogram::move(const point_t & p)
{
  point_t center = findCenterOfParallelogram(p1_, p2_, p3_);
  double dx = p.x - center.x;
  double dy = p.y - center.y;
  move(dx, dy);
}
void lebedev::Parallelogram::move(double dx, double dy)
{
  p1_.x += dx;
  p1_.y += dy;
  p2_.x += dx;
  p2_.y += dy;
  p3_.x += dx;
  p3_.y += dy;
}
void lebedev::Parallelogram::doScale(double ratio)
{
  point_t center = findCenterOfParallelogram(p1_, p2_, p3_);
  p1_ = scalePoint(p1_, center, ratio);
  p2_ = scalePoint(p2_, center, ratio);
  p3_ = scalePoint(p3_, center, ratio);
}
