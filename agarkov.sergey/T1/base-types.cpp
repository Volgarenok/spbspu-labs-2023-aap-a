#include "base-types.hpp"

void agarkov::point_t::move(double dx, double dy)
{
  x += dx;
  y += dy;
}
void agarkov::point_t::unsaveScale(point_t center, double k)
{
  x = center.x + (x - center.x) * k;
  y = center.y + (y - center.y) * k;
}

agarkov::point_t agarkov::getLineCenter(agarkov::point_t point1, agarkov::point_t point2)
{
  double center_x = (point1.x + point2.x) / 2;
  double center_y = (point1.y+ point2.y) / 2;
  return {center_x, center_y};
}
