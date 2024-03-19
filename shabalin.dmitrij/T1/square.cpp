#include "square.hpp"
#include <stdexcept>
#include <algorithm>

namespace shabalin
{
  Square::Square(double left_bottom_x, double left_bottom_y, double side_length) :
  left_bottom_{left_bottom_x, left_bottom_y},
  side_length_(side_length)
  {
  }

  Square::Square(point_t center, double side_length) :
  left_bottom_{center.x - side_length / 2, center.y - side_length / 2},
  side_length_(side_length)
  {
  }

  void Square::move(point_t p)
  {
    double dx = p.x - (left_bottom_.x + side_length_ / 2);
    double dy = p.y - (left_bottom_.y + side_length_ / 2);
    left_bottom_.x += dx;
    left_bottom_.y += dy;
  }

  void Square::move(double shift_x, double shift_y)
  {
    left_bottom_.x += shift_x;
    left_bottom_.y += shift_y;
  }

  void Square::scale(double scale)
  {
    double center_x = left_bottom_.x + side_length_ / 2;
    double center_y = left_bottom_.y + side_length_ / 2;

    side_length_ *= scale;

    left_bottom_.x = center_x - side_length_ / 2;
    left_bottom_.y = center_y - side_length_ / 2;
  }

  double Square::getArea() const
  {
    return side_length_ * side_length_;
  }

  rectangle_t Square::getFrameRect() const
  {
    return {left_bottom_, side_length_, side_length_};
  }

  Shape *Square::clone() const
  {
    return new Square(left_bottom_.x, left_bottom_.y, side_length_);
  }
}
