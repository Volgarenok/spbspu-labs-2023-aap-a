#include "rectangle.hpp"
#include <stdexcept>

namestnikov::Rectangle::Rectangle(const point_t & leftAnglePoint, const point_t & rightAnglePoint)
{
  frameRect_.width = rightAnglePoint.x - leftAnglePoint.x;
  frameRect_.height = rightAnglePoint.y - leftAnglePoint.y;
  double posX = rightAnglePoint.x - frameRect_.width / 2;
  double posY = rightAnglePoint.y - frameRect_.width / 2;
  frameRect_.pos = {posX, posY};
}

double namestnikov::Rectangle::getArea() const
{
  return frameRect_.width * frameRect_.height;
}

namestnikov::rectangle_t namestnikov::Rectangle::getFrameRect() const
{
  return frameRect_;
}

void namestnikov::Rectangle::move(const point_t & p)
{
  frameRect_.pos = p;
}

void namestnikov::Rectangle::move(const double dx, const double dy)
{
  frameRect_.pos.x += dx;
  frameRect_.pos.y += dy;
}

void namestnikov::Rectangle::scale(const double coefficient)
{
  if (coefficient <= 0.0)
  {
    throw std::invalid_argument("Coefficient must be greater than zero\n");
  }
  else
  {
    frameRect_.width *= coefficient;
    frameRect_.height *= coefficient;
  }
}
