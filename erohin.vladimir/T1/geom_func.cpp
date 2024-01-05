#include "geom_func.hpp"
#include <stdexcept>
#include <cmath>

void erohin::isoScale(Shape& shape, point_t pos, double ratio)
{
  if (ratio <= 0)
  {
    throw std::invalid_argument("Wrong scale ratio");
  }
  rectangle_t init = shape.getFrameRect();
  shape.move(pos);
  shape.scale(ratio);
  shape.move(ratio * (pos.x - init.pos.x), ratio * (pos.y - init.pos.y));
}

double erohin::getDistance(point_t from, point_t to)
{
  double dx = from.x - to.x;
  double dy = from.y - to.y;
  return std::sqrt(dx * dx + dy * dy);
}
