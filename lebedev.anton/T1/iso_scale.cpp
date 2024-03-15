#include "iso_scale.hpp"
#include <stdexcept>

void lebedev::isoScale(Shape * shape, const point_t & point, double ratio)
{
  if (ratio <= 0.0)
  {
    throw std::invalid_argument("Scaling ratio must be greater than zero");
  }
  point_t old_center = shape->getFrameRect().pos;
  shape->move(point);
  shape->scale(ratio);
  point_t new_center = shape->getFrameRect().pos;
  double dx = (old_center.x - new_center.x) * ratio;
  double dy = (old_center.y - new_center.y) * ratio;
  shape->move(dx, dy);
}
