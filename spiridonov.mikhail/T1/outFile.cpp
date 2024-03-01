#include <iostream>
#include "outFile.hpp"
#include "compositeShape.hpp"
#include "shape.hpp"

namespace spiridonov
{
  double globalCenterX = 0.0;
  double globalCenterY = 0.0;

  void setCenter(double centerX, double centerY)
  {
    globalCenterX = centerX;
    globalCenterY = centerY;
  }
  void outputShapes(std::ostream& out, const CompositeShape& shapes, bool useGlobalCenter, const double scaleCoefficient)
  {
    out << shapes.getArea();

    size_t i = 0;
    do
    {
      Shape* shape = shapes.getShape(i);

      Shape* cloneShape = shape->clone();
      cloneShape->scale(scaleCoefficient);

      double centerX = cloneShape->getFrameRect().pos.x;
      double centerY = cloneShape->getFrameRect().pos.y;

      double offsetX = (useGlobalCenter) ? globalCenterX - centerX : 0.0;
      double offsetY = (useGlobalCenter) ? globalCenterY - centerY : 0.0;

      cloneShape->move(-offsetX, -offsetY);

      rectangle_t frameRect = cloneShape->getFrameRect();

      out << " ";
      out << frameRect.pos.x - frameRect.width / 2.0 << " ";
      out << frameRect.pos.y - frameRect.height / 2.0 << " ";
      out << frameRect.pos.x + frameRect.width / 2.0 << " ";
      out << frameRect.pos.y + frameRect.height / 2.0;

      delete cloneShape;

      if (i == 1)
      {
        break;
      }

      ++i;
    }
    while (i < shapes.getShapesCount());
  }
}
