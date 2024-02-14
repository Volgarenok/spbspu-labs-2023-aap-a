#include "rectangle.hpp"
#include <stdexcept>

Rectangle::Rectangle(point_t leftBottom, point_t rightTop) :
  leftBottom_(leftBottom),
  rightTop_(rightTop)
{
  if (leftBottom_.x >= rightTop_.x || leftBottom_.y >= rightTop_.y)
  {
    throw std::invalid_argument("Invalid rectangle coordinates");
  }
}

double Rectangle::getArea() const
{
  double area = getFrameRect().width * getFrameRect().height;
  return area;
}

rectangle_t Rectangle::getFrameRect() const
{
  double width = rightTop_.x - leftBottom_.x;
  if (width < 0)
  {
    width = width * -1;
  }
  double height = rightTop_.y - leftBottom_.y;
  if (height < 0)
  {
    height = height * -1;
  }
  point_t center = { (leftBottom_.x + rightTop_.x) / 2, (leftBottom_.y + rightTop_.y) / 2 };
  return { center, width, height };
}

void Rectangle::move(point_t newPos)
{
  point_t center = { (leftBottom_.x + rightTop_.x) / 2, (leftBottom_.y + rightTop_.y) / 2 };
  double dx = newPos.x - center.x;
  double dy = newPos.y - center.y;
  move(dx, dy);
}

void Rectangle::move(double dx, double dy)
{
  leftBottom_.x += dx;
  leftBottom_.y += dy;
  rightTop_.x += dx;
  rightTop_.y += dy;
}

void Rectangle::scale(double factor)
{
  if (factor > 0)
  {
    point_t pos = getFrameRect().pos;
    double newWidth = (rightTop_.x - leftBottom_.x) * factor;
    double newHeight = (rightTop_.y - leftBottom_.y) * factor;
    leftBottom_ = { pos.x - newWidth / 2, pos.y - newHeight / 2 };
    rightTop_ = { pos.x + newWidth / 2, pos.y + newHeight / 2 };
  }
}