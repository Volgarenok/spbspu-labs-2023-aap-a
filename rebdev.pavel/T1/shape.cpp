#include "shape.hpp"

void rebdev::isoScale(Shape ** shapes, size_t numOfShape, const point_t & scalePoint, double k)
{
  for (size_t i = 0; i < numOfShape; ++i)
  {
    point_t centerPoint = shapes[i]->getFrameRect().pos;
    shapes[i]->move(scalePoint);
    point_t centerPoint2 = shapes[i]->getFrameRect().pos;
    shapes[i]->scale(k);
    shapes[i]->move((centerPoint.x - centerPoint2.x) * k, (centerPoint.y - centerPoint2.y) * k);
  }
}

void rebdev::deleteShapes(Shape ** shapes, size_t numOfShape)
{
  for (size_t i = 0; i < numOfShape; ++i)
  {
    delete shapes[i];
  }
}
