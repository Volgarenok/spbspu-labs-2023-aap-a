#include "rectangle.hpp"
#include <stdexcept>
#include "othersFun.hpp"

sivkov::Rectangle::Rectangle(const point_t leftBottom, const  point_t rightTop):
  leftBottom_(leftBottom),
  rightTop_(rightTop)
{
  if (leftBottom_.x >= rightTop_.x || leftBottom_.y >= rightTop_.y)
  {
    throw std::invalid_argument("Invalid rectangle coordinates");
  }
}

double sivkov::Rectangle::getArea() const
{
  return getFrameRect().width * getFrameRect().height;;
}

sivkov::rectangle_t sivkov::Rectangle::getFrameRect() const
{
  point_t pos = calculateVector(leftBottom_, rightTop_);
  point_t center = { (leftBottom_.x + rightTop_.x) / 2, (leftBottom_.y + rightTop_.y) / 2 };
  return { center, pos.x, pos.y };
}

void sivkov::Rectangle::move(const point_t newPos)
{
  point_t center = { (leftBottom_.x + rightTop_.x) / 2, (leftBottom_.y + rightTop_.y) / 2 };
  double dx = newPos.x - center.x;
  double dy = newPos.y - center.y;
  move(dx, dy);
}

void sivkov::Rectangle::move(const double dx, const double dy)
{
  point_t newXY = { dx, dy };
  leftBottom_ = shift(newXY, leftBottom_);
  rightTop_ = shift(newXY, rightTop_);
}

void sivkov::Rectangle::scale(const double k)
{
  if (k <= 0.0)
  {
    throw std::invalid_argument("k must be > 0\n");
  }
  point_t pos = getFrameRect().pos;
  double newWidth = (rightTop_.x - leftBottom_.x) * k;
  double newHeight = (rightTop_.y - leftBottom_.y) * k;
  leftBottom_ = { pos.x - newWidth / 2, pos.y - newHeight / 2 };
  rightTop_ = { pos.x + newWidth / 2, pos.y + newHeight / 2 };
}

