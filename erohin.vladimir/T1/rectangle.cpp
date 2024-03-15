#include "rectangle.hpp"
#include <stdexcept>
#include "base-types.hpp"
#include "geom_func.hpp"

erohin::Rectangle::Rectangle(point_t left_lower_corner, point_t right_upper_corner):
  frameRect_{ findRectangleFrameRect(left_lower_corner, right_upper_corner) }
{
  if (left_lower_corner.x >= right_upper_corner.x || left_lower_corner.y >= right_upper_corner.y)
  {
    throw std::invalid_argument("Wrong figure creation");
  }
}

erohin::Rectangle::~Rectangle() = default;

double erohin::Rectangle::getArea() const
{
  return (frameRect_.width * frameRect_.height);
}

erohin::rectangle_t erohin::Rectangle::getFrameRect() const
{
  return frameRect_;
}

void erohin::Rectangle::move(double dx, double dy)
{
  frameRect_.pos.x += dx;
  frameRect_.pos.y += dy;
}

void erohin::Rectangle::move(point_t point)
{
  frameRect_.pos = point;
}

void erohin::Rectangle::unsafeScale(double ratio)
{
  frameRect_.width *= ratio;
  frameRect_.height *= ratio;
}

erohin::Shape* erohin::Rectangle::clone() const
{
  rectangle_t framRect = getFrameRect();
  point_t left_lower_corner = {framRect.pos.x - framRect.width / 2.0, framRect.pos.y - framRect.height / 2.0};
  point_t right_upper_corner = {framRect.pos.x + framRect.width / 2.0, framRect.pos.y + framRect.height / 2.0};
  Shape* shape = new Rectangle(left_lower_corner, right_upper_corner);
  return shape;
}
