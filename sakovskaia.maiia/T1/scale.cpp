#include "scale.hpp"
void sakovskaia::scaleShapes(Shape * shape, point_t scalePoint, double scaleRatio)
{
  rectangle_t frameRect = shape->getFrameRect();
  point_t startPoint = frameRect.pos;
  shape->move(scalePoint);
  shape->scale(scaleRatio);
  shape->move((startPoint.x - scalePoint.x) * scaleRatio, (startPoint.y - scalePoint.y) * scaleRatio);
}
