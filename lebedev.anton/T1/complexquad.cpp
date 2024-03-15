#include "complexquad.hpp"
#include <stdexcept>

lebedev::Complexquad::Complexquad(const point_t & p1, const point_t & p2, const point_t & p3, const point_t & p4):
  p1_(p1),
  p2_(p2),
  p3_(p3),
  p4_(p4)
{
  if (!(checkLinesIntersection(p1_, p2_, p3_, p4_) && checkLinesIntersection(p2_, p1_, p4_, p3_)))
  {
    throw std::invalid_argument("Error: invalid arguments for the Complexquad");
  }
}
double lebedev::Complexquad::getArea() const
{
  point_t center = findLinesIntersection(p1_, p2_, p3_, p4_);
  double area = findAreaOfTriangle(p1_, p2_, center);
  area += findAreaOfTriangle(p3_, p4_, center);
  return area;
}
lebedev::rectangle_t lebedev::Complexquad::getFrameRect() const
{
  double high_point = std::max(std::max(std::max(p4_.y, p3_.y), p2_.y), p1_.y);
  double low_point = std::min(std::min(std::min(p4_.y, p3_.y), p2_.y), p1_.y);
  double left_point = std::min(std::min(std::min(p4_.x, p3_.x), p2_.x), p1_.x);
  double right_point = std::max(std::max(std::max(p4_.x, p3_.x), p2_.x), p1_.x);
  double center_x = (left_point + right_point) / 2;
  double center_y = (high_point + low_point) / 2;
  double width = right_point - left_point;
  double height = high_point - low_point;
  return {width, height, {center_x, center_y}};
}
void lebedev::Complexquad::move(const point_t & p)
{
  point_t center = findLinesIntersection(p1_, p2_, p3_, p4_);
  double dx = p.x - center.x;
  double dy = p.y - center.y;
  move(dx, dy);
}
void lebedev::Complexquad::move(double dx, double dy)
{
  p1_.x += dx;
  p1_.y += dy;
  p2_.x += dx;
  p2_.y += dy;
  p3_.x += dx;
  p3_.y += dy;
  p4_.x += dx;
  p4_.y += dy;
}
void lebedev::Complexquad::doScale(double ratio)
{
  point_t center = findLinesIntersection(p1_, p2_, p3_, p4_);
  p1_ = scalePoint(p1_, center, ratio);
  p2_ = scalePoint(p2_, center, ratio);
  p3_ = scalePoint(p3_, center, ratio);
  p4_ = scalePoint(p4_, center, ratio);
}
