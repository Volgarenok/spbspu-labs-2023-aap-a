#include "rectangle.hpp"
#include <stdexcept>


marishin::Rectangle::Rectangle(const point_t lowerLeftCorner, const point_t topRightCorner):
  lowerLeftCorner_(lowerLeftCorner),
  topRightCorner_(topRightCorner)
{
  if (!(((lowerLeftCorner_.x < topRightCorner_.x) && (lowerLeftCorner_.y < topRightCorner_.y))
    || ((lowerLeftCorner_.x > topRightCorner_.x) && (lowerLeftCorner_.y > topRightCorner_.y))))
  {
    throw std::logic_error("Invalid rectangle");
  }
}

marishin::Rectangle::~Rectangle()
{
}

double marishin::Rectangle::getArea()
{
  return (std::abs((lowerLeftCorner_.x - topRightCorner_.x) * (lowerLeftCorner_.y - topRightCorner_.y)));
}

rectangle_t marishin::Rectangle::getFrameRect()
{
  point_t pos = { ((lowerLeftCorner_.x + topRightCorner_.x) / 2), ((lowerLeftCorner_.y + topRightCorner_.y) / 2) };
  double width_t = std::abs(lowerLeftCorner_.x - topRightCorner_.x);
  double height_t = std::abs(lowerLeftCorner_.y - topRightCorner_.y);
  return { pos, width_t, height_t };
}

void marishin::Rectangle::move(const point_t newPos)
{
  point_t pos = { ((lowerLeftCorner_.x + topRightCorner_.x) / 2), ((lowerLeftCorner_.y + topRightCorner_.y) / 2) };
  move(newPos.x - pos.x, newPos.y - pos.y);
}

void marishin::Rectangle::move(const double dx, const double dy)
{
  lowerLeftCorner_.x += dx;
  lowerLeftCorner_.y += dy;
  topRightCorner_.x += dx;
  topRightCorner_.y += dy;
}

void marishin::Rectangle::scale(const double factor)
{
  point_t pos = { ((lowerLeftCorner_.x + topRightCorner_.x) / 2), ((lowerLeftCorner_.y + topRightCorner_.y) / 2) };
  lowerLeftCorner_.x = topRightCorner_.x - (topRightCorner_.x - lowerLeftCorner_.x) * factor;
  lowerLeftCorner_.y = topRightCorner_.y - (topRightCorner_.y - lowerLeftCorner_.y) * factor;
  topRightCorner_.x = lowerLeftCorner_.x + (topRightCorner_.x - lowerLeftCorner_.x) * factor;
  topRightCorner_.y = lowerLeftCorner_.y + (topRightCorner_.y - lowerLeftCorner_.y) * factor;
}
