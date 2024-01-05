#include "rectangle.hpp"
#include <cmath>

#include "rectangle.hpp"
#include <cmath>

Rectangle::Rectangle(point_t p1, point_t p2):
  p1_(p1),
  p2_(p2),
  center_({(p1_.x_ + p2_.x_) / 2, (p1_.y_ + p2_.y_) / 2})
{}

double Rectangle::getArea() const
{
  double height = std::abs(p1_.y_ - p2_.y_);
  double width = std::abs(p1_.x_ - p2_.x_);
  return height * width;
}

rectangle_t Rectangle::getFrameRect()
{
  double height = std::abs(p1_.y_ - p2_.y_);
  double width = std::abs(p1_.x_ - p2_.x_);
  rectangle_t r1 = {width, height, center_};
  return r1;
}

void Rectangle::move(point_t new_center)
{
  double offset_x = new_center.x_ - center_.x_;
  double offset_y = new_center.y_ - center_.y_;
  p1_.x_ += offset_x;
  p1_.y_ += offset_y;
  p2_.x_ += offset_x;
  p2_.y_ += offset_y;
  center_ = new_center;
}

void Rectangle::move(double k)
{
  center_.x_ += k;
  center_.y_ += k;
  p1_.x_ += k;
  p1_.y_ += k;
  p2_.x_ += k;
  p2_.y_ += k;
}

void Rectangle::move(double dx, double dy)
{
  center_.x_ += dx;
  center_.y_ += dy;
  p1_.x_ += dx;
  p1_.y_ += dy;
  p2_.x_ += dx;
  p2_.y_ += dy;
}

void Rectangle::scale(double k)
{
  double width = std::abs(p1_.x_ - p2_.x_);
  double height = std::abs(p1_.y_ - p2_.y_);

  double new_width = width * k;
  double new_height = height * k;

  double offset_x = (new_width - width) / 2.0;
  double offset_y = (new_height - height) / 2.0;
  p1_.x_ -= offset_x;
  p1_.y_ -= offset_y;
  p2_.x_ += offset_x;
  p2_.y_ += offset_y;
}
