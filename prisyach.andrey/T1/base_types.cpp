#include "base_types.h"

rectangle_t makeFrame(point_t point1, point_t point2)
{
  rectangle_t frame{point_t{(point1.x + point2.x) / 2, (point1.y + point2.y) / 2}, point2.x - point1.x, point2.y - point1.y};
  return frame;
}
