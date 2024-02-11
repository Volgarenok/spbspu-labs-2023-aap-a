#include "rectangle.hpp"
#include <stdexcept>

namespace spiridonov
{

  double Rectangle::getArea() const
  {
    return frameRect_.height * frameRect_.width;
  }

  rectangle_t Rectangle::getFrameRect() const
  {
    return frameRect_;
  }

  void Rectangle::move(point_t pos)
  {
    frameRect_.pos = pos;
  }

  void Rectangle::move(double x, double y)
  {
    frameRect_.pos.x += x;
    frameRect_.pos.y += y;
  }

  void Rectangle::scale(double coefficient)
  {
    if (coefficient <= 0)
    {
      throw std::invalid_argument("Error: invalid coefficient to scale");
    }
    frameRect_.height *= coefficient;
    frameRect_.width *= coefficient;
  }

}
