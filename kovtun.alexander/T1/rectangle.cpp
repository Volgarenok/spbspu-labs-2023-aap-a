#include "rectangle.h"

kovtun::Rectangle::Rectangle(kovtun::point_t leftBottomCorner, kovtun::point_t rightTopCorner):
    leftBottomCorner_(leftBottomCorner),
    rightTopCorner_(rightTopCorner)
{}

double kovtun::Rectangle::getArea() const
{
  return 0;
}

kovtun::rectangle_t kovtun::Rectangle::getFrameRect() const
{
  return rectangle_t();
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
