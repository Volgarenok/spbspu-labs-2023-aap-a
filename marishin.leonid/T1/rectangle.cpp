#include "rectangle.hpp"
#include <stdexcept>
#include <cmath>

marishin::Rectangle::Rectangle(const point_t& lowerLeftCorner, const point_t& topRightCorner):
  lowerLeftCorner_(lowerLeftCorner),
  topRightCorner_(topRightCorner)
{
  if (!((topRightCorner.y >= lowerLeftCorner.y) && (topRightCorner.x >= lowerLeftCorner.x)))
  {
    throw std::invalid_argument("Invalid rectangle");
  }
}

double marishin::Rectangle::getArea() const
{
  return (topRightCorner_.x - lowerLeftCorner_.x) * (topRightCorner_.y - lowerLeftCorner_.y);
}

marishin::rectangle_t marishin::Rectangle::getFrameRect() const
{
  point_t pos = { ((lowerLeftCorner_.x + topRightCorner_.x) / 2), ((lowerLeftCorner_.y + topRightCorner_.y) / 2) };
  double width_t = topRightCorner_.x - lowerLeftCorner_.x;
  double height_t = topRightCorner_.y - lowerLeftCorner_.y;
  return { pos, width_t, height_t };
}

void marishin::Rectangle::move(const point_t& newPos)
{
  rectangle_t f = getFrameRect();;
  move(newPos.x - f.pos.x, newPos.y - f.pos.y);
}

void marishin::Rectangle::move(double dx, double dy)
{
  lowerLeftCorner_ = mixPoint(lowerLeftCorner_, dx, dy);
  topRightCorner_ = mixPoint(topRightCorner_, dx, dy);
}

void marishin::Rectangle::unsafeScale(double factor)
{
  point_t pos = { ((lowerLeftCorner_.x + topRightCorner_.x) / 2), ((lowerLeftCorner_.y + topRightCorner_.y) / 2) };
  lowerLeftCorner_ = scalePoint(lowerLeftCorner_, pos, factor);
  topRightCorner_ = scalePoint(topRightCorner_, pos, factor);
}
