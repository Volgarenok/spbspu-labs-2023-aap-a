#include "outputShapesSource.hpp"

#include <cmath>

#include "base-types.hpp"

std::ostream &zhalilov::outputShapesSource(const Shape * const *shapes, size_t size, std::ostream &output)
{
  double square = 0.0;
  for (size_t i = 0; i < size; i++)
  {
    square += shapes[i]->getArea();
  }

  output << std::fixed;
  output.precision(1);
  output << square;
  for (size_t i = 0; i < size; i++)
  {
    double width = shapes[i]->getFrameRect().width;
    double height = shapes[i]->getFrameRect().height;
    double posX = shapes[i]->getFrameRect().pos.x;
    double posY = shapes[i]->getFrameRect().pos.y;
    point_t leftCorner = { posX - width / 2.0, posY - height / 2.0 };
    point_t rightCorner = { posX + width / 2.0, posY + height / 2.0 };
    output << " " << leftCorner.x << " " << leftCorner.y;
    output << " " << rightCorner.x << " " << rightCorner.y;
  }
  return output;
}
