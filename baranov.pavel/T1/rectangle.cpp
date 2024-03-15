#include "rectangle.hpp"
#include <stdexcept>

void baranov::pointScale(point_t & point, const point_t & center, double ratio)
{
  point.x += (ratio - 1) * (point.x - center.x);
  point.y += (ratio - 1) * (point.y - center.y);
}

baranov::Rectangle::Rectangle(const point_t & ldCorner, const point_t & ruCorner):
  ldCorner_(ldCorner),
  ruCorner_(ruCorner)
{
  if (ldCorner.x >= ruCorner.x || ldCorner.y >= ruCorner.y)
  {
    throw std::invalid_argument("Invalid rectangle parameters");
  }
}

double baranov::Rectangle::getArea() const
{
  return (ruCorner_.x - ldCorner_.x) * (ruCorner_.y - ldCorner_.y);
}

baranov::rectangle_t baranov::Rectangle::getFrameRect() const
{
  double height = ruCorner_.y - ldCorner_.y;
  double width = ruCorner_.x - ldCorner_.x;
  point_t pos = { ldCorner_.x + width / 2, ldCorner_.y + height / 2 };
  return { width, height, pos };
}

void baranov::Rectangle::move(const point_t & destPos)
{
  rectangle_t frameRect = getFrameRect();
  move(destPos.x - frameRect.pos.x, destPos.y - frameRect.pos.y);
}

void baranov::Rectangle::move(const double dx, const double dy)
{
  ruCorner_.x += dx;
  ruCorner_.y += dy;
  ldCorner_.x += dx;
  ldCorner_.y += dy;
}

void baranov::Rectangle::doScale(const double ratio)
{
  point_t center = getFrameRect().pos;
  pointScale(ruCorner_, center, ratio);
  pointScale(ldCorner_, center, ratio);
}

