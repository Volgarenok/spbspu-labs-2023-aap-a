#include "diamond.hpp"
#include <cmath>
#include <stdexcept>

nikitov::Diamond::Diamond(point_t& firstPoint, point_t& secondPoint, point_t& thirdPoint):
  firstPoint_(firstPoint),
  secondPoint_(secondPoint),
  thirdPoint_(thirdPoint)
{
  bool status = (firstPoint_.x - secondPoint_.x == 0 || firstPoint_.y - secondPoint_.y == 0);
  status = (firstPoint_.x - thirdPoint_.x == 0 || firstPoint_.y - thirdPoint_.y == 0) && status;
  status = (secondPoint_.x - thirdPoint_.x == 0 || secondPoint_.y - thirdPoint_.y == 0) && status;
  if (!status)
  {
    throw std::invalid_argument("Error: invalid diamond arguments");
  }
}

double nikitov::Diamond::getArea()
{
  rectangle_t frame = getFrameRect();
  return frame.width * frame.height / 2;
}

nikitov::rectangle_t nikitov::Diamond::getFrameRect()
{
  double width = 0;
  double height = 0;
  point_t center;
  if (firstPoint_.x - secondPoint_.x == 0)
  {
    height = abs(firstPoint_.y - secondPoint_.y) * 2;
    width = abs(firstPoint_.x - thirdPoint_.x) * 2;
    if (firstPoint_.y - thirdPoint_.y == 0)
    {
      center = firstPoint_;
    }
    else
    {
      center = secondPoint_;
    }
  }
  else if (firstPoint_.x - thirdPoint_.x == 0)
  {
    height = abs(firstPoint_.y - thirdPoint_.y) * 2;
    width = abs(firstPoint_.x - secondPoint_.x) * 2;
    if (firstPoint_.y - secondPoint_.y == 0)
    {
      center = firstPoint_;
    }
    else
    {
      center = thirdPoint_;
    }
  }
  else
  {
    height = abs(secondPoint_.y - thirdPoint_.y) * 2;
    width = abs(firstPoint_.x - secondPoint_.x) * 2;
    if (secondPoint_.y - firstPoint_.y == 0)
    {
      center = secondPoint_;
    }
    else
    {
      center = thirdPoint_;
    }
  }
  return { height, width, center };
}

void nikitov::Diamond::move(const point_t& point)
{
  point_t center = getFrameRect().pos;
  double dx = point.x - center.x;
  double dy = point.y - center.y;
  move(dx, dy);
}

void nikitov::Diamond::move(double dx, double dy)
{
  firstPoint_.x += dx;
  firstPoint_.y += dy;
  secondPoint_.x += dx;
  secondPoint_.y += dy;
  thirdPoint_.x += dx;
  thirdPoint_.y += dy;
}

void nikitov::Diamond::scale(double ratio)
{
  point_t center = getFrameRect().pos;
  if (firstPoint_.x == center.x && firstPoint_.y == center.y)
  {
    secondPoint_.x = center.x - (center.x - secondPoint_.x) * ratio;
    secondPoint_.y = center.y - (center.y - secondPoint_.y) * ratio;
    thirdPoint_.x = center.x - (center.x - thirdPoint_.x) * ratio;
    thirdPoint_.y = center.y - (center.y - thirdPoint_.y) * ratio;
  }
  else if (secondPoint_.x == center.x && secondPoint_.y == center.y)
  {
    firstPoint_.x = center.x - (center.x - firstPoint_.x) * ratio;
    firstPoint_.y = center.y - (center.y - firstPoint_.y) * ratio;
    thirdPoint_.x = center.x - (center.x - thirdPoint_.x) * ratio;
    thirdPoint_.y = center.y - (center.y - thirdPoint_.y) * ratio;
  }
  else if (thirdPoint_.x == center.x && thirdPoint_.y == center.y)
  {
    secondPoint_.x = center.x - (center.x - secondPoint_.x) * ratio;
    secondPoint_.y = center.y - (center.y - secondPoint_.y) * ratio;
    firstPoint_.x = center.x - (center.x - firstPoint_.x) * ratio;
    firstPoint_.y = center.y - (center.y - firstPoint_.y) * ratio;
  }
}
