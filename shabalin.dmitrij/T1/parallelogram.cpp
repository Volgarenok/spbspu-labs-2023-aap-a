#include "parallelogram.hpp"
#include <stdexcept>
#include <cmath>
#include "base_type.hpp"
#include <algorithm>

shabalin::Parallelogram::Parallelogram(const point_t &p1, const point_t &p2, const point_t &p3):
  p1_(p1),
  p2_(p2),
  p3_(p3)
{
  if ((p1_.x != p2_.x || p1_.y != p2_.y) || (p1_.x != p3_.x || p1_.y != p3_.y) || (p2_.x != p3_.x || p2_.y != p3_.y))
  {
    throw std::invalid_argument("At least one of the sides must be parallel to the abscissa axis!");
  }
}
