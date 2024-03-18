#include "diamond.hpp"
#include <stdexcept>
#include <cmath>
#include "base-types.hpp"

agarkov::Diamond::Diamond(point_t point1, point_t point2, point_t center):
  point1_(point1),
  point2_(point2),
  center_(center)
{
  if (!isCorrectDiamond())
  {
    throw std::invalid_argument("Incorrect diamond argument");
  }
}

double agarkov::Diamond::getArea() const
{
  return (std::fabs(point2_.x - center_.x)) * (std::fabs(point1_.y - center_.y)) * 2;
}

agarkov::rectangle_t agarkov::Diamond::getFrameRect() const
{
  return {center_, (std::fabs(point2_.x - center_.x)) * 2, (std::fabs(point1_.y - center_.y)) * 2};
}

void agarkov::Diamond::move(double dx, double dy)
{
  point1_.move(dx, dy);
  point2_.move(dx, dy);
  center_.move(dx, dy);
}

void agarkov::Diamond::move(agarkov::point_t position)
{
  double dx = position.x - center_.x;
  double dy = position.y - center_.y;
  move(dx, dy);
}

void agarkov::Diamond::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Incorrect scale coefficient");
  }
  point1_.unsaveScale(center_, k);
  point2_.unsaveScale(center_, k);
}

bool agarkov::Diamond::isCorrectDiamond() const
{
  return (center_.x == point1_.x) && (center_.y == point2_.y);
}
