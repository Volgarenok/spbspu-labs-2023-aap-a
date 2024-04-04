#include "isoScale.hpp"
#include <stdexcept>

void stepanov::isoScale(Shape** figures, point_t& p, double ratio, size_t size_shapes)
{
  point_t * points = new point_t[size_shapes]{};
  for (size_t i = 0; i < size_shapes; ++i)
  {
    points[i] = figures[i]->getFrameRect().pos;
  }
  for (size_t i = 0; i < size_shapes; ++i)
  {
    figures[i]->move(p);
  }
  for (size_t i = 0; i < size_shapes; ++i)
  {
    figures[i]->unsafeScale(ratio);
  }
  for (size_t i = 0; i < size_shapes; ++i)
  {
    double dx = (points[i].x - figures[i]->getFrameRect().pos.x) * ratio;
    double dy = (points[i].y - figures[i]->getFrameRect().pos.y) * ratio;
    figures[i]->move(dx,dy);
  }
  delete[] points;
}
