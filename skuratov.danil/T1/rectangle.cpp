#include "rectangle.hpp"

#include <stdexcept>

skuratov::Rectangle::Rectangle(const point_t& lowerLeftCorner, const point_t& upperRightCorner):
  lowerLeftCorner_(lowerLeftCorner),
  upperRightCorner_(upperRightCorner)
{
  if (lowerLeftCorner_.x >= upperRightCorner_.x || lowerLeftCorner_.y >= upperRightCorner_.x)
  {
    throw std::invalid_argument("Error: incorrect rectangle parametres");
  }
}

double skuratov::Rectangle::getArea() const
{
  return (upperRightCorner_.x - lowerLeftCorner_.x) * (upperRightCorner_.y - lowerLeftCorner_.y);
}

skuratov::rectangle_t skuratov::Rectangle::getFrameRect() const
{
  double width = upperRightCorner_.x - lowerLeftCorner_.x;
  double height = upperRightCorner_.y - lowerLeftCorner_.y;
  point_t pos = { lowerLeftCorner_.x + width / 2, lowerLeftCorner_.y + height / 2 };
  return { width, height, pos };
}

void skuratov::Rectangle::move(const point_t& A)
{
  rectangle_t B = getFrameRect();
  move(A.x - B.pos.x, A.y - B.pos.y);
}

void skuratov::Rectangle::move(double dx, double dy)
{
  lowerLeftCorner_.x += dx;
  upperRightCorner_.x += dx;
  lowerLeftCorner_.y += dy;
  upperRightCorner_.y += dy;
}

void skuratov::Rectangle::scale(double scalingFactor)
{
  if (scalingFactor <= 0)
  {
    throw std::invalid_argument("Error: scale factor of rectangle should be a positive");
  }

  rectangle_t B = getFrameRect();
  lowerLeftCorner_.x = { B.pos.x - (B.pos.x - lowerLeftCorner_.x) * scalingFactor };
  lowerLeftCorner_.y = { B.pos.y - (B.pos.y - lowerLeftCorner_.y) * scalingFactor };
  upperRightCorner_.x = { B.pos.x + (B.pos.x - lowerLeftCorner_.x) };
  upperRightCorner_.y = { B.pos.y + (B.pos.y - lowerLeftCorner_.y) };
}
