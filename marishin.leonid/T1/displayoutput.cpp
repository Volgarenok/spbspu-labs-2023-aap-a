#include "displayoutput.hpp"

void marishin::outputShapesInfo(std::ostream& out, size_t shapeCount, Shape** shapes)
{
  double totalArea = 0;

  for (size_t i = 0; i < shapeCount; ++i)
  {
    totalArea += shapes[i]->getArea();
  }

  out << "Total Area: " << totalArea << " ";

  for (size_t i = 0; i < shapeCount; ++i)
  {
    const auto& frameRect = shapes[i]->getFrameRect();
    double width = frameRect.width;
    double height = frameRect.height;
    point_t point = frameRect.pos;

    point_t lowerLeftCorner = { point.x - width / 2.0, point.y - height / 2.0 };
    point_t topRightCorner = { point.x + width / 2.0, point.y + height / 2.0 };

    out << std::fixed << std::setprecision(1) << std::round(10 * lowerLeftCorner.x) / 10 << " "
        << std::round(10 * lowerLeftCorner.y) / 10 << " " << std::round(10 * topRightCorner.x) / 10 << " "
        << std::round(10 * topRightCorner.y) / 10;
  }


  out << "\n";

}
