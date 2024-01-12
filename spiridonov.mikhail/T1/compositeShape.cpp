#include "compositeShape.hpp"
#include <algorithm>
#include <stdexcept>

namespace spiridonov
{
  CompositeShape::CompositeShape() : shapePtrs(nullptr), shapes(0) {}

  CompositeShape::~CompositeShape()
  {
    for (size_t i = 0; i < shapes; ++i)
    {
      delete shapePtrs[i];
    }
    delete[] shapePtrs;
    shapePtrs = nullptr;
  }

  void CompositeShape::addShape(Shape* shape)
  {
    Shape** newShapes = new Shape * [shapes + 1];
    std::copy(shapePtrs, shapePtrs + shapes, newShapes);
    newShapes[shapes] = shape;

    delete[] shapePtrs;
    shapePtrs = newShapes;

    ++shapes;
  }

  void CompositeShape::removeShape(size_t index)
  {
    if (index >= shapes)
    {
      throw std::out_of_range("Error: index out of range");
    }

    delete shapePtrs[index];
    std::copy(shapePtrs + index + 1, shapePtrs + shapes, shapePtrs + index);

    --shapes;
  }

  double CompositeShape::getArea()
  {
    double area = 0.0;
    for (size_t i = 0; i < shapes; ++i)
    {
      area += shapePtrs[i]->getArea();
    }
    return area;
  }

  rectangle_t CompositeShape::getFrameRect()
  {
    if (shapes == 0)
    {
      throw std::logic_error("Error: CompositeShape is empty");
    }

    rectangle_t frameRect = shapePtrs[0]->getFrameRect();
    for (size_t i = 1; i < shapes; ++i)
    {
      rectangle_t currentFrameRect = shapePtrs[i]->getFrameRect();
      double left = std::min(frameRect.pos.x - frameRect.width / 2, currentFrameRect.pos.x - currentFrameRect.width / 2);
      double right = std::max(frameRect.pos.x + frameRect.width / 2, currentFrameRect.pos.x + currentFrameRect.width / 2);
      double top = std::max(frameRect.pos.y + frameRect.height / 2, currentFrameRect.pos.y + currentFrameRect.height / 2);
      double bottom = std::min(frameRect.pos.y - frameRect.height / 2, currentFrameRect.pos.y - currentFrameRect.height / 2);

      frameRect.width = right - left;
      frameRect.height = top - bottom;
      frameRect.pos.x = (left + right) / 2;
      frameRect.pos.y = (top + bottom) / 2;
    }

    return frameRect;
  }

  size_t CompositeShape::getShapesCount() const
  {
    return shapes;
  }

  void CompositeShape::move(point_t pos)
  {
    for (size_t i = 0; i < shapes; ++i)
    {
      shapePtrs[i]->move(pos);
    }
  }

  void CompositeShape::move(double x, double y)
  {
    for (size_t i = 0; i < shapes; ++i)
    {
      shapeptrs[i].move(x, y);
    }
  }

  void CompositeShape::scale(double coefficient)
  {
    if (coefficient <= 0)
    {
      throw std::invalid_argument("Error: invalid coefficient to scale");
    }

    point_t center = getFrameRect().pos;
    for (size_t i = 0; i < shapes; ++i)
    {
      shapeptrs[i].scale(coefficient);
      point_t newCenter = shapeptrs[i].getFrameRect().pos;
      shapeptrs[i].move((center.x - newCenter.x) * coefficient, (center.y - newCenter.y) * coefficient);
    }
  }

  void CompositeShape::clear()
  {
    for (size_t i = 0; i < shapes; ++i)
    {
      delete shapePtrs[i];
    }
    delete[] shapePtrs;
    shapePtrs = nullptr;
    shapes = 0;
  }
}
