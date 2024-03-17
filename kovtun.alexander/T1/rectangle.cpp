#include "rectangle.h"

kovtun::Rectangle::Rectangle(kovtun::point_t leftBottomCorner, kovtun::point_t rightTopCorner):
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

void kovtun::Rectangle::move(kovtun::point_t point)
{

}

void kovtun::Rectangle::move(double dx, double dy)
{

}

void kovtun::Rectangle::scale(double k)
{

}
