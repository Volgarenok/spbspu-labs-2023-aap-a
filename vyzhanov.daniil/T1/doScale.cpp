#include "doScale.hpp"

void vyzhanov::doScale(Shape& shape, const point_t& point, const double ratio)
{
  point_t center = shape.getFrameRect().pos;
  shape.move(point);
  shape.scale(ratio);
  double dx = (point.x - center.x) * ratio;
  double dy = (point.y - center.y) * ratio;
  shape.move(-dx, -dy);
}
