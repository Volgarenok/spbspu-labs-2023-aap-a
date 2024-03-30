#include "rectangle.hpp"
#include <stdexcept>
#include "base-types.hpp"

agarkov::Rectangle::Rectangle(agarkov::point_t left_bottom, agarkov::point_t right_top):
  left_bottom_(left_bottom),
  right_top_(right_top)
{
  if (!isCorrectRectangle())
  {
    throw std::invalid_argument("Incorrect rectangle argument");
  }
}

double agarkov::Rectangle::getArea() const
{
  return getFrameRect().height * getFrameRect().width;
}

agarkov::rectangle_t agarkov::Rectangle::getFrameRect() const
{
  point_t centre_frame_rect = getLineCenter(left_bottom_, right_top_);
  double height_frame_rect = right_top_.y - left_bottom_.y;
  double width_frame_rect = right_top_.x - left_bottom_.x;
  return {centre_frame_rect, width_frame_rect, height_frame_rect};
}

void agarkov::Rectangle::move(double dx, double dy)
{
  left_bottom_.move(dx, dy);
  right_top_.move(dx, dy);
}

void agarkov::Rectangle::move(agarkov::point_t position)
{
  point_t centre = getLineCenter(left_bottom_, right_top_);
  double dx = position.x - centre.x;
  double dy = position.y - centre.y;
  move(dx, dy);
}

void agarkov::Rectangle::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Incorrect scale coefficient");
  }
  point_t center = getFrameRect().pos;
  left_bottom_.unsaveScale(center, k);
  right_top_.unsaveScale(center, k);
}

bool agarkov::Rectangle::isCorrectRectangle() const
{
  return ((left_bottom_.x < right_top_.x) && (left_bottom_.y < right_top_.y));
}
