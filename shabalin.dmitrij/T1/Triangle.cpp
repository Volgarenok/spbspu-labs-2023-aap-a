#include "Triangle.hpp"
#include "shape.hpp"

shabalin::Triangle::Triangle(point_t &p1, point_t &p2, point_t &p3):
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
  return std::sqrt(perimetr * (perimetr - a) * (perimetr - b) * (perimetr - c));
}


shabalin::rectangle_t shabalin::Triangle::getFrameRect() const
{
  double width = (std::max(p1_.x, std::max(p2_.x, p3_.x)) - std::min(p1_.x, std::min(p2_.x, p3_.x)));
  double height = (std::max(p1_.y, std::max(p2_.y, p3_.y)) - std::min(p1_.y, std::min(p2_.y, p3_.y)));
}
 

void shabalin::Triangle::move(double del_x, double del_y)
{
  point_t *points[] = { &p1_, &p2_, &p3_};
  for (size_t i = 0; i < 3; ++i)
  {
    points[i]->x += del_x;
    points[i]->y += del_y;
  }
}

void shabalin::Triangle::move(const point_t point)
{
  double midX = (p1_.x + p2_.x + p3_.x) / 3;
  double midY = (p1_.y + p2_.y + p3_.y) / 3;
  point_t center = { midX + midY };
  double dx = point.x - center.x;
  double dy = point.y - center.y;
  this->move(dx, dy);
}

void shabalin::Triangle::unsafeScale(const double ratio)
{
  point_t *points[] = { &p1_, &p2_, &p3_};
  double midX = (p1_.x + p2_.x + p3_.x) / 3;
  double midY = (p1_.y + p2_.y + p3_.y) / 3;
  point_t center = { midX + midY };
  for (size_t i = 0; i < 3; ++i)
  {
    points[i]->x = center.x + (points[i]->x - center.x) * ratio;
    points[i]->y = center.y + (points[i]->y - center.y) * ratio;
  }
}

