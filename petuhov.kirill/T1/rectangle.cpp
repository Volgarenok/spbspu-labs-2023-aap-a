#include "rectangle.hpp"
#include <stdexcept>

petuhov::Rectangle::Rectangle(point_t left_bottom_corner, point_t right_top_corner)
{
  if (left_bottom_corner.x >= right_top_corner.x || left_bottom_corner.y >= right_top_corner.y)
  {
    throw std::invalid_argument("Invalid rectangle");
  }

  rect_.pos.x = (left_bottom_corner.x + right_top_corner.x) / 2;
  rect_.pos.y = (left_bottom_corner.y + right_top_corner.y) / 2;
  rect_.width = right_top_corner.x - left_bottom_corner.x;
  rect_.height = right_top_corner.y - left_bottom_corner.y;
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