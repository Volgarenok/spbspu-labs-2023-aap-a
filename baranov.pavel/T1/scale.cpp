#include "scale.hpp"

void baranov::scale(Shape * shape, const point_t scalePoint, const double scaleRatio)
{
  rectangle_t frameRect = shape->getFrameRect();
  point_t startPoint = frameRect.pos;
  shape->move(scalePoint);
  shape->scale(scaleRatio);
  shape->move((startPoint.x - scalePoint.x) * scaleRatio, (startPoint.y - scalePoint.y) * scaleRatio);
}

