#include "compositeShape.hpp"
#include <algorithm>
#include <stdexcept>
#include "rectangle.hpp"


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

  double CompositeShape::getArea() const
  {
    double totalArea = 0.0;

    for (size_t i = 0; i < shapes; ++i)
    {
      double shapeArea = shapePtrs[i]->getArea();
      totalArea += shapeArea;
    }
    return totalArea;
  }
  rectangle_t CompositeShape::getFrameRect() const
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
      shapePtrs[i]->move(x, y);
    }
  }

  void CompositeShape::scale(double coefficient)
  {
    for (size_t i = 0; i < shapes; ++i)
    {
      shapePtrs[i]->scale(coefficient);
    }
  }
  Shape* CompositeShape::getShape(size_t index) const
  {
    if (index >= shapes)
    {
      throw std::out_of_range("Error: index out of range");
    }

    return shapePtrs[index];
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
