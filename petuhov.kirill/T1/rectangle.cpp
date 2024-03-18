#include "rectangle.hpp"
#include <stdexcept>

petuhov::Rectangle::Rectangle(const point_t &pos, float width, float height) : rect_{{0,0}, 0, 0}
{
  if (width > 0.0f && height > 0.0f)
  {
    rect_.pos = pos;
    rect_.width = width;
    rect_.height = height;
  }
  else
  {
    throw std::invalid_argument("Width and height must be positive");
  }
}

float petuhov::Rectangle::getArea() const
{
  return rect_.width * rect_.height;
}

petuhov::rectangle_t petuhov::Rectangle::getFrameRect() const
{
  return rect_;
}

void petuhov::Rectangle::move(const petuhov::point_t &pos)
{
  rect_.pos = pos;
}

void petuhov::Rectangle::move(float dx, float dy)
{
  rect_.pos.x += dx;
  rect_.pos.y += dy;
}

void petuhov::Rectangle::scale(const petuhov::point_t &center, float factor)
{
  if (factor > 0.0f)
  {
    rect_.pos.x = center.x + (rect_.pos.x - center.x) * factor;
    rect_.pos.y = center.y + (rect_.pos.y - center.y) * factor;
    rect_.width *= factor;
    rect_.height *= factor;
  }
  else
  {
    throw std::invalid_argument("Factor must be positive");
  }
}
