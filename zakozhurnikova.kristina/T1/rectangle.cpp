#include "rectangle.hpp"
#include <stdexcept>
#include "geometryFunc.hpp"

zakozhurnikova::Rectangle::Rectangle(const point_t& pointOne, const point_t& pointTwo):
  downLeft_(pointOne),
  upRight_(pointTwo)
{
  if (pointOne.x >= pointTwo.x || pointOne.y >= pointTwo.y)
  {
    throw std::invalid_argument("Invalid rectangle parameters");
  }
}

double zakozhurnikova::Rectangle::getArea() const
{
  double width = upRight_.x - downLeft_.x;
  double height = upRight_.y - downLeft_.y;
  return width * height;
}

zakozhurnikova::rectangle_t zakozhurnikova::Rectangle::getFrameRect() const
{
  double width = upRight_.x - downLeft_.x;
  double height = upRight_.y - downLeft_.y;
  point_t pos = {(upRight_ + downLeft_) / 2.0};
  return rectangle_t{width, height, pos};
}

void zakozhurnikova::Rectangle::move(const point_t& p)
{
  point_t center = {(downLeft_ + upRight_)  / 2.0};
  double shiftX = p.x - center.x;
  double shiftY = p.y - center.y;
  move(shiftX, shiftY);
}

void zakozhurnikova::Rectangle::move(double dx, double dy)
{
  point_t shift = {dx, dy};
  downLeft_ += shift;
  upRight_ += shift;
}

void zakozhurnikova::Rectangle::unsafeScale(double k)
{
  point_t pos{(downLeft_ + upRight_) / 2.0};
  downLeft_ = scaleShift(k, downLeft_, pos);
  upRight_ = scaleShift(k, upRight_, pos);
}
