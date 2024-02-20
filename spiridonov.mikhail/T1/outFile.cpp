#include "outFile.hpp"
#include "shape.hpp"
#include "compositeShape.hpp"

namespace spiridonov
{
  double globalCenterX = 0.0;
  double globalCenterY = 0.0;

  void setCenter(double centerX, double centerY)
  {
    globalCenterX = centerX;
    globalCenterY = centerY;
  }

  void outputShapes(std::ostream& out, const CompositeShape& shapes, bool useGlobalCenter)
  {
    out << shapes.getArea();

    for (size_t i = 0; i < shapes.getShapesCount(); ++i)
    {
      Shape* shape = shapes.getShape(i);
      rectangle_t frameRect = shape->getFrameRect();
      double offsetX = (!useGlobalCenter) ? 0.0 : globalCenterX;
      double offsetY = (!useGlobalCenter) ? 0.0 : globalCenterY;

      out << " ";
      out << (frameRect.pos.x - (frameRect.width / 2)) - offsetX << " ";
      out << (frameRect.pos.y - (frameRect.height / 2)) - offsetY << " ";
      out << (frameRect.pos.x + (frameRect.width / 2)) - offsetX << " ";
      out << (frameRect.pos.y + (frameRect.height / 2)) - offsetY;
    }
  }
}
