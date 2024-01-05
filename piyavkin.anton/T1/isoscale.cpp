#include "isoscale.hpp"
#include <iostream>

namespace piyavkin
{
  void isoScale(Shape* shape, point_t center, double k)
  {
    if (k < 0)
    {
      throw std::invalid_argument("Сoefficient less than 0");
    }
    point_t pos = shape->getFrameRect().pos;
    shape->move(center);
    shape->scale(k);
    shape->move(k * (pos.x - shape->getFrameRect().pos.x), k * (pos.y - shape->getFrameRect().pos.y));
  }
}
