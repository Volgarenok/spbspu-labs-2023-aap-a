#include "outputShapes.hpp"

double baranov::getSumArea(const Shape * const * shapes, const size_t count)
{
  double result = 0;
  for (size_t i = 0; i < count; ++i)
  {
    result += shapes[i]->getArea();
  }
  return result;
}

void baranov::outputShapes(std::ostream & output, const Shape * const * shapes, const size_t count)
{
  output << getSumArea(shapes, count);
  for (size_t i = 0; i < count; ++i)
  {
    rectangle_t frameRect = shapes[i]->getFrameRect();
    point_t pos = frameRect.pos;
    double width = frameRect.width;
    double height = frameRect.height;
    output << ' ' << pos.x - width / 2 << ' ' << pos.y - height / 2;
    output << ' ' << pos.x + width / 2 << ' ' << pos.y + height / 2;
  }
}

