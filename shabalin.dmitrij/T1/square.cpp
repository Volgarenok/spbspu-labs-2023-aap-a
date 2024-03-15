#include "square.hpp"

#include <stdexcept>

shabalin::Square::Square(const point_t &leftCorner, double lengthOfSide):
  leftCorner_(leftCorner),
  lengthOfSide_(lengthOfSide)
{
  if (lengthOfSide <= 0)
  {
    throw std::invalid_argument("Error: incorrect square parameters");
  }
}

shabalin::rectangle_t shabalin::Square::getFrameRect() const
{
  point_t rect = { leftCorner_.x + (lengthOfSide_ / 2), leftCorner_.y + (lengthOfSide_ / 2) };
  return { lengthOfSide_, lengthOfSide_, rect };
}

double shabalin::Square::getArea() const
{
  return lengthOfSide_ * lengthOfSide_;
}

void shabalin::Square::move(double del_x, double del_y)
{
  leftCorner_.x += del_x;
  leftCorner_.y += del_y;
}

void shabalin::Square::move(const point_t newCenter)
{
  rectangle_t newCenter_ = getFrameRect();
  move(newCenter.x - newCenter_.position.x, newCenter.y - newCenter_.position.y);
}

void shabalin::Square::scale(double scaling)
{
  if (scaling <= 0)
  {
    throw std::invalid_argument("Error scale must be a positive");
  }

  point_t rect = getFrameRect().position;
  lengthOfSide_ *= scaling;
  leftCorner_.x = rect.x - (lengthOfSide_ / 2);
  leftCorner_.y = rect.y - (lengthOfSide_ / 2);
}