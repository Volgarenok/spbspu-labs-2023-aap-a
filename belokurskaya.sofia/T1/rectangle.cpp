#include "rectangle.hpp"

#include <stdexcept>

Rectangle::Rectangle(const point_t & pos, float width, float height):
pos_(pos), width_(width), height_(height)
{
  if (width <= 0 || height <= 0)
  {
    throw std::invalid_argument("Invalid rectangle dimensions");
  }
}

float Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {pos_, width_, height_};
}

void Rectangle::move(const point_t & new_pos)
{
  pos_ = new_pos;
}

void Rectangle::move(float dx, float dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Rectangle::scale(float factor)
{
  if (factor <= 0)
  {
    throw std::invalid_argument("Invalid scaling factor");
  }

  width_ *= factor;
  height_ *= factor;
}
