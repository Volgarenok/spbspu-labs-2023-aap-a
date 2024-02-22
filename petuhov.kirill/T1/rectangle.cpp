#include "rectangle.hpp"
#include <stdexcept>

petuhov::Rectangle::Rectangle(const petuhov::point_t & pos, double width, double height): rect_({pos, width, height})
{
  if (width < 0.0)
  {
    throw std::invalid_argument("Width must be non-negative");
  }
  if (height < 0.0)
  {
    throw std::invalid_argument("Height must be non-negative");
  }
}

double petuhov::Rectangle::getArea() const
{
  return rect_.width * rect_.height;
}

petuhov::rectangle_t petuhov::Rectangle::getFrameRect() const
{
  return rect_;
}

void petuhov::Rectangle::move(const point_t & pos)
{
  rect_.pos = pos;
}

void petuhov::Rectangle::scale(double factor)
{
  rect_.width *= factor;
  rect_.height *= factor;
}