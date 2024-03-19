#include "isoScale.hpp"
#include <stdexcept>
#include "square.hpp"
#include "base-types.hpp"

void agarkov::isoScale(agarkov::Shape* shape, agarkov::point_t point, double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Incorrect scale coefficient");
  }
  double x = shape->getFrameRect().pos.x;
  double y = shape->getFrameRect().pos.y;
  double dx = point.x - x;
  double dy = point.y - y;
  shape->move(dx, dy);
  dx = -dx * k;
  dy = -dy * k;
  shape->scale(k);
  shape->move(dx, dy);
}
