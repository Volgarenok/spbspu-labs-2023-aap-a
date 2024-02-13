include "rectangle.hpp"
#include <stdexcept>
#include <iostream>

namespace spiridonov
{
  Rectangle::Rectangle() : left_(0.0), bottom_(0.0), right_(0.0), top_(0.0)
  {}

  Rectangle::Rectangle(double left, double bottom, double right, double top) :
    left_(left), bottom_(bottom), right_(right), top_(top)
  {
    if (left >= right || bottom >= top)
    {
      throw std::invalid_argument("Invalid rectangle coordinates");
    }
  }

  double Rectangle::getArea() const
  {
    return (right_ - left_) * (top_ - bottom_);
  }

  rectangle_t Rectangle::getFrameRect() const
  {
    return { (left_ + right_) / 2, (bottom_ + top_) / 2, right_ - left_, top_ - bottom_ };
  }

  void Rectangle::move(point_t pos)
  {
    double dx = pos.x - (left_ + right_) / 2;
    double dy = pos.y - (bottom_ + top_) / 2;
    left_ += dx;
    right_ += dx;
    top_ += dy;
    bottom_ += dy;
  }

  void Rectangle::move(double dx, double dy)
  {
    left_ += dx;
    right_ += dx;
    top_ += dy;
    bottom_ += dy;
  }

  void Rectangle::scale(double coefficient)
  {
    if (coefficient <= 0)
    {
      std::cerr << "Error: Invalid scale coefficient\n";
      return;
    }

    double newWidth = (right_ - left_) * coefficient;
    double newHeight = (top_ - bottom_) * coefficient;

    double centerX = (left_ + right_) / 2;
    double centerY = (top_ + bottom_) / 2;

    left_ = centerX - newWidth / 2;
    right_ = centerX + newWidth / 2;
    top_ = centerY + newHeight / 2;
    bottom_ = centerY - newHeight / 2;
  }
}
