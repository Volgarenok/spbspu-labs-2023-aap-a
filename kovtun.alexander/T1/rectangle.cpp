#include "rectangle.hpp"

kovtun::Rectangle::Rectangle(const kovtun::point_t & leftBottomCorner, const kovtun::point_t & rightTopCorner):
    leftBottomCorner_(leftBottomCorner),
    rightTopCorner_(rightTopCorner)
{}

double kovtun::Rectangle::getArea() const
{
  return (rightTopCorner_.x - leftBottomCorner_.x) * (rightTopCorner_.y - leftBottomCorner_.y);;
}

kovtun::rectangle_t kovtun::Rectangle::getFrameRect() const
{
  double width = rightTopCorner_.x - leftBottomCorner_.x;
  double height = rightTopCorner_.y - leftBottomCorner_.y;
  point_t position = { leftBottomCorner_.x + width / 2, rightTopCorner_.y - height / 2};
  rectangle_t frameRect = { width, height, position };

  return frameRect;
}

void kovtun::Rectangle::move(const kovtun::point_t & point)
{
  rectangle_t selfRect = getFrameRect();
  double dx = point.x - selfRect.pos.x;
  double dy = point.y - selfRect.pos.y;
  move(dx, dy);
}

void kovtun::Rectangle::move(double dx, double dy)
{
  leftBottomCorner_.x += dx;
  rightTopCorner_.x += dx;
  leftBottomCorner_.y += dy;
  rightTopCorner_.y += dy;
}

void kovtun::Rectangle::scale(double k)
{
  rectangle_t selfRect = getFrameRect();
  double halfWidth = rightTopCorner_.x - selfRect.pos.x;
  double halfHeight = rightTopCorner_.y - selfRect.pos.y;

  leftBottomCorner_.x -= halfWidth * (k - 1);
  rightTopCorner_.x += halfWidth * (k - 1);
  leftBottomCorner_.y -= halfHeight * (k - 1);
  rightTopCorner_.y += halfHeight * (k - 1);
}

