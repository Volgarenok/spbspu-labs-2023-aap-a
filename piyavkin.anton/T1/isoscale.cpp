#include "isoscale.hpp"
#include <stdexcept>

void piyavkin::isoScale(Shape* shape, const point_t& center, const double k)
{
  if (k < 0)
  {
    throw std::invalid_argument("Сoefficient less than 0");
  }
  point_t pos = shape->getFrameRect().pos;
  shape->move(center);
  point_t newPos = shape->getFrameRect().pos;
  shape->scale(k);
  shape->move(k * (pos.x - newPos.x), k * (pos.y - newPos.y));
}

