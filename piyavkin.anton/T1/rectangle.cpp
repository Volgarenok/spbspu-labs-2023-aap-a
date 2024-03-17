#include "rectangle.hpp"
#include <iostream>
#include "base-function.hpp"

piyavkin::Rectangle::Rectangle(const point_t& p1, const point_t& p2):
  lowerLeftCorner_(p1),
  topRightCorner_(p2)
{
  if (!(lowerLeftCorner_.x < topRightCorner_.x && lowerLeftCorner_.y < topRightCorner_.y))
  {
    throw std::logic_error("It is not rectangle");
  }
}
double piyavkin::Rectangle::getArea() const
{
  return std::abs((lowerLeftCorner_.x - topRightCorner_.x) * (lowerLeftCorner_.y - topRightCorner_.y));
}
piyavkin::rectangle_t piyavkin::Rectangle::getFrameRect() const
{
  point_t pos = {(lowerLeftCorner_.x + topRightCorner_.x) / 2, (lowerLeftCorner_.y + topRightCorner_.y) / 2};
  return {std::abs(lowerLeftCorner_.x - topRightCorner_.x), std::abs(lowerLeftCorner_.y - topRightCorner_.y), pos};
}
void piyavkin::Rectangle::move(const point_t& bias)
{
  point_t pos = {(lowerLeftCorner_.x + topRightCorner_.x) / 2, (lowerLeftCorner_.y + topRightCorner_.y) / 2};
  move(bias.x - pos.x, bias.y - pos.y);
}
void piyavkin::Rectangle::move(double dx, double dy)
{
  lowerLeftCorner_ = addShift(lowerLeftCorner_, dx, dy);
  topRightCorner_ = addShift(topRightCorner_, dx, dy);
}
void piyavkin::Rectangle::unsafeScale(double k)
{
  point_t pos = {(lowerLeftCorner_.x + topRightCorner_.x) / 2, (lowerLeftCorner_.y + topRightCorner_.y) / 2};
  lowerLeftCorner_ = scalePoint(lowerLeftCorner_, pos, k);
  topRightCorner_ = scalePoint(topRightCorner_, pos, k);
}
piyavkin::Shape* piyavkin::Rectangle::clone() const
{
  return new Rectangle(*this);
}

