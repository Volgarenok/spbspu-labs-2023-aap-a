#include "scale.hpp"

void marishin::scale(Shape* shape, point_t& center, double scaleCoefficient)
{
  if (scaleCoefficient < 0)
  {
    throw std::invalid_argument("Invalid scale coefficient. Must be non-negative.");
  }

  point_t initialPosition = shape->getFrameRect().pos;
  shape->move(center);
  shape->scale(scaleCoefficient);
  shape->move(scaleCoefficient * (initialPosition.x - shape->getFrameRect().pos.x),
  scaleCoefficient * (initialPosition.y - shape->getFrameRect().pos.y));
}
