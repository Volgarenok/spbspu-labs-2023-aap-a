#include "operations.hpp"
#include "ioOperations.hpp"
#include <stdexcept>

void shabalin::isoScale(Shape *shapeObject, point_t pos, double ratio)
{
  point_t initialPosition = shapeObject->getFrameRect().position;
  shapeObject->move(pos);
  point_t newPosition = shapeObject->getFrameRect().position;
  //shape->scale(ratio);
  //shape->move(ratio *(initialPosition.x - newPosition.x), ratio * (initialPosition.y - newPosition.y));
  double px = (newPosition.x - initialPosition.x) * ratio;
  double py = (newPosition.y - initialPosition.y) * ratio;
  shapeObject->scale(ratio);
  shapeObject->move(-px, -py);
}

double shabalin::getDistance(point_t start, point_t finish)
{
  double px = start.x - finish.x;
  double py = start.y - finish.y;
  return std::sqrt(px * px + py * py);
}

double *shabalin::getSides(double *result, point_t *point, size_t numberOfSide)
{
  for (size_t i = 0; i < numberOfSide; ++i)
  {
    result[i] = getDistance(point[i], point[(i + 1) % numberOfSide]);
  }
  return result;
}
