#include "triangle.hpp"
#include <iostream>
#include <cmath>

namespace piyavkin
{
  Triangle::Triangle(point_t p1, point_t p2, point_t p3):
    a_(p1),
    b_(p2),
    c_(p3)
  {
    double ab = std::sqrt((a_.x - b_.x) * (a_.x - b_.x) + (a_.y - b_.y) * (a_.y - b_.y));
    double ac = std::sqrt((a_.x - c_.x) * (a_.x - c_.x) + (a_.y - c_.y) * (a_.y - c_.y));
    double bc = std::sqrt((b_.x - c_.x) * (b_.x - c_.x) + (b_.y - c_.y) * (b_.y - c_.y));
    if (ab >= ac + bc || bc >= ab + ac || ac >= ab + bc)
    {
      throw std::logic_error("It is not triangle");
    }
  }
  double Triangle::getArea()
  {
    double ab_ = std::sqrt((a_.x - b_.x) * (a_.x - b_.x) + (a_.y - b_.y) * (a_.y - b_.y));
    double ac_ = std::sqrt((a_.x - c_.x) * (a_.x - c_.x) + (a_.y - c_.y) * (a_.y - c_.y));
    double bc_ = std::sqrt((b_.x - c_.x) * (b_.x - c_.x) + (b_.y - c_.y) * (b_.y - c_.y));
    double semiperimeter = (ab_ + bc_ + ac_) / 2;
    return std::sqrt(semiperimeter * (semiperimeter - ab_) * (semiperimeter - bc_) * (semiperimeter - ac_));
  }
  rectangle_t Triangle::getFrameRect()
  {
    double heigth = (std::max(std::max(a_.y, b_.y), c_.y) - std::min(std::min(a_.y, b_.y), c_.y));
    double width = (std::max(std::max(a_.x, b_.x), c_.x) - std::min(std::min(a_.x, b_.x), c_.x));
    point_t pos = { std::min(std::min(a_.x, b_.x), c_.x) + width / 2, std::min(std::min(a_.y, b_.y), c_.y) + heigth / 2 };
    return { width, heigth, pos };
  }
  void Triangle::move(point_t bias)
  {
    point_t pos = { (a_.x + b_.x + c_.x) / 3, (a_.y + b_.y + c_.y) / 3 };
    move(bias.x - pos.x, bias.y - pos.y);
  }
  void Triangle::move(double dx, double dy)
  {
    point_t pos = { (a_.x + b_.x + c_.x) / 3, (a_.y + b_.y + c_.y) / 3 };
    pos.x += dx;
    pos.y += dy;
    a_.x += dx;
    a_.y += dy;
    b_.x += dx;
    b_.y += dy;
    c_.x += dx;
    c_.y += dy;
  }
  void Triangle::scale(double k)
  {
    point_t pos = { (a_.x + b_.x + c_.x) / 3, (a_.y + b_.y + c_.y) / 3 };
    a_.x = k * (a_.x - pos.x) + pos.x;
    a_.y = k * (a_.y - pos.y) + pos.y;
    b_.x = k * (b_.x - pos.x) + pos.x;
    b_.y = k * (b_.y - pos.y) + pos.y;
    c_.x = k * (c_.x - pos.x) + pos.x;
    c_.y = k * (c_.y - pos.y) + pos.y;
  }
}
