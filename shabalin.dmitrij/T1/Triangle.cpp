#include "Triangle.hpp"
#include "shape.hpp"

shabalin::Triangle::Triangle(point_t p1, point_t p2, point_t p3):
  p1_(p1),
  p2_(p2),
  p3_(p3)
{
  double det = p1_.x * (p2_.y - p3_.y) - p2_.x * (p1_.y - p3_.y) + p3_.x * (p1_.y - p2_.y);
  if (det == 0)
  {
    throw std::invalid_argument("Infinitely many solutions");
  }
}

double shabalin::Triangle::getLength(point_t p1, point_t p2) const
{
  return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

double shabalin::Triangle::getArea() const
{
  double a = Triangle::getLength(p1_, p2_);
  double b = Triangle::getLength(p2_, p3_);
  double c = Triangle::getLength(p3_, p1_);
  double perimetr = (a + b + c) / 2.0;
  return std::sqrt(perimetr * (perimetr - a) * (perimetr - b) * (perimetr - c))
}
