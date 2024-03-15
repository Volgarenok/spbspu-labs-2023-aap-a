#include "scale.hpp"

void marishin::isoScale(Shape *shape, const point_t& center, double coefficient)
{
  if (coefficient <= 0.0)
  {
    throw std::invalid_argument("Invalid scale coefficient. Must be non-negative.");
  }
  else
  {
    scale(shape, center, coefficient);
  }
}

void marishin::scale(Shape *shape, const point_t& center, double coefficient)
{
  point_t initialPosition = shape->getFrameRect().pos;
  shape->move(center);
  point_t newPosition = shape->getFrameRect().pos;
  shape->unsafeScale(coefficient);
  shape->move((initialPosition.x - newPosition.x) * coefficient, (initialPosition.y - newPosition.y) * coefficient);
}
