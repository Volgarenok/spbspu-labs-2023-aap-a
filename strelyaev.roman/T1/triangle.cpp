#include "triangle.hpp"
#include <cmath>
#include <algorithm>
#include <stdexcept>

strelyaev::Triangle::Triangle(point_t p1, point_t p2, point_t p3):
  p1_(p1),
  p2_(p2),
  p3_(p3)
{
  double determinant = p1_.x * (p2_.y - p3_.y) - p2_.x * (p1_.y - p3_.y) + p3_.x * (p1_.y - p2_.y);
  if (determinant == 0)
  {
    throw std::invalid_argument("Invalid points for TRIANGLE");
  }
}

double strelyaev::Triangle::getDistance(const point_t p1, const point_t p2) const
{
  return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}


double strelyaev::Triangle::getArea() const
{
  double a = Triangle::getDistance(p1_, p2_);
  double b = Triangle::getDistance(p2_, p3_);
  double c = Triangle::getDistance(p3_, p1_);
  double half_per = (a + b + c) / 2.0;
  return std::sqrt(half_per * (half_per - a) * (half_per - b) * (half_per - c));
}

strelyaev::rectangle_t strelyaev::Triangle::getFrameRect() const
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

void strelyaev::Triangle::move(const point_t point)
{
  double center_x = (p1_.x + p2_.x + p3_.x) / 3;
  double center_y = (p1_.y + p2_.y + p3_.y) / 3;
  point_t center = {center_x, center_y};
  double dx = point.x - center.x;
  double dy = point.y - center.y;
  this->move(dx, dy);
}



void strelyaev::Triangle::move(double offset_x, double offset_y)
{
  point_t* points[] = {&p1_, &p2_, &p3_};
  for (size_t i = 0; i < 3; i++)
  {
    points[i]->x += offset_x;
    points[i]->y += offset_y;
  }
}

void strelyaev::Triangle::unsafeScale(double k)
{
  double center_x = (p1_.x + p2_.x + p3_.x) / 3;
  double center_y = (p1_.y + p2_.y + p3_.y) / 3;
  point_t center = {center_x, center_y};
  point_t* points[] = {&p1_, &p2_, &p3_};
  for (size_t i = 0; i < 3; i++)
  {
    points[i]->x = center.x + (points[i]->x - center.x) * k;
    points[i]->y = center.y + (points[i]->y - center.y) * k;
  }
}

