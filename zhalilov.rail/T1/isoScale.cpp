#include "isoScale.hpp"

void zhalilov::isoScale(Shape *shape, const point_t &point, const double ratio)
{
  point_t basePos = shape->getFrameRect().pos;
  shape->move(point);
  shape->scale(ratio);
  double dx = (point.x - basePos.x) * ratio;
  double dy = (point.y - basePos.y) * ratio;
  shape->move(-dx, -dy);
}
