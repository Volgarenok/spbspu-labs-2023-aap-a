#include "iso_scale.hpp"
#include <stdexcept>

void belokurskaya::isoScale(Shape * shapes, const point_t & pos, double ratio)
{
  if (ratio <= 0.0)
  {
    throw std::invalid_argument("Invalid scaling factor");
  }
  point_t init_pos = shapes->getFrameRect().pos;
  shapes->move(pos);
  point_t new_pos = shapes->getFrameRect().pos;
  shapes->scale(ratio);
  shapes->move(ratio * (init_pos.x - new_pos.x), ratio * (init_pos.y - new_pos.y));
}
