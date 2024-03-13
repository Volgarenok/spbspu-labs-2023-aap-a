#include "isoScale.hpp"

#include <stdexcept>

void skuratov::isoScale(Shape* shape, const point_t& p, const double scalingFactor)
{
  if (scalingFactor <= 0)
  {
    throw std::invalid_argument("Scaling factor should be a positive");
  }

  point_t basCenter = shape->getFrameRect().pos;
  shape->move(p);
  shape->scale(scalingFactor);
  double dx = (p.x - basCenter.x) * scalingFactor;
  double dy = (p.y - basCenter.y) * scalingFactor;
  shape->move(-dx, -dy);
}
