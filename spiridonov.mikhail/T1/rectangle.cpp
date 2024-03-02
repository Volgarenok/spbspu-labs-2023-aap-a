#include "rectangle.hpp"
#include <iostream>
#include <stdexcept>

spiridonov::Rectangle::Rectangle(double left, double bottom, double right, double top) :
  left_(left), bottom_(bottom), right_(right), top_(top)
{
  if (left >= right || bottom >= top)
  {
    throw std::invalid_argument("Invalid rectangle coordinates");
  }
}

double spiridonov::Rectangle::getArea() const
{
  return (right_ - left_) * (top_ - bottom_);
}

spiridonov::rectangle_t spiridonov::Rectangle::getFrameRect() const
{
  double width = right_ - left_;
  double height = top_ - bottom_;
  point_t pos = { left_ + width / 2, bottom_ + height / 2 };
  return { width, height, pos };
}

void spiridonov::Rectangle::move(point_t pos)
{
  double dx = pos.x - (left_ + right_) / 2;
  double dy = pos.y - (bottom_ + top_) / 2;
  left_ += dx;
  right_ += dx;
  top_ += dy;
  bottom_ += dy;
}

void spiridonov::Rectangle::move(double dx, double dy)
{
  left_ += dx;
  right_ += dx;
  top_ += dy;
  bottom_ += dy;
}

void spiridonov::Rectangle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    std::cerr << "Error: Invalid scale coefficient\n";
    return;
  }

  double centerX = (left_ + right_) / 2;
  double centerY = (bottom_ + top_) / 2;

  double newWidth = (right_ - left_) * coefficient;
  double newHeight = (top_ - bottom_) * coefficient;

  left_ = centerX - newWidth / 2;
  right_ = centerX + newWidth / 2;
  bottom_ = centerY - newHeight / 2;
  top_ = centerY + newHeight / 2;
}

spiridonov::Shape* spiridonov::Rectangle::clone() const
{
  return new Rectangle(*this);
}
