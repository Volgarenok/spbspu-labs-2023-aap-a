#include "isoScale.hpp"
#include <stdexcept>

void grechishnikov::isoScale(Shape* shape, point_t scalePoint, double ratio)
{
  if (ratio <= 0)
  {
    throw std::logic_error("Incorrect scale ratio");
  }
  unsafeIsoScale(shape, scalePoint, ratio);
}

void grechishnikov::unsafeIsoScale(Shape* shape, point_t scalePoint, double ratio)
{
  point_t initPoint = shape->getFrameRect().pos;
  shape->move(scalePoint);
  point_t isoPoint = shape->getFrameRect().pos;
  shape->scale(ratio);
  shape->move((initPoint.x - isoPoint.x) * ratio, (initPoint.y - isoPoint.y) * ratio);
}
