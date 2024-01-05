#include "outputShapes.hpp"

double baranov::getSumArea(Shape ** shapes, const size_t count)
{
  double result = 0;
  for (size_t i = 0; i < count; ++i)
  {
    result += shapes[i]->getArea();
  }
  return result;
}

void baranov::outputShapes(std::ostream & output, Shape ** shapes, const size_t count)
{
  output << std::fixed;
  output.precision(1);

  output << getSumArea(shapes, count) << ' ';
  for (size_t i = 0; i < count; ++i)
  {
    rectangle_t frameRect = shapes[i]->getFrameRect();
    point_t pos = frameRect.pos;
    size_t width = frameRect.width;
    size_t height = frameRect.height;
    output << pos.x - width / 2 << ' ' << pos.y - height / 2  << ' ';
    output << pos.x + width / 2 << ' ' << pos.y + height / 2;
    if (i != count - 1)
    {
      output << ' ';
    }
  }
  output << '\n';
}

