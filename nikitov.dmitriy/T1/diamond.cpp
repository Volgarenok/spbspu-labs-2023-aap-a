#include "diamond.hpp"
#include <cmath>
#include <stdexcept>

nikitov::point_t identifyFirst(const nikitov::point_t& first, const nikitov::point_t& second, const nikitov::point_t& third)
{
  if (first.x - second.x == 0)
  {
    if (first.y - third.y == 0)
    {
      return first;
    }
    else
    {
      return second;
    }
  }
  else if (first.x - third.x == 0)
  {
    if (first.y - second.y == 0)
    {
      return first;
    }
    else
    {
      return third;
    }
  }
  else
  {
    if (second.y - first.y == 0)
    {
      return second;
    }
    else
    {
      return third;
    }
  }
}

nikitov::point_t identifySecond(const nikitov::point_t& first, const nikitov::point_t& second, const nikitov::point_t& third)
{
  if (first.y - second.y == 0)
  {
    return third;
  }
  else if (first.y - third.y == 0)
  {
    return second;
  }
  else
  {
    return first;
  }
}

nikitov::point_t identifyThird(const nikitov::point_t& first, const nikitov::point_t& second, const nikitov::point_t& third)
{
  if (first.x - second.x == 0)
  {
    return third;
  }
  else if (first.x - third.x == 0)
  {
    return second;
  }
  else
  {
    return first;
  }
}

nikitov::Diamond::Diamond(const point_t& first, const point_t& second, const point_t& third):
  first_(identifyFirst(first, second, third)),
  second_(identifySecond(first, second, third)),
  third_(identifyThird(first, second, third))
{
  size_t status = (first_.x - second_.x == 0 || first_.y - second_.y == 0);
  status += (first_.x - third_.x == 0 || first_.y - third_.y == 0);
  status += (second_.x - third_.x == 0 || second_.y - third_.y == 0);
  if (status < 2)
  {
    throw std::invalid_argument("Error: invalid diamond arguments");
  }
}

double nikitov::Diamond::getArea() const
{
  rectangle_t frame = getFrameRect();
  return frame.width * frame.height / 2.0;
}

nikitov::rectangle_t nikitov::Diamond::getFrameRect() const
{
  double width = std::abs(first_.x - third_.x) * 2.0;
  double height = std::abs(first_.y - second_.y) * 2.0;
  return { width, height, first_ };
}

void nikitov::Diamond::move(const point_t& point)
{
  double dx = point.x - first_.x;
  double dy = point.y - first_.y;
  move(dx, dy);
}

void nikitov::Diamond::move(double dx, double dy)
{
  first_.x += dx;
  first_.y += dy;
  second_.x += dx;
  second_.y += dy;
  third_.x += dx;
  third_.y += dy;
}

void nikitov::Diamond::doScale(double ratio)
{
  second_.x = first_.x - (first_.x - second_.x) * ratio;
  second_.y = first_.y - (first_.y - second_.y) * ratio;
  third_.x = first_.x - (first_.x - third_.x) * ratio;
  third_.y = first_.y - (first_.y - third_.y) * ratio;
}

nikitov::Shape* nikitov::Diamond::clone() const
{
  return new Diamond(first_, second_, third_);
}
