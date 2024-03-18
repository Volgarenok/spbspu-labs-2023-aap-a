#include "square.hpp"

#include <stdexcept>

skuratov::Square::Square(const point_t& bottomLeftCorner, double sideLength):
  bottomLeftCorner_(bottomLeftCorner),
  sideLength_(sideLength)
{
  if (sideLength <= 0)
  {
    throw std::invalid_argument("Error: incorrect square parameters");
  }
}

double skuratov::Square::getArea() const
{
  return sideLength_ * sideLength_;
}

skuratov::rectangle_t skuratov::Square::getFrameRect() const
{
  point_t core = { bottomLeftCorner_.x + (sideLength_ / 2), bottomLeftCorner_.y + (sideLength_ / 2) };
  return { sideLength_, sideLength_, core };
}

void skuratov::Square::move(const point_t& A)
{
  rectangle_t B = getFrameRect();
  move(A.x - B.pos.x, A.y - B.pos.y);
}

void skuratov::Square::move(double dx, double dy)
{
  bottomLeftCorner_.x += dx;
  bottomLeftCorner_.y += dy;
}

void skuratov::Square::scale(double scalingFactor)
{
  if (scalingFactor <= 0)
  {
    throw std::invalid_argument("Error: scale factor of square should be a positive");
  }

  point_t core = getFrameRect().pos;
  sideLength_ *= scalingFactor;
  bottomLeftCorner_.x = core.x - (sideLength_ / 2);
  bottomLeftCorner_.y = core.y - (sideLength_ / 2);
}
