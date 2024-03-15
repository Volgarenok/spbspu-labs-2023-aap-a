#include "rectangle.hpp"

#include <stdexcept>
#include "base-types.hpp"

arakelyan::Rectangle::Rectangle(point_t fp, point_t sp):
  pointRightUp_(sp),
  pointLeftDown_(fp)
{
  if (pointLeftDown_.y > pointRightUp_.y || pointLeftDown_.x > pointRightUp_.x)
  {
    throw std::logic_error("Invalid arguments!");
  }
}

double arakelyan::Rectangle::getArea() const
{
  double width = pointRightUp_.x - pointLeftDown_.x;
  double height = pointRightUp_.y - pointLeftDown_.y;
  return width * height;
}

arakelyan::rectangle_t arakelyan::Rectangle::getFrameRect() const
{
  double width = std::abs(pointRightUp_.x - pointLeftDown_.x);
  double height = std::abs(pointRightUp_.y - pointLeftDown_.y);
  point_t midpoint = {((pointRightUp_.x + pointLeftDown_.x) / 2), ((pointRightUp_.y + pointLeftDown_.y) / 2)};
  return {width, height, midpoint};
}

void arakelyan::Rectangle::move(const point_t point)
{
  rectangle_t data = getFrameRect();
  double delX = point.x - data.pos.x;
  double delY = point.y - data.pos.y;
  move(delX, delY);
}

void arakelyan::Rectangle::move(const double delX, const double delY)
{
  point_t * pointsArray[2] = {&pointLeftDown_, &pointRightUp_};
  for (size_t i = 0; i < 2; i++)
  {
    pointsArray[i]->x += delX;
    pointsArray[i]->y += delY;
  }
}

void arakelyan::Rectangle::scaleShape(const double k)
{
  rectangle_t data = getFrameRect();
  double widthWithScale = data.width * k;
  double heightWithScale = data.height * k;
  double widthHalf = widthWithScale / 2.0;
  double heightHalf = heightWithScale / 2.0;
  pointLeftDown_.x = data.pos.x - widthHalf;
  pointLeftDown_.y = data.pos.y - heightHalf;
  pointRightUp_.x = data.pos.x + widthHalf;
  pointRightUp_.y = data.pos.y + heightHalf;
}
