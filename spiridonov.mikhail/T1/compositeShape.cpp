#include "compositeShape.hpp"
#include <algorithm>
#include <stdexcept>

namespace spiridonov
{
  CompositeShape::CompositeShape() :
    shapes(0),
    capacity(0),
    shapeptrs(nullptr)
  {}

  CompositeShape::CompositeShape(const CompositeShape& other) :
    shapes(other.shapes),
    capacity(other.capacity),
    shapeptrs(new Shape* [other.capacity])
  {
    std::copy(other.shapeptrs, other.shapeptrs + other.shapes, shapeptrs);
  }

  CompositeShape::CompositeShape(CompositeShape&& other) noexcept :
    shapes(other.shapes),
    capacity(other.capacity),
    shapeptrs(other.shapeptrs)
  {
    other.shapes = 0;
    other.capacity = 0;
    other.shapeptrs = nullptr;
  }

  CompositeShape::~CompositeShape()
  {
    delete[] shapeptrs;
    shapes = 0;
    capacity = 0;
  }

  CompositeShape& CompositeShape::operator=(const CompositeShape& other)
  {
    if (this != &other)
    {
      shapes = other.shapes;
      capacity = other.capacity;
      delete[] shapeptrs;
      shapeptrs = new Shape * [other.capacity];
      std::copy(other.shapeptrs, other.shapeptrs + other.shapes, shapeptrs);
    }
    return *this;
  }

  CompositeShape& CompositeShape::operator=(CompositeShape&& other) noexcept
  {
    if (this != &other)
    {
      shapes = other.shapes;
      capacity = other.capacity;
      delete[] shapeptrs;
      shapeptrs = other.shapeptrs;
      other.shapes = 0;
      other.capacity = 0;
      other.shapeptrs = nullptr;
    }
    return *this;
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
    double area = 0.0;
    for (size_t i = 0; i < shapes; ++i)
    {
      area += shapeptrs[i].getArea();
    }
    return area;
  }

  rectangle_t CompositeShape::getFrameRect() const
  {
    if (shapes == 0)
    {
      throw std::logic_error("Error: empty CompositeShape");
    }

    rectangle_t frameRect = shapeptrs[0]->getFrameRect();
    for (size_t i = 1; i < shapes; ++i)
    {
      rectangle_t currentFrameRect = shapeptrs[i]->getFrameRect();
      frameRect = getFrameRect(frameRect, currentFrameRect);
    }
    return frameRect;
  }

  void CompositeShape::move(point_t pos)
  {
    point_t currentPos = getFrameRect().pos;
    move(pos.x - currentPos.x, pos.y - currentPos.y);
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
}
