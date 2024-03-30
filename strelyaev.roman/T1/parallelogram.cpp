#include "parallelogram.hpp"
#include <cmath>
#include <algorithm>
#include <stdexcept>

strelyaev::Parallelogram::Parallelogram(point_t p1, point_t p2, point_t p3):
  p1_(p1),
  p2_(p2),
  p3_(p3)
{
  double determinant = this->getArea();
  if (determinant == 0)
  {
    throw std::invalid_argument("Invalid points for PARALLELOGRAM: Not a triangle");
  }
  if (!((p1_.y == p2_.y) || (p1_.y == p3_.y) || (p2_.y == p3_.y)))
  {
    throw std::invalid_argument("Invalid points for PARALLELOGRAM: Sides are not parallel to axis");
  }
}

double strelyaev::Parallelogram::getArea() const
{
  return std::abs((p1_.x * (p2_.y - p3_.y) + p2_.x * (p3_.y - p1_.y) + p3_.x * (p1_.y - p2_.y)));
}

strelyaev::rectangle_t strelyaev::Parallelogram::getFrameRect() const
{
  double up = std::max(p1_.y, std::max(p2_.y, p3_.y));
  double down = std::min(p1_.y, std::min(p2_.y, p3_.y));
  double right = std::max(p1_.x, std::max(p2_.x, p3_.x));
  double left = std::min(p1_.x, std::min(p2_.x, p3_.x));
  point_t r_p1 = {left, down};
  point_t r_p2 = {left, up};
  point_t r_p3 = {right, up};
  point_t r_p4 = {right, down};
  double height = up - down;
  double width = right - left;
  double r_center_x = (r_p1.x + r_p2.x + r_p3.x + r_p4.x) / 4;
  double r_center_y = (r_p1.y + r_p2.y + r_p3.y + r_p4.y) / 4;
  point_t r_center = {r_center_x, r_center_y};
  rectangle_t rect = {width, height, r_center};
  return rect;
}

void strelyaev::Parallelogram::move(const point_t new_center)
{
  point_t center = {(p1_.x + p2_.x + p3_.x) / 3, (p1_.y + p2_.y + p3_.y) / 3};
  double offset_x = new_center.x - center.x;
  double offset_y = new_center.y - center.y;
  this->move(offset_x, offset_y);
}

void strelyaev::Parallelogram::move(double dx, double dy)
{
  point_t* points[] = {&p1_, &p2_, &p3_};
  for (size_t i = 0; i < 3; i++)
  {
    points[i]->x += dx;
    points[i]->y += dy;
  }
}

void strelyaev::Parallelogram::unsafeScale(double k)
{
  point_t center = {(p1_.x + p2_.x + p3_.x) / 3, (p1_.y + p2_.y + p3_.y) / 3};
  point_t* points[] = {&p1_, &p2_, &p3_};
  for (size_t i = 0; i < 3; i++)
  {
    points[i]->x = center.x + (points[i]->x - center.x) * k;
    points[i]->y = center.y + (points[i]->y - center.y) * k;
  }
}


