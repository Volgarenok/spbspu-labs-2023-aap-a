#include "square.hpp"
#include <stdexcept>

chistyakov::Square::Square(const point_t & leftDownCorner, double side):
  leftDownCorner_(leftDownCorner),
  side_(side)
{
  if (side <= 0.0)
  {
    throw std::invalid_argument("Invalid argument for side of the square");
  }
}

chistyakov::Square::~Square() = default;

double chistyakov::Square::getArea() const
{
  return side_ * side_;
}

chistyakov::rectangle_t chistyakov::Square::getFrameRect() const
{
  point_t pos = { side_/2.0 + leftDownCorner_.x, side_/2.0 + leftDownCorner_.y};
  return {side_, side_, pos};
}

void chistyakov::Square::move(const point_t & point)
{
  rectangle_t area = getFrameRect();
  double mx = point.x - area.pos.x;
  double my = point.y - area.pos.y;
  move(mx, my);
}

void chistyakov::Square::move(double mx, double my)
{
  leftDownCorner_.x += mx;
  leftDownCorner_.y += my;
}

void chistyakov::Square::scale(double ratio)
{
  if (ratio <= 0.0)
  {
    throw std::invalid_argument("Invalid argument for ratio");
  }

  leftDownCorner_.x -= (side_ * ratio - side_)/2.0;
  leftDownCorner_.y -= (side_ * ratio - side_)/2.0;
  side_ = side_ * ratio;
}
