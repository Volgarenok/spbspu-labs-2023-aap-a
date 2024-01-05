#include "triangle.hpp"
#include <cmath>
#include <algorithm>

Triangle::Triangle(point_t p1, point_t p2, point_t p3):
  p1_(p1),
  p2_(p2),
  p3_(p3),
  center_({(p1.x_ + p2.x_ + p3.x_) / 3, (p1.y_ + p2.y_ + p3.y_) / 3})
{}

double Triangle::getDistance(const point_t p1, const point_t p2) const
{
  return std::sqrt(std::pow(p2.x_ - p1.x_, 2) + std::pow(p2.y_ - p1.y_, 2));
}


double Triangle::getArea() const
{
  double a = Triangle::getDistance(p1_, p2_);
  double b = Triangle::getDistance(p2_, p3_);
  double c = Triangle::getDistance(p3_, p1_);
  double half_per = (a + b + c) / 2.0;
  return std::sqrt(half_per * (half_per - a) * (half_per - b) * (half_per - c));
}

rectangle_t Triangle::getFrameRect()
{
  double up = std::max(p1_.y_, std::max(p2_.y_, p3_.y_));
  double down = std::min(p1_.y_, std::min(p2_.y_, p3_.y_));
  double left = std::min(p1_.x_, std::min(p2_.x_, p3_.x_));
  double right = std::max(p1_.x_, std::max(p2_.x_, p3_.x_));

  double center_x = (right + left) / 2.0;
  double center_y = (up + down) / 2.0;
  point_t r_center = {center_x, center_y};

  rectangle_t r1 = {right - left, up - down, r_center};
  return r1;
}

void Triangle::move(point_t new_center)
{
  double offset_x = new_center.x_ - center_.x_;
  double offset_y = new_center.y_ - center_.y_;

  p1_.x_ += offset_x;
  p1_.y_ += offset_y;

  p2_.x_ += offset_x;
  p2_.y_ += offset_y;

  p3_.x_ += offset_x;
  p3_.y_ += offset_y;

  center_ = new_center;
}

void Triangle::move(double k)
{
  center_.x_ += k;
  center_.y_ += k;
  p1_.x_ += k;
  p1_.y_ += k;
  p2_.x_ += k;
  p2_.y_ += k;
  p3_.x_ += k;
  p3_.y_ += k;
}

void Triangle::move(double dx, double dy)
{
  center_.x_ += dx;
  center_.y_ += dy;
  p1_.x_ += dx;
  p1_.y_ += dy;
  p2_.x_ += dx;
  p2_.y_ += dy;
  p3_.x_ += dx;
  p3_.y_ += dy;

}

void Triangle::scale(double k)
{
  p1_.x_ = center_.x_ + (p1_.x_ - center_.x_) * k;
  p1_.y_ = center_.y_ + (p1_.y_ - center_.y_) * k;

  p2_.x_ = center_.x_ + (p2_.x_ - center_.x_) * k;
  p2_.y_ = center_.y_ + (p2_.y_ - center_.y_) * k;

  p3_.x_ = center_.x_ + (p3_.x_ - center_.x_) * k;
  p3_.y_ = center_.y_ + (p3_.y_ - center_.y_) * k;
}