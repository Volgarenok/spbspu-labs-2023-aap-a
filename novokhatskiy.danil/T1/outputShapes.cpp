#include "outputShapes.hpp"
#include <cmath>

void novokhatskiy::outputShapes(std::ostream &output, size_t shapeCounter, Shape **shapes)
{
  double square = 0.0;
  for (size_t i = 0; i < shapeCounter; i++)
  {
    if (shapes[i])
    {
      square += shapes[i]->getArea();
    }
  }
  output << square << " ";
  for (size_t i = 0; i < shapeCounter; ++i)
  {
    if (shapes[i])
    {
      double width = shapes[i]->getFrameRect().width;
      double height = shapes[i]->getFrameRect().height;
      point_t point = shapes[i]->getFrameRect().pos;
      point_t leftCorner = {point.x - width / 2.0, point.y - height / 2.0};
      point_t rightCorner = {point.x + width / 2.0, point.y + height / 2.0};
      output << std::round(10 * leftCorner.x) / 10 << " " << std::round(10 * leftCorner.y) / 10 << " " << std::round(10 * rightCorner.x) / 10 << " " << std::round(10 * rightCorner.y) / 10;
    }
  }
  output << "\n";
}
