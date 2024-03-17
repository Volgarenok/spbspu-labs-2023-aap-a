#include "rectangle.hpp"
#include <stdexcept>
#include "pointLogic.hpp"

grechishnikov::Rectangle::Rectangle(const point_t& dLeft, const point_t& uRight):
  points_{ dLeft, uRight },
  size_(2)
{
  if (dLeft.x >= uRight.x || dLeft.y >= uRight.y)
  {
    throw std::invalid_argument("Invalid parameters (Points were entered incorrectly)");
  }
}

double grechishnikov::Rectangle::getArea() const
{
  return (points_[1].x - points_[0].x) * (points_[1].y - points_[0].y);
}

grechishnikov::rectangle_t grechishnikov::Rectangle::getFrameRect() const
{
  return getFrameRectGeneral(points_, size_);
}

void grechishnikov::Rectangle::move(const point_t& pos)
{
  point_t aPos = getAveragePoint(points_, size_);
  double dx = pos.x - aPos.x;
  double dy = pos.y - aPos.y;
  move(dx, dy);
}

void grechishnikov::Rectangle::move(double dx, double dy)
{
  movePoints(points_, size_, dx, dy);
}

void grechishnikov::Rectangle::unsafeScale(double rate)
{
  unsafeScalePoints(points_, size_, rate);
}
