#include "rectangle.hpp"
#include <iostream>

namespace piyavkin
{
  Rectangle::Rectangle(point_t p1, point_t p2):
    p1_(p1),
    p2_(p2)
  {
    if (!((p1_.x < p2_.x && p1_.y < p2_.y) || (p1_.x > p2_.x && p1_.y > p2_.y)))
    {
      throw std::logic_error("It is not rectangle");
    }
  }
  double Rectangle::getArea()
  {
    return std::abs((p1_.x - p2_.x) * (p1_.y - p2_.y));
  }
  rectangle_t piyavkin::Rectangle::getFrameRect()
  {
    point_t pos = { (p1_.x + p2_.x) / 2, (p1_.y + p2_.y) / 2 };
    return { std::abs(p1_.x - p2_.x), std::abs(p1_.y - p2_.y), pos };
  }
  void Rectangle::move(point_t bias)
  {
    point_t pos = { (p1_.x + p2_.x) / 2, (p1_.y + p2_.y) / 2 };
    move(bias.x - pos.x, bias.y - pos.y);
  }
  void Rectangle::move(double dx, double dy)
  {
    p1_.x += dx;
    p1_.y += dy;
    p2_.x += dx;
    p2_.y += dy;
  }
  void piyavkin::Rectangle::scale(double k)
  {
    point_t pos = { (p1_.x + p2_.x) / 2, (p1_.y + p2_.y) / 2 };
    p1_.x = k * (pos.x - p1_.x);
    p2_.x = k * (pos.x - p2_.x);
    p1_.y = k * (pos.y - p1_.y);
    p2_.y = k * (pos.y - p2_.y);
  }
}
