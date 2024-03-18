#include "isoscale.hpp"

#include <iostream>

void lopatina::isoScale(Shape * shape, point_t center, double index)
{
  point_t pos1 = shape->getFrameRect().pos;
  shape->move(center);
  point_t pos2 = shape->getFrameRect().pos;
  shape->scale(index);
  shape->move(index * (pos1.x - pos2.x), index * (pos1.y - pos2.y));
}
