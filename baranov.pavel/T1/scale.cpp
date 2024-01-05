#include "scale.hpp"
#include <iostream>

void baranov::scale(baranov::Shape * shape, const baranov::point_t scalePoint, const size_t scaleRatio)
{
  rectangle_t frameRect = shape->getFrameRect();
  point_t startPoint = frameRect.pos;
  shape->move(scalePoint);
  shape->scale(scaleRatio);
  shape->move((startPoint.x - scalePoint.x) * scaleRatio, (startPoint.y - scalePoint.y) * scaleRatio);
}
