#include "displayoutput.hpp"

void marishin::outputShapesInfo(std::ostream& out, const Shape* const* shapes, size_t& shapeCount)
{
  if (shapeCount == 0)
  {
    throw std::logic_error("no shapes");
  }

  double totalArea = 0.0;

  for (size_t i = 0; i < shapeCount; i++)
  {
    totalArea += shapes[i]->getArea();
  }

  out << totalArea;

  for (size_t i = 0; i < shapeCount; ++i)
  {
    double width = shapes[i]->getFrameRect().width;
    double height = shapes[i]->getFrameRect().height;
    point_t point = shapes[i]->getFrameRect().pos;

    point_t lowerLeftCorner = { point.x - width / 2.0, point.y - height / 2.0 };
    point_t topRightCorner = { point.x + width / 2.0, point.y + height / 2.0 };

    out << " " << lowerLeftCorner.x << " " << lowerLeftCorner.y << " " << topRightCorner.x << " " << topRightCorner.y;
  }

}
