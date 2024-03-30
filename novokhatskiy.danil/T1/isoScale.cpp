#include "isoScale.hpp"
#include <stdexcept>

void novokhatskiy::isoScale(Shape *shape, const point_t &point, double ratio)
{
  if (ratio <= 0.0)
  {
    throw std::invalid_argument("Ratio can't be negative or zero");
  }
  point_t oldCenter = shape->getFrameRect().pos;
  shape->move(point);
  point_t newCenter = shape->getFrameRect().pos;
  shape->scale(ratio);
  shape->move((oldCenter.x - newCenter.x) * ratio, (oldCenter.y - newCenter.y) * ratio);
}
