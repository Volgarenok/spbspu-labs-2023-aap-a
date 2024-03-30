#include "square.hpp"
#include <stdexcept>
#include "geometryFunc.hpp"

zakozhurnikova::Square::Square(const point_t& downLeft, double length):
  downLeft_(downLeft),
  length_(length)
{
  if (length <= 0.0)
  {
    throw std::invalid_argument("Invalid square parameters");
  }
}

double zakozhurnikova::Square::getArea() const
{
  return length_ * length_;
}

zakozhurnikova::rectangle_t zakozhurnikova::Square::getFrameRect() const
{
  point_t pos = {downLeft_.x + (length_ / 2.0), downLeft_.y + (length_ / 2.0)};
  return rectangle_t{length_, length_, pos};
}

void zakozhurnikova::Square::move(double dx, double dy)
{
  point_t shift = {dx, dy};
  downLeft_ += shift;
}

void zakozhurnikova::Square::move(const point_t& p)
{
  point_t pos = {downLeft_.x + (length_ / 2.0), downLeft_.y + (length_ / 2.0)};
  double shiftX = p.x - pos.x;
  double shiftY = p.y - pos.y;
  move(shiftX,  shiftY);
}


void zakozhurnikova::Square::unsafeScale(double k)
{
  point_t center = {downLeft_.x + (length_ / 2.0), downLeft_.y + (length_ / 2.0)};
  downLeft_ = center - (center - downLeft_) * k;
  length_ *= k;
}
