#include "Parallelogram.hpp"
#include <cmath>

Parallelogram::Parallelogram(point_t p1, point_t p2, point_t p3):
  p1_(p1),
  p2_(p2),
  p3_(p3),
  p4_({p2_.x_ + p3_.x_ - p1_.x_, p2_.y_ + p3_.y_ - p1_.y_}),
  center_({(p1_.x_ + p3_.x_) / 2.0, (p1_.y_ + p3_.y_) / 2.0})
{}

double Parallelogram::getArea() const
{
  return std::abs((p1_.x_ * (p2_.y_ - p3_.y_) + p2_.x_ * (p3_.y_ - p1_.y_) + p3_.x_ * (p1_.y_ - p2_.y_)));
}
rectangle_t Parallelogram::getFrameRect()
{
  double up = std::max(p1_.y_, std::max(p2_.y_, p3_.y_));
  double down = std::min(p1_.y_, std::min(p2_.y_, p3_.y_));
  double left = std::min(p1_.x_, std::min(p2_.x_, p3_.x_));
  double right = std::max(p1_.x_, std::max(p2_.x_, p3_.x_));

  double center_x = (right + left) / 2.0;
  double center_y = (up + down) / 2.0;
  point_t r_center = {center_x, center_y};

  rectangle_t r1 = {up - down, right - left, r_center};
  return r1;
}
void Parallelogram::move(point_t new_center)
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
void Parallelogram::move(double k)
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

void Parallelogram::move(double dx, double dy)
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

void Parallelogram::scale(double k)
{
  p1_.x_ = center_.x_ + (p1_.x_ - center_.x_) * k;
  p1_.y_ = center_.y_ + (p1_.y_ - center_.y_) * k;

  p2_.x_ = center_.x_ + (p2_.x_ - center_.x_) * k;
  p2_.y_ = center_.y_ + (p2_.y_ - center_.y_) * k;

  p3_.x_ = center_.x_ + (p3_.x_ - center_.x_) * k;
  p3_.y_ = center_.y_ + (p3_.y_ - center_.y_) * k;
}