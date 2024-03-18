#include "rectangle.hpp"

ishmuratov::Rectangle::Rectangle(const point_t & point1, const point_t & point2):
  tri1_(Triangle(point1, { point1.x, point2.y }, point2)),
  tri2_(Triangle(point1, { point2.x, point1.y }, point2))
{
  if ((point1.x >= point2.x) || (point1.y >= point2.y))
  {
    throw std::invalid_argument("Incorrect rectangle corners coordinates!");
  }
}

ishmuratov::Rectangle::~Rectangle() = default;

double ishmuratov::Rectangle::getArea() const
{
  return tri1_.getArea() + tri2_.getArea();
}

ishmuratov::rectangle_t ishmuratov::Rectangle::getFrameRect() const
{
  return tri1_.getFrameRect();
}

void ishmuratov::Rectangle::move(point_t position)
{
  tri1_.move(position);
  tri2_.move(position);
}

void ishmuratov::Rectangle::move(double dx, double dy)
{
  tri1_.move(dx, dy);
  tri2_.move(dx, dy);
}

void ishmuratov::Rectangle::scale(double factor)
{
  if (factor <= 0)
  {
    throw std::runtime_error("Invalid factor!");
  }
  tri1_.scale(factor);
  tri2_.scale(factor);
}
