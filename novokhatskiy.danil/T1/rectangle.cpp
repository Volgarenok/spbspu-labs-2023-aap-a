#include "rectangle.hpp"
#include <stdexcept>

novokhatskiy::Rectangle::Rectangle(const point_t &leftCorner, const point_t &rightCorner):
  leftCorner_(leftCorner),
  rightCorner_(rightCorner)
{
  if (!((rightCorner.y >= leftCorner.y) && (rightCorner.x >= leftCorner.x)))
  {
    throw std::invalid_argument("Wrong arguments of the rectangle");
  }
}
double novokhatskiy::Rectangle::getArea() const
{
  return (rightCorner_.x - leftCorner_.x) * (rightCorner_.y - leftCorner_.y);
}
novokhatskiy::rectangle_t novokhatskiy::Rectangle::getFrameRect() const
{
  double width = rightCorner_.x - leftCorner_.x;
  double height = rightCorner_.y - leftCorner_.y;
  point_t center = {leftCorner_.x + width / 2, leftCorner_.y + height / 2};
  return {width, height, center};
}
void novokhatskiy::Rectangle::move(const point_t &p)
{
  point_t center = {((rightCorner_.x + leftCorner_.x) / 2), ((rightCorner_.y + leftCorner_.y) / 2)};
  point_t moveVec = {p.x - center.x, p.y - center.y};
  leftCorner_.x += moveVec.x;
  leftCorner_.y += moveVec.y;
  rightCorner_.x += moveVec.x;
  rightCorner_.y += moveVec.y;
}
void novokhatskiy::Rectangle::move(double x, double y)
{
  leftCorner_.x += x;
  leftCorner_.y += y;
  rightCorner_.x += x;
  rightCorner_.y += y;
}
void novokhatskiy::Rectangle::scale(double ratio)
{
  point_t center = {((rightCorner_.x + leftCorner_.x) / 2), ((rightCorner_.y + leftCorner_.y) / 2)};
  leftCorner_.x += (leftCorner_.x - center.x) * (ratio - 1);
  leftCorner_.y += (leftCorner_.y - center.y) * (ratio - 1);
  rightCorner_.x += (rightCorner_.x - center.x) * (ratio - 1);
  rightCorner_.y += (rightCorner_.y - center.y) * (ratio - 1);
}
