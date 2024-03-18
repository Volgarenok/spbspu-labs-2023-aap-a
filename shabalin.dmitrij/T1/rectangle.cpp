#include "rectangle.hpp"

#include <stdexcept>

shabalin::Rectangle::Rectangle(point_t center, size_t width, size_t height) : center_(center), width_(width), height_(height)
{
}

shabalin::Rectangle::Rectangle(point_t bottom_left, point_t upper_right)
{
  if (bottom_left.x >= upper_right.x ||
      bottom_left.y >= upper_right.y)
  {
    throw std::invalid_argument("Can't create rectangle with next arguments");
  }
  width_ = upper_right.x - bottom_left.x;
  height_ = upper_right.y - bottom_left.y;
  center_.x = bottom_left.x + width_ / 2.0;
  center_.y = bottom_left.y + height_ / 2.0;
}

void shabalin::Rectangle::move(point_t p)
{
  center_ = p;
}

void shabalin::Rectangle::move(double shift_x, double shift_y)
{
  center_.x += shift_x;
  center_.y += shift_y;
}

void shabalin::Rectangle::scale(double scale)
{
  width_ *= scale;
  height_ *= scale;
}

shabalin::Shape *shabalin::Rectangle::clone() const
{
  return new Rectangle(center_, width_, height_);
}

double shabalin::Rectangle::getArea() const
{
  return width_ * height_;
}

rectange_t shabalin::Rectangle::getFrameRect() const
{
  return rectange_t{center_, width_, height_};
}
