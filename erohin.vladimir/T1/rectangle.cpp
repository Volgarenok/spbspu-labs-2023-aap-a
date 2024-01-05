#include "rectangle.hpp"
#include "base-types.hpp"
#include <stdexcept>

erohin::Rectangle::Rectangle() :
  frameRect_{ 0.0, 0.0, {0.0, 0.0} }
{}

erohin::Rectangle::Rectangle(point_t left_corner, point_t right_corner)
{
  frameRect_ = { 0.0, 0.0, {0.0, 0.0} };
  if (left_corner.x < right_corner.x && left_corner.y < right_corner.y)
  {
    frameRect_.width = right_corner.x - left_corner.x;
    frameRect_.height = right_corner.y - left_corner.y;
    frameRect_.pos = { left_corner.x + frameRect_.width / 2, left_corner.y + frameRect_.height / 2 };
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

void erohin::Rectangle::scale(double ratio)
{
  if (ratio <= 0)
  {
    throw std::invalid_argument("Wrong scale ratio");
  }
  frameRect_.width *= ratio;
  frameRect_.height *= ratio;
}
