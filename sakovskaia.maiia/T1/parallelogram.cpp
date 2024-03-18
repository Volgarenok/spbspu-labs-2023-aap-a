#include "parallelogram.hpp"
#include <cmath>

sakovskaia::Parallelogram::Parallelogram(point_t p1, point_t p2, point_t p3):
  p1_(p1),
  p2_(p2),
  p3_(p3)
{}

double sakovskaia::Parallelogram::getArea() const
{
  return std::abs((p1_.x * (p2_.y - p3_.y) + p2_.x * (p3_.y - p1_.y) + p3_.x * (p1_.y - p2_.y)));
}

sakovskaia::rectangle_t
sakovskaia::Parallelogram::getFrameRect() const
{
  double u = std::max(p1_.y, std::max(p2_.y, p3_.y));
  double d = std::min(p1_.y, std::min(p2_.y, p3_.y));
  double r = std::max(p1_.x, std::max(p2_.x, p3_.x));
  double l = std::min(p1_.x, std::min(p2_.x, p3_.x));
  point_t p_p1 = {l, d};
  point_t p_p2 = {l, u};
  point_t p_p3 = {r, u};
  point_t p_p4 = {r, d};
  double height = u - d;
  double width = r - l;
  double p_center_x = (p_p1.x + p_p2.x + p_p3.x + p_p4.x) / 4;
  double p_center_y = (p_p1.y + p_p2.y + p_p3.y + p_p4.y) / 4;
  point_t p_center = {p_center_x, p_center_y};
  rectangle_t parallelogram = {width, height, p_center};
  return parallelogram;
}

