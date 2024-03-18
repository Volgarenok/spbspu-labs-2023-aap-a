#include "rectangle.hpp"

#include <stdexcept>

chistyakov::Rectangle::Rectangle(const point_t & leftDownCorner, const point_t & rightUpCorner):
  leftDownCorner_(leftDownCorner),
  rightUpCorner_(rightUpCorner)
{
  if (leftDownCorner.x >= rightUpCorner.x && leftDownCorner.y >= rightUpCorner.y)
  {
    throw std::invalid_argument("Invalid argument for rectangle");
  }
}

chistyakov::Rectangle::~Rectangle() = default;

double chistyakov::Rectangle::getArea() const
{
  rectangle_t area = getFrameRect();
  return area.width * area.height;
}

chistyakov::rectangle_t chistyakov::Rectangle::getFrameRect() const
{
  double width = rightUpCorner_.x - leftDownCorner_.x;
  double height = rightUpCorner_.y - leftDownCorner_.y;
  point_t pos = { width/2.0 + leftDownCorner_.x, height/2.0 + leftDownCorner_.y};
  return {width, height, pos};
}

void chistyakov::Rectangle::move(const point_t & point)
{
  rectangle_t area = getFrameRect();
  double mx = point.x - area.pos.x;
  double my = point.y - area.pos.y;
  move(mx, my);
}

void chistyakov::Rectangle::move(double mx, double my)
{
  leftDownCorner_.x += mx;
  leftDownCorner_.y += my;
  rightUpCorner_.x += mx;
  rightUpCorner_.y += my;
}

void chistyakov::Rectangle::scale(double ratio)
{
  if (ratio <= 0)
  {
    throw std::invalid_argument("Invalid argument for ratio");
  }

  rectangle_t area = getFrameRect();
  leftDownCorner_.x -= (area.width * ratio - area.width) / 2.0;
  leftDownCorner_.y -= (area.height * ratio - area.height) / 2.0;
  rightUpCorner_.x += (area.width * ratio - area.width) / 2.0;
  rightUpCorner_.y += (area.height * ratio - area.height) / 2.0;
}
