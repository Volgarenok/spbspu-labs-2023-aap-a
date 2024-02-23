#include "outputShapes.hpp"
#include <iomanip>

void novokhatskiy::outputShapes(std::ostream &output, const Shape* const* shapes, size_t shapeCounter)
{
  if (shapeCounter == 0)
  {
    throw std::logic_error("No shapes");
  }
  double area = 0.0;
  for (size_t i = 0; i < shapeCounter; i++)
  {
    if (shapes[i])
    {
      area += shapes[i]->getArea();
    }
  }
  output << area;

  for (size_t i = 0; i < shapeCounter; ++i)
  {
    if (shapes[i])
    {
      double width = shapes[i]->getFrameRect().width;
      double height = shapes[i]->getFrameRect().height;
      point_t point = shapes[i]->getFrameRect().pos;
      point_t leftCorner = {point.x - width / 2.0, point.y - height / 2.0};
      point_t rightCorner = {point.x + width / 2.0, point.y + height / 2.0};
      output << " " << leftCorner.x << " " << leftCorner.y << " " << rightCorner.x << " " << rightCorner.y;
    }
  }
}
