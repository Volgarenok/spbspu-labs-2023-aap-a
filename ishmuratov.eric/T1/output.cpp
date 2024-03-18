#include "output.hpp"

void ishmuratov::outputShape(std::ostream & output, const Shape * const * shapes, size_t count)
{
  output << std::fixed << std::setprecision(1);
  double sumArea = 0;
  for (size_t i = 0; i < count; ++i)
  {
    sumArea += shapes[i]->getArea();
  }
  output << sumArea;
  for (size_t i = 0; i < count; ++i)
  {
    rectangle_t frameRect = shapes[i]->getFrameRect();
    point_t botLeft = { frameRect.pos.x - frameRect.width / 2, frameRect.pos.y - frameRect.height / 2 };
    point_t topRight = { frameRect.pos.x + frameRect.width / 2, frameRect.pos.y + frameRect.height / 2 };
    output << " " << botLeft.x << " " << botLeft.y << " " << topRight.x << " " << topRight.y;
  }
}
